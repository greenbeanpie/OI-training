# s=input()
s="ABCaasdf12DZX"
l=[]
for i in s:
    l.append(i)
for i in range(len(l)):
    if l[i].isupper():
        l[i]=str(ord(l[i])-64)
    elif l[i].isdigit():
        l[i]=chr(int(l[i])+ord('A')-1)

i=0;j=len(l)-1
while i<j:
    while i<j and not l[i].islower():
        i+=1
    while i<j and not l[j].islower():
        j-=1
    l[i],l[j]=l[j],l[i]
    l[i]=l[i].swapcase()
    l[j]=l[j].swapcase()
    i+=1
    j-=1

if i==j and l[i].islower():
    l[i]=l[i].swapcase()

for i in l:
    print(i,end=" ")