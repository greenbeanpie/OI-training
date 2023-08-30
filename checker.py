# encoding=utf-8
import os,prettytable,time

result=prettytable.PrettyTable()
result.field_names=["Test Case","Result","Time"]

print("Python code checker for OI.\nDeveloped by HMZ_0915.\nThese features are developing in progress: check by subtasks, memory limit set(on linux platform),check code correctness\n\n")

work_dir = "D:\\OI-training\\"

print("目前支持自动查找文件目录的题目: Luogu, ZROI 10-day NOIP")

problem_name = input("请输入希望进行对拍的题目 ")
if problem_name[0] == "P":
	os.chdir(
		work_dir
		+ "Luogu\\"
		+ problem_name[0:2]
		+ "\\"
		+ problem_name[0:3]
		+ "\\"
		+ problem_name
		+ "\\"
	)
elif problem_name[0:2]=="ZR":
	if problem_name[0:8] == "ZR-NOIP-":
		if problem_name[8:10]=="10":
			os.chdir(work_dir+"ZROI\\NOIP10\\" + problem_name[8:10]+"\\"+problem_name[11:])
			problem_name = problem_name[11:]
		else:
			os.chdir(work_dir+"ZROI\\NOIP10\\" + problem_name[8:9]+"\\"+problem_name[10:])
			problem_name = problem_name[10:]
elif problem_name == "test":
	os.chdir(work_dir + "\\test\\")
else:
	relative_dir = input("请输入路径 ")
	try:
		os.chdir(work_dir+relative_dir)
	except:
		os.chdir(relative_dir);

cnt = int(input("请输入对拍次数   "))
generator_cpp = bool(int(input("请选择生成器语言: Python(0)/C++(1) ")))
if generator_cpp:
	os.system("g++ generator.cpp -Ofast -ogenerator")
spj = bool(int(input("是否需要使用SPJ(testlib.h)? 0: 否 1: 是 ")))
if spj:
	os.system("g++ checker.cpp -ochecker -O2 -Wall -Wextra --std=c++23")
else:
	os.system(
	"g++ "
	+ problem_name
	+ "_TJ.cpp -O2 -Wall -Wextra --std=c++23 -o"
	+ problem_name
	+ "_TJ")
os.system(
	"g++ " + problem_name + ".cpp -O2 -Wall -Wextra --std=c++23 -o" + problem_name
)
validator = bool(int(input("是否需要使用数据校验程序(validator.cpp)?(1: 是 0: 否)")))
if validator:
	os.system("g++ validator.cpp -ovalidator -O2 -Wall -Wextra --std=c++23")



for tot in range(1,cnt+1):
	# launch your data generator or generate input data here
	if generator_cpp:
		os.system(".\\generator")
	else:
		os.system("python generator.py")
	if validator:
		while os.system(".\\validator")!=0:
			os.system(".\\generator")
	# launch your program here
	start_time = time.perf_counter()
	res_hmz=os.system(".\\" + problem_name)
	used_time = time.perf_counter() - start_time
	if res_hmz:
		# Runtime Error check
		result.add_row([str(tot),"\033[35m Runtime Error \033[0m","-1"])
		continue
	if not(spj):
		output_hmz = open(problem_name + ".out", "r")
		os.system(".\\" + problem_name + "_TJ")
		output_tj = open(problem_name + "_TJ.out", "r")
		if(output_tj.read()!=output_hmz.read()):
			result.add_row([str(tot),"\033[31m Wrong Answer \033[0m",str(used_time)+"s"])
		else:
			result.add_row([str(tot),"\033[32m Accepted \033[0m",str(used_time)+"s"])
		output_tj.close()
	else:
		# Special Judge required
		os.system(".\\checker "+problem_name+".in "+problem_name+".out "+problem_name+".ans "+problem_name+".res")
		res=open(problem_name+".res","r+")
		if res.read().find("Wrong Answer"):
			result.add_row([str(tot),"\033[31m Wrong Answer \033[0m",str(used_time)+"s"])
		else:
			result.add_row([str(tot),"\033[32m Accepted \033[0m",str(used_time)+"s"])
	print("checking in progress: "+str(tot)+"/"+str(cnt)+" completed.")
	
print(result.get_string())
