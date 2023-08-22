import os
os.chdir("D:\\OI-training\\Luogu\\P9\\P95\\P9575")
filei=open("P9575.in","r+")
fileo=open("P9575.out","r+")
ind=filei.readline()
ind=filei.readline()
ind=ind.split(" ")
def swap(x,y):
    z=x
    x=y
    y=z
def gcd(x,y):
    if x<y:
        z=x
        x=y
        y=z
    if x%y==0:
        return y
    return gcd(y,x%y)

outd=fileo.readline()
x=int(outd)
outd=fileo.read()
sum1=0
sum2=0
idx=0
for i in outd:
    if(i=='0'):
        sum1=sum1+gcd(x,int(ind[idx]))
        idx+=1
    else:
        sum2=sum2+gcd(x,int(ind[idx]))
        idx+=1
if(sum1!=sum2):
    exit(1)
exit(0)
        
    