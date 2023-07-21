# encoding=utf-8
import random
import os
os.chdir("/mnt/c/Users/Administrator/Desktop/OI-training/Luogu/P2/P22/P2216/")
tot=1
while True:
	file=open("P2216.in","w+")
	n=random.randint(1,5)
	m=random.randint(1,5)
	k=random.randint(1,min(n,m))
	file.write(str(n)+" "+str(m)+" "+str(k)+"\n")
	for i in range(n):
		for j in range(m):
			file.write(str(random.randint(1,10))+" ")
		file.write("\n")
	file.close()
	os.system("./P2216_TJ")
	os.system("./P2216")
	output_hmz=open("P2216.out","r")
	output_tj=open("P2216_TJ.out","r")
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