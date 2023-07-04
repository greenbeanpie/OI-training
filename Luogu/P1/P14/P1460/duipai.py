import random
import os
os.chdir("/workspaces/OI-training/Luogu/P1/P14/P1460/")
tot=1
while True:
	file=open("P1460.in","w+")
	v=random.randint(1,3)
	g=random.randint(1,5)
	file.write(str(v))
	file.write("\n")
	for i in range(v):
		file.write(str(random.randint(1,1000)))
		file.write(" ")
	file.write("\n")
	file.write(str(g))
	file.write("\n")
	for i in range(g):
		for i in range(v):
			file.write(str(random.randint(1,1000)))
			file.write(" ")
		file.write("\n")
	file.close()
	os.system("./P1460_xhw")
	os.system("./P1460")
	output_hmz=open("P1460.out","r")
	output_xhw=open("P1460_xhw.out","r")
	if(output_hmz.read()!=output_xhw.read()):
		print("你妈炸了")
		break
	else:
		print("第"+str(tot)+"次你妈没炸")
	output_hmz.close()
	output_xhw.close()
	if(tot>=1000):
		print("你妈没炸!!!太厉害了!!!%%%orz")
		break
	tot+=1