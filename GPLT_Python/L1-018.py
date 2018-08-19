#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jul 15 16:54:40 2018

@author: zhuzihao
"""

N=input().split(':')
if int(N[0])<13:
    print('Only '+N[0]+':'+N[1]+'.  Too early to Dang.')
else:
    if int(N[1])>0:
        for i in range(int(N[0])-12):
            print('Dang',end='')
        print('Dang')
    else:
        for i in range(int(N[0])-13):
            print('Dang',end='')
        print('Dang')