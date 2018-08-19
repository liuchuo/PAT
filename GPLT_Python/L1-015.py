#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jul 15 19:06:14 2018

@author: zhuzihao
"""

N=input().split()
m=int(N[0])
for i in range(round(m/2,0)):
    for j in range(m):
        print(N[-1],end='')
    print()