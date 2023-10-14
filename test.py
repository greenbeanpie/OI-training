# encoding=utf-8
from math import *

def f(x):
	for i in range(2,floor(x**0.5)+1):
		while x%i==0:
			print(i,end=" ")
			x=x/i
	if(x>1):
		print(int(x))

x=4557785

f(int(input()))