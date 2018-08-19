#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jul 15 10:55:31 2018

@author: zhuzihao
"""

dic={'0':'ling','1':'yi','2':'er','3':'san','4':'si','5':'wu','6':'liu','7':'qi','8':'ba','9':'jiu'}
N=input()
for i in range(len(N)-1):
    if i==0 and N[i]=='-':
        print('fu',end=' ')
    else:
        print(dic[N[i]],end=' ')
print(dic[N[-1]])