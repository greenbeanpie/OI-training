from math import *
# s=input()
# k=int(input())
s="hello world!"
k=5
ans=""

for i in range(k):
	ans+=s[i::k]

print(ans)