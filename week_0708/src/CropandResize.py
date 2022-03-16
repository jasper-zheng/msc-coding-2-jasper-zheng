# -*- coding: utf-8 -*-
"""
Created on Fri Mar  4 14:09:54 2022

@author: 21009460
"""

from PIL import Image 
import PIL

import os, os.path



imgs = []
path = "./all_imgs/1"
valid_images = [".jpg",".gif",".png",".tga"]
size = 512
for i,f in enumerate(os.listdir(path)):
    ext = os.path.splitext(f)[1]
    if ext.lower() not in valid_images:
        continue
    
    
    img = Image.open(os.path.join(path,f))
    
    w,h = img.size
    
    if w==h:
        img.resize((size,size)).convert('RGB').save(f'./dataset/1/{i:05}.jpg')
    
    elif w>h:
        img.crop(((w-h)/2,0,(w-h)/2+h,h)).resize((size,size)).convert('RGB').save(f'./dataset/1/{i:05}.jpg')
    
    elif h>w:
        img.crop((0,(h-w)/2,w,(h-w)/2+w)).resize((size,size)).convert('RGB').save(f'./dataset/1/{i:05}.jpg')
        
    if i%100==0:
        print(i)
    
    
    