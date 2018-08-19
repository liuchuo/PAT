#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jul 15 16:16:45 2018

@author: zhuzihao
"""

N=int(input())
a=[]
for i in range(N):
    temp=input().split()
    if temp[0]=='M':
        a.append(eval(temp[1])/1.09)
    else:
        a.append(eval(temp[1])*1.09)
for i in a:
    print("%.2f" %i)