#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jul 15 14:06:39 2018

@author: zhuzihao
"""

N=int(input())
k1=0
k2=0
temp=input().split()
for i in temp:
    if int(i)%2==0:
        k2=k2+1
    else:
        k1=k1+1
print(str(k1)+' '+str(k2))