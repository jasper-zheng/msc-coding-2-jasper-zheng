#include "ofApp.h"

ofApp::~ofApp()
{
    for (int i = 0; i < boids.size(); i++)
    {
        delete boids[i];
//        delete obstacles[i];
    }
    for (int i = 0; i < obstacles.size(); i++)
    {
//        delete boids[i];
        delete obstacles[i];
    }
}

//--------------------------------------------------------------
void ofApp::setup(){
    int sampleRate = 44100; /* Sampling Rate */
    int initialBufferSize = 512; /* Buffer Size. you have to fill this buffer with sound using the for loop in the audioOut method */
    ofxMaxiSettings::setup(sampleRate, 2, initialBufferSize);
    
    ofSoundStreamSettings settings;
    
    settings.setOutListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels = 2;
    settings.numInputChannels = 0;
    settings.bufferSize = initialBufferSize;
    soundStream.setup(settings);
    
    
    min.set(0, 0);
    max.set(ofGetWidth(), ofGetHeight());
    
    for (int i = 0; i < 300; i++){
        boids.push_back(new Boid());
    }
    for (int i = 0; i < 100; i++){
        Boid * thisObs = new Obstacle;
        obstacles.push_back(thisObs);
//        std::cout<<obstacles.size()<<std::endl;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->update(boids, obstacles, min, max);
    }
    for (int i = 0; i < obstacles.size(); i++)
    {
        obstacles[i]->update(obstacles, boids, min, max);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < boids.size(); i++){
        boids[i]->draw();
    }
    for (int i = 0; i < obstacles.size(); i++){
        obstacles[i]->draw();
    }
}

void ofApp::audioIn(ofSoundBuffer& input){
    std::size_t inChannels = input.getNumChannels();
    for (size_t i = 0; i < input.getNumFrames(); i++){
    }
}

void ofApp::audioOut(ofSoundBuffer& output){
    std::size_t outChannels = output.getNumChannels();
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
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
