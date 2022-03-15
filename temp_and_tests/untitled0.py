#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Feb 26 16:57:23 2022

@author: winter_camp
"""

# Random Local Search
# -----------------

# but it's a rubbish idea.

import math
import random

x = -2
y = 3;

def forwardMultiplyGate(x, y):
    return x * y

tweak_amount = 0.01 # this is a bit like the learning rate
best_out = -10000000
best_x = x
best_y = y

for k in range(100): # 100 is the number of steps
    x_try = x + tweak_amount * (random.random() * 2 - 1) # tweak x a bit
    y_try = y + tweak_amount * (random.random() * 2 - 1) # tweak y a bit
    out = forwardMultiplyGate(x_try, y_try)
    if out > best_out:
        # best improvement yet! Keep track of the x and y
        best_out = out
        best_x = x_try
        best_y = y_try
        print (best_out)

print ("This works, but is not very efficient.")






