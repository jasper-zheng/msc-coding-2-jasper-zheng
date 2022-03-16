# -*- coding: utf-8 -*-
"""
Created on Wed Feb  9 15:11:03 2022

@author: 21009460
"""
from bs4 import BeautifulSoup
import requests

#%%
import os
from selenium import webdriver
#from selenium.webdriver.common.keys import Keys
import time

import shutil

#%%
def save_web(input_url,save_dir,scroll_num=5):
    chromrdriver = "chromedriver"
    os.environ["webdriver.chrome.driver"] = chromrdriver
    driver = webdriver.Chrome(chromrdriver)
    driver.get(input_url)
    
    for i in range(scroll_num):
        driver.execute_script("window.scrollTo(1,50000)")
        time.sleep(5)
    
    file = open(save_dir, 'w')
    file.write(driver.page_source)
    file.close()
    
    driver.close()

#%%

#html_page = requests.get('https://www.flickr.com/photos/nasahubble/albums/72157667717916603')


def scrape_page(page_dir,save_dir,file_name_prefix):
    page = open(page_dir,'r')
    soup = BeautifulSoup(page, 'html.parser')
    
    all_img = soup.findAll('div',class_="awake")
    
    for i, img_container in enumerate(all_img):
        img_url = 'https:'+ img_container.attrs['style'].split('"')[1]
        #img_url = 'https:'+ img_container.attrs['style'].split('url')[1][1:-1]
        img = requests.get(img_url, stream=True)
    
        if img.status_code == 200:                     #200 status code = OK
           with open(f'{save_dir}/heic_{file_name_prefix}_{i:03}.jpg', 'wb') as f: 
              img.raw.decode_content = True
              shutil.copyfileobj(img.raw, f)
        if (i%10==0):
            print(f'scraping at {file_name_prefix}_{i:03}')
        
    
#%%
page = open('web/DS.html','r')
soup = BeautifulSoup(page, 'html.parser')


#%%

img_con = soup.findAll('div',class_="awake")


#%%

img_url = 'https:'+ img_con[0].attrs['style'].split('url')[1][1:-1]

#%%

img = requests.get(img_url, stream=True) #Get request on full_url



#%%

if img.status_code == 200:                     #200 status code = OK
   with open("test.jpg", 'wb') as f: 
      img.raw.decode_content = True
      shutil.copyfileobj(img.raw, f)
      
#%%

#save_web('https://www.flickr.com/photos/nasahubble/albums/72157667717916603/page1','saved_web/ds.html',scroll_num=6)

#scrape_page('saved_web/ds.html','saved_img')




for i in range(2):
    index = i + 1
    file_index = index + 6
    save_web(f'https://www.flickr.com/photos/nasahubble/albums/72157695205167691/page{index}',f'saved_web/page{file_index}.html',scroll_num=6)
    scrape_page(f'saved_web/page{file_index}.html','saved_img',f'p{file_index:02}')





#%%

















