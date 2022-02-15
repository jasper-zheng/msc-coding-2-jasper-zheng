#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Feb 11 11:44:47 2022

@author: winter_camp
"""

pow(2,38)

#%%



s = "g fmnc wms bgblr rpylqjyrc gr zw fylb. rfyrq ufyr amknsrcpq ypc dmp. bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. lmu ynnjw ml rfc spj."


#%%

old_string = "map"
new_string = ''
for s_1 in s:
    if ord(s_1)>=121:
        number = ord(s_1)-26
    else:
        number = ord(s_1)
    new_string += chr(number+2)
    
#%%


s = open('ooo.txt','r').read()

#%%

from collections import Counter

c = Counter(s)
print(c.most_common())


#%%


#65 90
#97 122

import re


#%%


target_string = open('ooo.txt','r').read()

result = re.findall("[a-z][A-Z]{3}([a-z])[A-Z]{3}[a-z]", target_string)


#%%
new_string = ''
for s in result:
    new_string+=s

#%%


import urllib.request

#%%

number = 63579
for i in range(400):
    with urllib.request.urlopen(f'http://www.pythonchallenge.com/pc/def/linkedlist.php?nothing={number}') as response:
       html = response.read()
       try:
           number = re.findall(r'[0-9]+',str(html))[0]
       except:
           print(html)
    print(html)


#%%










