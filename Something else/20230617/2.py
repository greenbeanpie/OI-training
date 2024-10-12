from slib import f2 as _10to2
from slib import f5 as _2to16
s="QWERTYUIOPASDFGHJKLZXCVBNM"
key={s[i]:chr(ord('A')+i) for i in range(len(s))}
w=input()
ans=""
for i in w:
	if i.isupper():
		i=key[i]
	cur2 = _10to2(ord(i))
	cur2 = cur2.rjust(8,"0")
	tmp=""
	for i in range(4,8):
		if cur2[i]=="1":
			tmp += "0"
		else:
			tmp+="1"
	cur2 = cur2[:4]+tmp
	cur16 = _2to16(cur2)
	ans+=cur16
print(ans)
