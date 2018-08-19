#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jul 15 11:02:51 2018

@author: zhuzihao
"""

N=input().split()
k=0
for i in range(int(N[0]),int(N[-1])+1):
    k=k+1
    if k==5:
        print("%5d" %i)
        k=0
    else:
        print("%5d" %i,end='')
if k!=0:    
    print()
print('Sum = '+str(sum(range(int(N[0]),int(N[-1])+1))))