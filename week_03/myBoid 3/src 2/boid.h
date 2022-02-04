#ifndef _BOID
#define _BOID
#define TWO_PI 6.2831853
#include <vector>
#include "ofMain.h"


class Boid
{
// all the methods and variables after the
// private keyword can only be used inside
// the class
public:
    ofVec3f position;
    ofVec3f velocity;
    
    float separationWeight;
    float cohesionWeight;
    float alignmentWeight;
    
    float separationThreshold;
    float neighbourhoodSize;
    
    template<class T>
    ofVec3f separation(std::vector<T *> &otherBoids){
       // finds the first collision and avoids that
       // should probably find the nearest one
       // can you figure out how to do that?
       for (int i = 0; i < otherBoids.size(); i++)
       {
           if(position.distance(otherBoids[i]->getPosition()) < separationThreshold)
           {
               ofVec3f v = position -  otherBoids[i]->getPosition();
               v.normalize();
               return v;
           }
       }
    }
    
    template<class T>
    ofVec3f cohesion(std::vector<T *> &otherBoids){
       ofVec3f average(0,0,0);
       int count = 0;
       for (int i = 0; i < otherBoids.size(); i++)
       {
           if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
           {
               average += otherBoids[i]->getPosition();
               count += 1;
           }
       }
       average /= count;
       ofVec3f v =  average - position;
       v.normalize();
       return v;
    }
    
    template<class T>
    ofVec3f alignment(std::vector<T *> &otherBoids){
       ofVec3f average(0,0,0);
       int count = 0;
       for (int i = 0; i < otherBoids.size(); i++)
       {
           if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
           {
               average += otherBoids[i]->getVelocity();
               count += 1;
           }
       }
       average /= count;
       ofVec3f v =  average - velocity;
       v.normalize();
       return v;
    }
    
// all the methods and variables after the
// public keyword can only be used by anyone
//public:
    Boid();
    Boid(ofVec3f &pos, ofVec3f &vel);
    
    ~Boid();
    
    ofVec3f getPosition();
    ofVec3f getVelocity();
    
    float r = 10;
    
    float getSeparationWeight();
    float getCohesionWeight();
    float getAlignmentWeight();
    
    float getSeparationThreshold();
    float getNeighbourhoodSize();
    
    void setSeparationWeight(float f);
    void setCohesionWeight(float f);
    void setAlignmentWeight(float f);
    
    void setSeparationThreshold(float f);
    void setNeighbourhoodSize(float f);
    
//    void update(std::vector<Boid *> &otherBoids, ofVec3f &min, ofVec3f &max);
    
//    template<class T>
//    void update(std::vector<T*,std::allocator<T*>> &otherBoids, ofVec3f &min, ofVec3f &max);
    
//    template<class T>
//    void update(std::vector<T*,std::allocator<T*>> &otherBoids, ofVec3f &min, ofVec3f &max)
//    {
//        velocity += separationWeight*separation<T>(otherBoids);
//        velocity += cohesionWeight*cohesion<T>(otherBoids);
//        velocity += alignmentWeight*alignment<T>(otherBoids);
//        if (sqrt(pow(velocity.x,2)+pow(velocity.y,2))>=10){
//            velocity *= 0.9;
//        }
//        walls(min, max);
//        position += velocity;
//    }

    void update(std::vector<Boid*> &otherBoids, ofVec3f &min, ofVec3f &max);
//    {
//        velocity += separationWeight*separation<T>(otherBoids);
//        velocity += cohesionWeight*cohesion<T>(otherBoids);
//        velocity += alignmentWeight*alignment<T>(otherBoids);
//        if (sqrt(pow(velocity.x,2)+pow(velocity.y,2))>=10){
//            velocity *= 0.9;
//        }
//        walls(min, max);
//        position += velocity;
//    }
    
    void walls(ofVec3f &min, ofVec3f &max);
    
    void draw();
};

#endif
