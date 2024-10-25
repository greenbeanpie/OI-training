#! /usr/bin/python3
# encoding=utf-8
from math import ceil,floor

for i in range(1,10):
	for j in range(1,i+1):
		print(i,"*",j,"=",i*j,sep="",end=" ")
	print('\n',end="")