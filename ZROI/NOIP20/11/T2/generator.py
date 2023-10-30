#! /usr/local/bin/python3
# encoding=utf-8

import cyaron,random

for i in range(11,14):
	with open("value"+str(i)+".in","w+") as file:
		n=random.randint(1,100000)
		res = cyaron.Graph.tree(n,flower=1,chain=0).to_str()  # type: ignore
		# res = cyaron.Graph.flower(100000).to_str()
		file.write(str(n)+"\n")
		file.write(res)
		res = res.split()
		# root = random.randint(1,100000)
		# for i in range(2,100000+1):
		# 	file.write(str(root))
		# 	file.write(" ")
