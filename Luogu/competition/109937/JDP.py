import os,random
a=""
b=""
os.chdir("/Users/hddhp/OI-training/Luogu/competition/109937")
while a==b:
    ipt=open("J1.in","w+")
    ipt.write(str(random.randint(1,100))+" ")
    ipt.write(str(random.randint(1,100))+" ")
    ipt.write(str(random.randint(1,100))+" ")
    ipt.close()
    os.system("pwd")
    os.system("./J1")
    os.system("./J1a")
    opt1=open("J1.out","r")
    opt2=open("J1a.out","r")
    if(opt1.read!=opt2.read):
        break