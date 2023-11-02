#! /usr/local/bin/python3
#encoding=utf-8

import random,cyaron

n=500000



a=random.randint(1,1000000000)
b=random.randint(1,1000000000)
if b<=a:
	a,b=b,a
res=cyaron.Graph.tree(n,flower=1).to_str().split()
print(str(n)+" "+str(a)+" "+str(b))
for i in range(len(res)):
	if i%3!=2:
		print(res[i]+" ",end="")
	else:
		print("")
