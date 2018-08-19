#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul 16 11:38:12 2018

@author: zhuzihao
"""

N=int(input())
dic={}
for i in range(N):
    temp=input().split()
    for j in temp[1:]:
        if j in dic:
            dic[j]=dic[j]+1
        else:
            dic[j]=1
k=max(dic.values())
tem=[]
for key, value in dic.items():
    if value==k:
        tem.append(int(key))
print(str(max(tem))+' '+str(max(dic.values())))