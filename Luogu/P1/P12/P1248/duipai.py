# encoding=utf-8
import os
import random
os.chdir("/mnt/c/Users/Administrator/Desktop/OI-training/Luogu/P1/P12/P1248/")
tot=1
while True:
	file=open("P1248.in","w+")
	num=random.randint(1,10)
	file.write(str(num))
	file.write("\n")
	for i in range(num):
		file.write(str(random.randint(1,10)))
		file.write(" ")
	file.write("\n")
	for i in range(num):
		file.write(str(random.randint(1,10)))
		file.write(" ")
	file.close()
	os.system("./P1248")
	os.system("./P1248_TJ")
	myopt=open("P1248.out","r")
	tjopt=open("P1248_TJ.out","r")
	if(myopt.read()!=tjopt.read()):
		print("你妈炸了")
		break
	print("第"+str(tot)+"次你妈没炸")
	tot+=1