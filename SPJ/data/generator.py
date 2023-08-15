import os
os.chdir("/OI-training/SPJ/data")
ans="ACCCBACCDCCDBABBAFFTDCCTFTDABCADBABCDBC"
for i in range(1,40):
    filei=open(str(i)+".in","w+")
    fileo=open(str(i)+".out","w+")
    filei.write(str(i))
    fileo.write(ans)
    filei.close()
    fileo.close()