# encoding=utf-8
import random
import os
os.chdir("/mnt/c/Users/Administrator/Desktop/OI-training/XYD/20230704/E")
tot=1
while True:
	file=open("E.in","w+")
	num=random.randint(1,10)
	file.write(str(num))
	file.write("\n")
	for i in range(num):
		for j in range(num):
			file.write(str(random.randint(1,9)))
			file.write(" ")
		file.write("\n")
	file.write("0")
	file.close()
	os.system("./E_TJ")
	os.system("./E_LH")
	output_hmz=open("E_TJ.out","r")
	output_cjx=open("E_LH.out","r")
	if(output_hmz.read()!=output_cjx.read()):
	 	print("你妈炸了")
		break
	else:
		print("第"+str(tot)+"次你妈没炸")
	output_hmz.close()
	output_cjx.close()
	if(tot>=1000):
		print("你妈没炸!!!太厉害了!!!%%%orz")
		break
	tot+=1