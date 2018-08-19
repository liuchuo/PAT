#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jul 15 11:18:36 2018

@author: zhuzihao
"""

N=input().split()
a=[]
for i in N:
    a.append(int(i))
a=sorted(a)
for i in range(3):
    if i==2:
        print(a[i])
    else:
        print(a[i],end='->')