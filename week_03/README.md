# Two Group of Boids with Noises  

An implementation of boids with polymorphism class in openFrameworks.     

https://user-images.githubusercontent.com/74963879/152512112-9aa08c81-d647-4e95-8afa-a5d77a187547.mp4



### Implementation  

##### Polymorphism   

In `boid.h`:

```
virtual void draw();
```  

In `ofApp.cpp`:  

```
for (int i = 0; i < 300; i++){
        boids.push_back(new Boid());
    }
    for (int i = 0; i < 100; i++){
        Boid * thisObs = new Obstacle;
        obstacles.push_back(thisObs);
    }
```

##### Draw Triangles  
<img src="graph.png" width=500></img>


##### X,Y -> frequency and amplitude  
```
for (int i = 0; i < output.getNumFrames(); ++i){

        double wave = osc1.sinewave(boids[5]->getPosition().x)*boids[5]->getPosition().y/800 +
                      osc2.sinewave(boids[50]->getPosition().x)*boids[50]->getPosition().y/800 +
                      osc3.sinewave(boids[20]->getPosition().x)*boids[20]->getPosition().y/800 +
                      osc4.sinewave(obstacles[20]->getPosition().x)*obstacles[20]->getPosition().y/800 +
                      osc5.sinewave(obstacles[10]->getPosition().x)*obstacles[10]->getPosition().y/800 +
                      osc6.sinewave(obstacles[70]->getPosition().x)*obstacles[70]->getPosition().y/800 +
                      osc7.sinewave(boids[200]->getPosition().x)*boids[200]->getPosition().y/800 +
                      osc8.sinewave(boids[280]->getPosition().x)*boids[280]->getPosition().y/800;
        output[i * outChannels] = wave/10;
        output[i * outChannels + 1] = output[i * outChannels];
```
