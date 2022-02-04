//
//  obstacle.hpp
//  myBoid
//
//  Created by Zheng Jasper on 01/02/2022.
//

#ifndef obstacle_hpp
#define obstacle_hpp
#include "boid.h"
#include <vector>
#include "ofMain.h"

#include <stdio.h>

class Obstacle : public Boid{
//private:
//    ofVec3f position;
//    ofVec3f velocity;
public:
//    Obstacle();
//    Obstacle(ofVec3f &pos, ofVec3f &vel);
//    ~Obstacle();
//        void update(std::vector<Obstacle *> &otherBoids, ofVec3f &min, ofVec3f &max);
    void draw();
};
#endif /* obstacle_hpp */
