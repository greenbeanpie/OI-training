import random
c=open("P2602,in","w+")

a=random.randint(1,1000000000001)
b=random.randint(1,1000000000001)
c.write(str(a))
c.write(" ")
c.write(str(b))
c.close()