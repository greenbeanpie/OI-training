# encoding=utf-8
a, b = map(int, input().split())
from decimal import Decimal

a = Decimal(a)
b = Decimal(b)
a = a**b
if a <= 1e9:
     print(a)
else:
    print(-1)
