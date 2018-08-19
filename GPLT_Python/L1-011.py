#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jul 15 11:34:46 2018

@author: zhuzihao
"""

a=input()
b=list(input())
for i in b:
    a=a.replace(i,'')
print(a)