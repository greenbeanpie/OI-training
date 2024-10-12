# -*- coding: utf-8 -*-
"""
Created on Mon Sep 23 14:35:31 2024

@author: Administrator
"""

##1、统计一段文本中某个字母的个数
a="What's the weather today?"
key="a"
cnt=0
for i in a:
    if i==key:
        cnt+=1


##2、统计一篇文章中某个单词出现的次数
#文章内容在“202201A.txt”
txt=open("202201A.txt","r",encoding="utf-8").read()

punc = [i for i in ",.\":;?!@#$%^&*()`~\n"]

for i in punc:
    txt = txt.replace(i," ")

words = txt.lower().split(" ")

d = {}

for i in words:
    if i!="" and i.islower():
        if not i in d:
            d[i]=0
        d[i]+=1

d1= sorted(d,key=lambda d:d.values())
##3、统计一篇文章中出现频率最高的3个词（中文）
#文章内容在“news.txt”
