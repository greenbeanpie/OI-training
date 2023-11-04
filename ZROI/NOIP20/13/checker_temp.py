#! /usr/local/bin/python3
# encoding=utf-8

import os

filename = "geometry"

for i in range(1,26):
	os.system("./"+filename+"_TJ < "+filename+str(i)+".in > "+filename+str(i)+".ans")
# for i in range(1,51):
# 	os.system("./generator > "+filename+str(i)+".in")
