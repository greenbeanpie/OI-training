# encoding=utf-8
import random
import os
os.chdir("/mnt/c/Users/Administrator/Desktop/OI-training/Luogu/P3/P33/P3387/")
tot=1
while True:
	file=open("P3387.in","w+")
	n=random.randint(1,10)
	m=random.randint(1,20)
	file.write(str(n)+" "+str(m)+"\n")
	for i in range(n):
		file.write(str(pow(2,i))+" ")
	file.write("\n")
	for i in range(m):
		file.write(str(random.randint(1,n))+" "+str(random.randint(1,n))+"\n")
	file.close()
	os.system("./P3387_TJ")
	os.system("./P3387")
	output_hmz=open("P3387.out","r")
	output_tj=open("P3387_TJ.out","r")
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