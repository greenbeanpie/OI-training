# -*- coding: utf-8 -*-
"""
Created on Sat Sep  7 11:24:25 2024

@author: Administrator
"""


"""
#nums = [3,4,1,-1]
#nums = [3,-1,2,4]
#nums = [-5,4,3,-1,0,1]
nums=[1,2,3,4,5]
n=len(nums)
flag=[0]*(n+5)
for i in range(n):
    flag[max(nums[i],0)]=1

for i in range(1,n+1):
    if not flag[i]:
        print(i)
        break
else:
    print(n+1)
"""

nums=eval(input())
nums=[0]+nums
n=len(nums)
nums = [(i if i>0 else 0) for i in nums]
for i in range(1,n+1):
    while nums[nums[i]]!=nums[i] and nums[nums[i]]!=nums[i]:
        nums[i],nums[nums[i]]=nums[nums[i]],nums[i]

for i in range(1,n+1):
    if nums[i]!=i:
        print(i)
        break
else:
    print(n+1)