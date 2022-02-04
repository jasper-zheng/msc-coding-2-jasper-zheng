/*  boid.cpp
*  boids
*
*  Created by Marco Gillies on 05/10/2010.
*  Copyright 2010 Goldsmiths, University of London. All rights reserved.
*
*/

#include "boid.h"
#include "ofMain.h"
#include <cmath>

Boid::Boid()
{
   separationWeight = 0.8f;
   cohesionWeight = 0.3f;
   alignmentWeight = 0.15f;
   
   separationThreshold = 25;
   neighbourhoodSize = 150;
   
   position = ofVec3f(ofRandom(0, 200), ofRandom(0, 200));
   velocity = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2));
}

Boid::Boid(ofVec3f &pos, ofVec3f &vel)
{
   separationWeight = 0.8f;
   cohesionWeight = 0.3f;
   alignmentWeight = 0.15f;
   
   separationThreshold = 25;
   neighbourhoodSize = 150;
   
   position = pos;
   velocity = vel;
}

Boid::~Boid()
{
   
}

float Boid::getSeparationWeight()
{
   return separationWeight;
}
float Boid::getCohesionWeight()
{
   return cohesionWeight;
}

float Boid::getAlignmentWeight()
{
   return alignmentWeight;
}


float Boid::getSeparationThreshold()
{
   return separationThreshold;
}

float Boid::getNeighbourhoodSize()
{
   return neighbourhoodSize;
}


void Boid::setSeparationWeight(float f)
{
   separationWeight = f;
}
void Boid::setCohesionWeight(float f)
{
   cohesionWeight = f;
}

void Boid::setAlignmentWeight(float f)
{
   alignmentWeight = f;
}


void Boid::setSeparationThreshold(float f)
{
   separationThreshold = f;
}

void Boid::setNeighbourhoodSize(float f)
{
   neighbourhoodSize = f;
}


ofVec3f Boid::getPosition()
{
   return position;
}

ofVec3f Boid::getVelocity()
{
   return velocity;
}

//template<class T>
//ofVec3f Boid::separation(std::vector<T *> &otherBoids)
//{
//   // finds the first collision and avoids that
//   // should probably find the nearest one
//   // can you figure out how to do that?
//   for (int i = 0; i < otherBoids.size(); i++)
//   {
//       if(position.distance(otherBoids[i]->getPosition()) < separationThreshold)
//       {
//           ofVec3f v = position -  otherBoids[i]->getPosition();
//           v.normalize();
//           return v;
//       }
//   }
//}
//
//template<class T>
//ofVec3f Boid::cohesion(std::vector<T *> &otherBoids)
//{
//   ofVec3f average(0,0,0);
//   int count = 0;
//   for (int i = 0; i < otherBoids.size(); i++)
//   {
//       if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
//       {
//           average += otherBoids[i]->getPosition();
//           count += 1;
//       }
//   }
//   average /= count;
//   ofVec3f v =  average - position;
//   v.normalize();
//   return v;
//}
//
//template<class T>
//ofVec3f Boid::alignment(std::vector<T *> &otherBoids)
//{
//   ofVec3f average(0,0,0);
//   int count = 0;
//   for (int i = 0; i < otherBoids.size(); i++)
//   {
//       if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
//       {
//           average += otherBoids[i]->getVelocity();
//           count += 1;
//       }
//   }
//   average /= count;
//   ofVec3f v =  average - velocity;
//   v.normalize();
//   return v;
//}

//template<class T>
//void Boid::update(std::vector<T*,std::allocator<T*>> &otherBoids, ofVec3f &min, ofVec3f &max)
//{
////    velocity += separationWeight*separation<T>(otherBoids);
////    velocity += cohesionWeight*cohesion<T>(otherBoids);
////    velocity += alignmentWeight*alignment<T>(otherBoids);
//
//    if (sqrt(pow(velocity.x,2)+pow(velocity.y,2))>=10){
//        velocity *= 0.9;
//    }
//    walls(min, max);
//    position += velocity;
//}

void Boid::update(std::vector<Boid *> &otherBoids, ofVec3f &min, ofVec3f &max)
{
//    velocity += separationWeight*separation<T>(otherBoids);
//    velocity += cohesionWeight*cohesion<T>(otherBoids);
//    velocity += alignmentWeight*alignment<T>(otherBoids);

    if (sqrt(pow(velocity.x,2)+pow(velocity.y,2))>=10){
        velocity *= 0.9;
    }
    walls(min, max);
    position += velocity;
}

void Boid::walls(ofVec3f &min, ofVec3f &max)
{
   if (position.x < min.x){
       position.x = min.x;
       velocity.x *= -1;
   } else if (position.x > max.x){
       position.x = max.x;
       velocity.x *= -1;
   }
   
   if (position.y < min.y){
       position.y = min.y;
       velocity.y *= -1;
   } else if (position.y > max.y){
       position.y = max.y;
       velocity.y *= -1;
   }
   
   
}

void Boid::draw(){
    ofSetColor(0,255, 255);
//   ofCircle(position.x, position.y, 3);
    double theta = atan2(velocity.y,velocity.x);
    ofDrawTriangle(position.x+r*2*cos(theta), position.y+r*2*sin(theta),
                   position.x+r*cos(theta+TWO_PI/3), position.y+r*sin(theta+TWO_PI/3),
                   position.x+r*cos(theta-TWO_PI/3), position.y+r*sin(theta-TWO_PI/3));
}
