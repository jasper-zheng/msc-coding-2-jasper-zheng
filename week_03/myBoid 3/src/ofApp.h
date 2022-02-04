#pragma once

#include "ofMain.h"
#include "boid.h"
#include "obstacle.h"
#include <vector>

#include "ofxMaxim.h"

class ofApp : public ofBaseApp{

	public:
        ~ofApp();
    
        void setup() override;
        void update() override;
        void draw() override;

        void keyPressed(int key) override;
        void keyReleased(int key) override;
        void mouseMoved(int x, int y ) override;
        void mouseDragged(int x, int y, int button) override;
        void mousePressed(int x, int y, int button) override;
        void mouseReleased(int x, int y, int button) override;
        void mouseEntered(int x, int y) override;
        void mouseExited(int x, int y) override;
        void windowResized(int w, int h) override;
        void dragEvent(ofDragInfo dragInfo) override;
        void gotMessage(ofMessage msg) override;
    
        ofSoundStream soundStream;
        
        /* ofxMaxi*/
        void audioIn(ofSoundBuffer& input) override; // not used in this example
        void audioOut(ofSoundBuffer& output) override;
//        std::vector<Boid *> boids;
//        std::vector<Obstacle *> obstacles;
    
        std::vector<Boid *> boids;
        std::vector<Boid *> obstacles;
    
//        maxiOsc lfo1;
        maxiOsc osc1;
        maxiOsc osc2;
        maxiOsc osc3;
        maxiOsc osc4;
        maxiOsc osc5;
        maxiOsc osc6;
        maxiOsc osc7;
        maxiOsc osc8;
        
        ofVec3f min;
        ofVec3f max;
};
