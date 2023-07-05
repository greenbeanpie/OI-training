import random
import os
os.chdir("/workspaces/OI-training/XYD/20230704/C")
tot=1
while True:
	file=open("C.in","w+")
	num=random.randint(1,10000)
	file.write(str(num))
	file.write("\n")
	for i in range(num):
		if(random.randint(0,1)==0):
			file.write("B")
		else:
			file.write("G")
	file.write("\n")
	for i in range(num):
		file.write(str(random.randint(1,10000000)))
		file.write(" ")
	file.close()
	os.system("./C_cjx")
	os.system("./C")
	output_hmz=open("C.out","r")
	output_cjx=open("C_cjx.out","r")
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