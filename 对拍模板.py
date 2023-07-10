# encoding=utf-8
import random
import os
os.chdir("/mnt/c/Users/Administrator/Desktop/OI-training/Luogu/P4/P49/P4941/")
tot=1
while True:
	file=open("P4941.in","w+")
	n=random.randint(1,4)
	m=random.randint(1,n)
	k=random.randint(0,n*n-n)
	file.write(str(n)+" "+str(m)+" "+str(k)+"\n")
	for i in range(n):
		file.write(str(random.randint(1,5))+" ")
	file.write("\n")
	for i in range(k):
		file.write(str(random.randint(1,n))+" "+str(random.randint(1,n))+" "+str(random.randint(1,5))+"\n")
	file.close()
	os.system("./P4941_TJ")
	os.system("./P4941")
	output_hmz=open("P4941.out","r")
	output_tj=open("P4941_TJ.out","r")
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