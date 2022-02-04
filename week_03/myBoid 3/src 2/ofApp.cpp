#include "ofApp.h"

ofApp::~ofApp()
{
    for (int i = 0; i < boids.size(); i++)
    {
        delete boids[i];
        delete obstacles[i];
    }
}

//--------------------------------------------------------------
void ofApp::setup(){
    min.set(0, 0);
    max.set(ofGetWidth(), ofGetHeight());
    
    for (int i = 0; i < 100; i++){
        boids.push_back(new Boid());
//        Obstacle myObs;
//        Boid * thisObs = &myObs;
        
        obstacles.push_back(new Obstacle());
        std::cout<<obstacles.size()<<std::endl;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < boids.size(); i++)
    {
//        std::cout<<i<<std::endl;
//        boids[i]->update<Boid>(boids, min, max);
//        obstacles[i]->update<Obstacle>(obstacles, min, max);
        
        boids[i]->update(boids, min, max);
        obstacles[i]->update(obstacles, min, max);
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < boids.size(); i++)
    {
        boids[i]->draw();
        obstacles[i]->draw();
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
