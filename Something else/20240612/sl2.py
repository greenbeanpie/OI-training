# -*- coding: utf-8 -*-
"""
Created on Mon Jun 17 14:48:02 2024

@author: Administrator
"""
s = "QWERTYUIOPASDFGHJKLZXCVBNM"
k = {s[i]: chr(ord("A") + i) for i in range(len(s))}


def xhw(a):
    b = ""
    num = int(a)
    while num != 0:
        b += str(num % 2)
        num = num // 2
    b = b[::-1]
    b = "0" * (8 - len(b)) + b
    return b


def wwc(a):
    b = ""
    for i in range(0, len(a), 4):
        num = 0
        for j in range(i, i + 4):
            if j < 4:
                num = num * 2 + int(a[j])
            else:
                num = num * 2 + int(a[j] != "1")
        if num > 9:
            b = b + chr(num + 55)
        else:
            b = b + str(num)
    return b


x = input()
l = []
ans = ""
for i in range(len(x)):
    if "a" > x[i] >= "A":
        l.append(ord(k[x[i]]))
    elif x[i] <= "9":
        l.append(ord(x[i]))
    else:
        l.append(ord(x[i]))
for i in range(len(x)):
    ans = ans + wwc(xhw(l[i]))
print(ans)
