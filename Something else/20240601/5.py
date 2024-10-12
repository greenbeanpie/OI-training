#! /usr/bin/python3
# encoding=utf-8
from math import ceil,floor

k=input()
M=input()
k=k.upper()
i=0
while i<len(M):
	if not('A' <= M[i] <= 'Z' or 'a' <= M[i] <= 'z'):
		print(M[i],end="")
		M=M[:i]+M[i+1:]
		continue
	flag=M[i].isupper()
	tmp=M[i].upper()
	ans=chr((ord(tmp)+ord(k[i%len(k)])-ord('A')*2)%26+ord('A'))
	if not flag:
		ans=ans.lower()
	print(ans,end="")
	i+=1
