# Channel Vocoder  

This is a 30-band vocoder implemented in openFrameworks using [Maximilian](https://github.com/micknoise/Maximilian) library.  

https://user-images.githubusercontent.com/74963879/151467762-3894d031-d4b9-4211-9627-e98a467986e5.mp4  

### Implementation  
Shown in the diagram above, where the modulator is the original vocal (plus another pitched down voice just to have more low end), the carrier is a group of sqare waves, `n = 30`. The bandpass filters and the envelope followers are using classes in the Maximilian library.
![m](https://sethares.engr.wisc.edu/vocoders/channelvocoder.gif)  
[↑ Img Reference](https://sethares.engr.wisc.edu/vocoders/channelvocoder.html)  


