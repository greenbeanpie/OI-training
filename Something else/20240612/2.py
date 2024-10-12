p,k=input(),input()
k=k.rjust(7,"0")
p1=[bin(ord(i))[2:] for i in p]
print(p1)
def xor(a:str,b:str):
	ans = ""
	for i in range(len(a)):
		ans+="1" if a[i]!=b[i] else "0"
	return ans
for i in range(len(p1)):
	p1[i]=xor(p1[i],k)
print(p1)