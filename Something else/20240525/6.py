#! /usr/bin/python3
# encoding=utf-8
from math import ceil,floor

ans="h dew!lolrol"
k=5
i=0
s=""
seg = ceil(len(ans)/k)
p = len(ans)%k
if p==0:
	p+=k
for i in range(seg):
	j=i
	cnt=0
	if i!=seg-1:
		while j<len(ans):
			s+=ans[j]
			cnt+=1
			if cnt<=p:
				j+=seg
			else:
				j+=seg-1
	else:
		while j<len(ans):
			s+=ans[j]
			cnt+=1
			if cnt<p:
				j+=seg
			else:
				break
print(s)
