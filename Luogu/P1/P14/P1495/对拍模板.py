# encoding=utf-8
import random
import os
os.chdir("/mnt/c/Users/Administrator/Desktop/OI-training/Luogu/P1/P14/P1495/")
tot=1
while True:
	file=open("P1495.in","w+")
	n=random.randint(1,10)
	file.write(str(n)+"\n")
	for i in range(n):
		a=random.randint(10,100000)
		b=random.randint(1,a)
		file.write(str(a)+" "+str(b)+"\n")
	file.close()
	os.system("./P1495_TJ")
	os.system("./P1495")
	output_hmz=open("P1495.out","r")
	output_tj=open("P1495_TJ.out","r")
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