# encoding=utf-8
import random
import os
os.chdir("/mnt/c/Users/Administrator/Desktop/OI-training/Luogu/P1/P12/P1253/")
tot=1
while True:
	file=open("P1253.in","w+")
	op=random.randint(1,1000000)
	num=random.randint(1,1000000)
	num_max=1000000000
	file.write(str(num)+" ")
	file.write(str(op))
	file.write("\n")
	for i in range(num):
		file.write(str(random.randint(-num_max,num_max)))
		file.write(" ")
	file.write("\n")
	for i in range(op):
		op=random.randint(1,3)
		file.write(str(op))
		file.write(" ")
		if(op==3):
			l=random.randint(1,num)
			r=random.randint(l,num)
			file.write(str(l)+" "+str(r))
		else:
			l=random.randint(1,num)
			r=random.randint(l,num)
			val=random.randint(-100000,num_max)
			file.write(str(l)+" "+str(r)+" "+str(val))
		file.write("\n")
	file.close()
	os.system("./P1253_TJ")
	os.system("./P1253")
	output_hmz=open("P1253.out","r")
	output_cjx=open("P1253_TJ.out","r")
	if(output_hmz.read().replace(" ","")!=output_cjx.read().replace(" ","")):
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