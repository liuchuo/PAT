#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jul 15 16:38:18 2018

@author: zhuzihao
"""

a=[]
while True:
    N=input()
    if N!='.':
        a.append(N)
    else:
        break
if len(a)<2:
    print('Momo... No one is for you ...')
elif 2<=len(a)<14:
    print(a[1]+' is the only one for you...')
else:
    print(a[1]+' and '+a[13]+' are inviting you to dinner...')