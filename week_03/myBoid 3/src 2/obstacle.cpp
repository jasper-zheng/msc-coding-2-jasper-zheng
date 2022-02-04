//
//  obstacle.cpp
//  myBoid
//
//  Created by Zheng Jasper on 01/02/2022.
//

#include "ofMain.h"
#include "obstacle.h"

//Obstacle::Obstacle():Boid(){}

void Obstacle::draw(){
    ofSetColor(255,255, 255);
    ofCircle(position.x, position.y, 3);
}

//void Obstacle::update(std::vector<Obstacle *> &otherBoids, ofVec3f &min, ofVec3f &max)
//{
//    velocity += separationWeight*separation(otherBoids);
//    velocity += cohesionWeight*cohesion(otherBoids);
//    velocity += alignmentWeight*alignment(otherBoids);
//
//    if (sqrt(pow(velocity.x,2)+pow(velocity.y,2))>=10){
//        velocity *= 0.9;
//    }
//    walls(min, max);
//    position += velocity;
//}
