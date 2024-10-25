#! /usr/bin/python3
# encoding=utf-8
from math import ceil,floor

s="hello world!"
l1=[4,1,5,3,2]
i=0
ans=""
l={}
for i in range(len(l1)):
	l[l1[i]]=i+1
i=0
while i<len(s):
	if len(s)-i<len(l):
		ans+=s[i::]
		break
	t = ""
	for j in range(len(l)):
		t+=s[l[j+1]+i-1]
	ans+=t
	i+=len(l)

print(ans)