#ifndef _BOID
#define _BOID
#define TWO_PI 6.2831853
#include <vector>
#include "ofMain.h"

class Boid
{
// all the methods and variables after the
//private:
// the class
public:
    ofVec3f position;
    ofVec3f velocity;
//public:
    float separationWeight;
    float cohesionWeight;
    float alignmentWeight;
    
    float foreignSeparationWeight;
    float foreignCohesionWeight;
    
    float separationThreshold;
    float neighbourhoodSize;
    
    float foreignSeparationThreshold;
    float foreignNeighbourhoodThreshold;
    
    ofVec3f separation(std::vector<Boid *> &otherBoids);
    ofVec3f cohesion(std::vector<Boid *> &otherBoids);
    ofVec3f alignment(std::vector<Boid *> &otherBoids);
    
    ofVec3f foreignSeparation(std::vector<Boid *> &foreigners);
    ofVec3f foreignCohesion(std::vector<Boid *> &foreigners);
    
// all the methods and variables after the
// public keyword can only be used by anyone

    Boid();
    Boid(ofVec3f &pos, ofVec3f &vel);
    
    ~Boid();
    
    ofVec3f getPosition();
    ofVec3f getVelocity();
    
    float r = 8;
    
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
//
//    template<class T>
//    void update(std::vector<T*,std::allocator<T*>>& otherBoids, ofVec3f &min, ofVec3f &max);
    
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

    void update(std::vector<Boid *> &otherBoids, std::vector<Boid *> &foreigners, ofVec3f &min, ofVec3f &max);
    
    void walls(ofVec3f &min, ofVec3f &max);
    
    virtual void draw();
};

#endif
