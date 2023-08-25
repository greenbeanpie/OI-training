# encoding=utf-8
import os,prettytable

result=prettytable.PrettyTable()
result.field_names=["Test Case","Result","Time"]

work_dir = "D:\\OI-training\\"

problem_name = input("请输入希望进行对拍的题目的题号")
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
elif problem_name == "test":
	os.chdir(work_dir + "\\test\\")

generator_cpp = bool(int(input("请选择生成器语言: C++(0)/Python(1)")))
if generator_cpp:
	os.system("g++ generator.cpp -Ofast -ogenerator")
spj = bool(int(input("是否需要使用SPJ(testlib.h)? 0: 否 1: 是")))
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

tot = 0
while True:
	tot=tot+1
	# launch your data generator or generate input data here
	if generator_cpp:
		os.system(".\\generator")
	else:
		os.system("python generator.py")
	# launch your program here
	res_hmz=os.system(".\\" + problem_name)
	if res_hmz:
		# Runtime Error check
		result.add_row([str(tot),"Runtime Error","-1"])
	if not(spj):
		output_hmz = open(problem_name + ".out", "r")
		os.system(".\\" + problem_name + "_TJ")
		output_tj = open(problem_name + "_TJ.out", "r")
		if(output_tj.read()!=output_hmz.read()):
			break
		output_tj.close()
	else:
		# Special Judge required
		os.system(".\\checker "+problem_name+".in "+problem_name+".out "+problem_name+".ans "+problem_name+".res")
		res=open(problem_name+".res","r+")
		if res.read().find("Wrong Answer"):

		else:


	output_hmz.close()
	
print("Wrong Answer.\nWrong answer on test "+str(tot)+". Check output file for more detail.")