# encoding=utf-8
import os
work_dir="D:\\OI-training\\Atcoder\\20230819\\C\\"
os.chdir(work_dir)
problem_name="C"
os.system("g++ generator.cpp -Ofast -ogenerator")
os.system("g++ "+problem_name+".cpp -O2 -Wall -Wextra --std=c++14 -o"+problem_name)
os.system("g++ "+problem_name+"_TJ.cpp -O2 -Wall -Wextra --std=c++14 -o"+problem_name+"_TJ")
tot=1
while True:
	# launch your data generator or generate input data here
	os.system(".\\generator")
	# launch your program ${program_name}$ here
	os.system(".\\"+problem_name+"_TJ.exe")
	os.system(".\\"+problem_name+".exe")
	# open your output file here
	output_hmz=open(problem_name+".out","r")
	output_tj=open(problem_name+"_TJ.out","r")
	if(output_hmz.read()!=output_tj.read()):
		print("你妈炸了")
		break
	else:
		print("第"+str(tot)+"次你妈没炸")
	output_hmz.close()
	output_tj.close()
	if(tot>=1000):
		print("你妈没炸!!!太厉害了!!!%%%orz")
		break
	tot+=1