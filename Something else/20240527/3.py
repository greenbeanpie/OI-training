#! /usr/bin/python3
# encoding=utf-8
from math import ceil,floor

n=int(input())
l=[""]*n
for i in range(n):
	for j in range(i+1):
		if j==0:
			l[i]+="*"
		else:
			l[i]+=" *"

for i in range(n):
	temp = l[i].center(len(l[-1]))
	print(temp)