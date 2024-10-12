#! /usr/bin/python3
# encoding=utf-8
from math import ceil,floor

s="abcde"
ans=""
for i in range(1,len(s)+1):
	for j in range(len(s)-i+1):
		ans+=s[j:j+i]+"/"

print(ans[:len(ans)-1])