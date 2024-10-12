#! /usr/bin/python3
# encoding=utf-8
import random
from math import ceil,floor

n=10
s=[]

for i in range(n):
	s.append(random.randint(1,10))

dic={}

i=0

while i<len(s):
	if s.index(s[i])!=i:
		s.pop(i)
	else:
		i+=1


print(s)