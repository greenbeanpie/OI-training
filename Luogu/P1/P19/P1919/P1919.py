import decimal
decimal.getcontext().prec = 20000000
file=open("/mnt/c/Users/Administrator/Desktop/OI-training/Luogu/P1/P19/P1919/P1919.in","r")
a = file.readline()
b = file.readline()
flag=False
if a[0] == '-':
    flag=not(flag)
    a = a[1:]
if b[0] == '-':
    flag=not(flag)
    b = b[1:]
a = decimal.Decimal("0." + a)
b = decimal.Decimal("0." + b)
c = str(a * b)
c = c.replace("0.","")
while(c[0] == '0'):
    c = c[1:]
file2=open("/mnt/c/Users/Administrator/Desktop/OI-training/Luogu/P1/P19/P1919/P1919.out","w+")
if flag:
    file2.write('-')
file2.write(c)