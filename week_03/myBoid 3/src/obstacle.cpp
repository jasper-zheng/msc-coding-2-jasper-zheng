//
//  obstacle.cpp
//  myBoid
//
//  Created by Zheng Jasper on 01/02/2022.
//

#include "ofMain.h"
#include "obstacle.h"



void Obstacle::draw(){
    ofSetColor(255,234,80);
    ofCircle(position.x, position.y, 3);
}
