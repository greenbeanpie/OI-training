# -*- coding: utf-8 -*-
"""
Created on Wed Sep 27 15:47:03 2023

@author: Administrator
"""




a=[['p',4],['b',8],['h',5],['h',0],['n',1],['o',7],['S',3],['u',-1],['Z',2]]
head=6
while head!=-1:
    print(a[head][0],end='->')
    head=a[head][1]

class l:
    
    class node:
        def __init__(self,val=0,nxt=-1):
            self.val=val
            self.nxt=nxt
    
    def __init__(self):
        self.idx_begin=-1
        self.idx_rbegin=-1
        self.l=[]
    
    def length(self)->int:
        return len(self.l)
    
    def push_back(self,val) -> None:
        if self.idx_rbegin==-1:
            self.l.append(self.node(val,-1))
            self.idx_rbegin=self.idx_begin=0
        else:
            self.l[self.idx_rbegin].nxt=len(l)
            self.l.append(self.node(val,-1))
            self.idx_rbegin=len(l)


lis=l()