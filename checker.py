# encoding=utf-8
import os
work_dir="D:\\OI-training\\"
problem_name="P9575"
if(problem_name[0]=='P'):
	os.chdir(work_dir+"Luogu\\"+problem_name[0:2]+"\\"+problem_name[0:3]+"\\"+problem_name+"\\")
elif(problem_name=="test"):
	os.chdir(work_dir+"\\test\\")
os.system("g++ generator.cpp -Ofast -ogenerator")
os.system("g++ "+problem_name+".cpp -O2 -Wall -Wextra --std=c++14 -o"+problem_name)
os.system("g++ "+problem_name+"_TJ.cpp -O2 -Wall -Wextra --std=c++14 -o"+problem_name+"_TJ")
tot=1
while True:
	# launch your data generator or generate input data here
	os.system(".\\generator")
	# launch your program ${program_name}$ here
	os.system(".\\"+problem_name+"_TJ")
	os.system(".\\"+problem_name)
	# open your output file here
	output_hmz=open(problem_name+".out","r")
	output_tj=open(problem_name+"_TJ.out","r")
	if(os.system("python checker.py")):
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