#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

typedef hannWinFunctor grainPlayerWin;

class ofApp : public ofBaseApp{
    
public:
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
    
    // For drawing
    float waveform[4096]; //make this bigger, just in case
    int waveIndex;
    
    ofSoundStream soundStream;
    
    /* ofxMaxi*/
    void audioIn(ofSoundBuffer& input) override; // not used in this example
    void audioOut(ofSoundBuffer& output) override;
    
    maxiOsc lfo1;
    
//    static const int bandNum = 15;
//    int bandFreqs[bandNum] = {33,50,75,113,170,255,383,575,863,1295,1943,2915,4373,6560,9840};
    
    static const int bandNum = 30;
    int bandFreqs[bandNum] = {
        50,60,72,87,104,124,150,180,215,258,
        310,372,446,535,642,770,924,1109,1331,1597,
        1917,2300,2760,3312,3974,4769,5724,6869,8242,9890
    };
    
    static const int noteNum = 8;
    int notes[noteNum] = {31,33,35,36,38,40,42,43};
    int intervals[4] = {0,24,31,36};
    
    maxiOsc oscs[bandNum];
    float envs[bandNum];
    maxiEnvelopeFollowerF envFollowers[bandNum];
    maxiSVF bandpassIns[bandNum];
    maxiSVF bandpassOuts[bandNum];
    
    maxiSample sample01;
    
    int initialBufferSize;
    float * myAudioIn;
    
    convert util;
    
    maxiTimePitchStretch<grainPlayerWin, maxiSample> *pitch_12;
    
    maxiClock myClock;
    int randomNote = 0;
    
    int currentPlaying = 3; //0: originnal, 1: Modulator, 2: Carrier, 3: Output;
    
    
    float viewHeight = ofGetHeight();
    float viewWidth = ofGetWidth();
    
    ofRectangle myRect;
    
    float arrowPosition = viewHeight*0.85;
    float shift1=0;
    float shift2=0;
    float shift3=0;
    float shift4=0;
};
