# encoding=utf-8
import random
import os
import time
os.chdir("/mnt/c/Users/Administrator/Desktop/OI-training/Atcoder/AT_joisc2014_c")
tot=1
while True:
	# launch your data generator or generate input data here
	os.system("./generator")
	time.sleep(0.15)
	# launch your program ${program_name}$ here
	os.system("./AT_joisc2014_c")
	os.system("./AT_joisc2014_c_TJ")
	# open your output file here
	output_hmz=open("AT_joisc2014_c.out","r")
	output_tj=open("AT_joisc2014_c_TJ.out","r")
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