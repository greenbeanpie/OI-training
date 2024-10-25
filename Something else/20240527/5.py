#! /usr/bin/python3
# encoding=utf-8
from math import ceil,floor

n=int(input())

l=[1]

for i in range(1,n+1):
	l.append(l[-1]*i)

for i in range(0,n):
	for j in range(0,i+1):
		print(l[i]//l[j]//l[i-j],end=" ")
	print()