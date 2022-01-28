#include "ofApp.h"
#include <math.h>
#include <ctime>

//--------------------------------------------------------------
void ofApp::setup(){
    
    std::srand(std::time(0));
    randomNote = std::rand()%7;
    
    ofBackground(0,0,0);
    
    //Initialize the drawing variables
    for (int i = 0; i < ofGetWidth(); ++i) {
        waveform[i] = 0;
    }
    waveIndex = 0;
    
//     Maximilian audio stuff
//    int sampleRate = 48000; /* Sampling Rate */
    int sampleRate = 44100; /* Sampling Rate */
    initialBufferSize = 512; /* Buffer Size. you have to fill this buffer with sound using the for loop in the audioOut method */
    ofxMaxiSettings::setup(sampleRate, 2, initialBufferSize);
    
    sample01.load(ofToDataPath("TORI_LETZLER_vocal_spoken_numeric_countdown.wav"));
    pitch_12 = new maxiTimePitchStretch<grainPlayerWin, maxiSample>(&sample01);
    myClock.setTempo(96);
    myClock.setTicksPerBeat(4);
    
//    myAudioIn = new float[initialBufferSize];/* inputs */
    
    // Setup ofSound
    ofSoundStreamSettings settings;
    
    settings.setOutListener(this);
//    settings.setInListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels = 2;
    settings.numInputChannels = 0;
    settings.bufferSize = initialBufferSize;
    soundStream.setup(settings);
    
//    bandpass01.setResonance(1);
    for (int i = 0; i < bandNum; ++i){
        bandpassIns[i].setCutoff(bandFreqs[i]);
        bandpassOuts[i].setCutoff(bandFreqs[i]);
        bandpassIns[i].setResonance(10);
        bandpassOuts[i].setResonance(10);
    }
    
    myRect.set(viewWidth*0.15,viewHeight*0.7,viewWidth*0.3,40);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    /////////////// waveform
//    ofTranslate(0, ofGetHeight()/2);
    ofSetColor(0, 255, 0);
    ofFill();
    
    
    ofDrawLine(0, 0, 1, waveform[1] * viewHeight/5. + viewHeight*0.2); //first line
    for(int i = 1; i < (viewWidth - 1); ++i) {
        ofDrawLine(i, waveform[i] * viewHeight/5. + viewHeight*0.2,
                   i + 1, waveform[i+1] * viewHeight/5. + viewHeight*0.2);
    }
//    ofSetColor(255, 255, 255);
    for (int n = 0; n < bandNum; ++n){
        ofDrawRectangle(viewWidth/(bandNum+2)*(n+1),viewHeight*0.5,
                        viewWidth/(bandNum+2), -envs[n]*100);
    }
//    ofDrawRectangle(myRect);
    ofDrawBitmapString("Original Recording",    100+shift1, viewHeight*0.7);
    ofDrawBitmapString("Modulator",             100+shift2, viewHeight*0.75);
    ofDrawBitmapString("Carrier",               100+shift3, viewHeight*0.8);
    ofDrawBitmapString("Output",                100+shift4, viewHeight*0.85);
    ofDrawBitmapString(">",                     70, arrowPosition);
}

//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer& input){
    std::size_t inChannels = input.getNumChannels();
    for (size_t i = 0; i < input.getNumFrames(); i++)
    {
        // handle input here
//        myAudioIn[i] = input[i * inChannels];
    }
}
//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer& output){
    std::size_t outChannels = output.getNumChannels();
    for (int i = 0; i < output.getNumFrames(); ++i){
        
        myClock.ticker();
        if(myClock.tick&&myClock.playHead%8==0&&ofRandom(1)>0.4){
            randomNote = std::rand()%noteNum;
            std::cout<<randomNote<<std::endl;
        }
        if(myClock.tick&&myClock.playHead%64==0){
            sample01.reset();
            pitch_12->setPosition(0);
        }
        
        float carrier = 0;
        for (int j = 0; j < 4; ++j){
            carrier += oscs[j].square(util.mtof(notes[randomNote]+intervals[j])) * 0.1;
        }
        float sample_di = sample01.playOnce();
        float modulator = pitch_12->playOnce(0.35, 1, 0.2, 2)*0.8 + sample_di;
//        float modulator = myAudioIn[i];
        float modulated = 0;
        for (int n = 0; n < bandNum; ++n){
            
            envs[n] = envFollowers[n].play(bandpassIns[n].play(modulator, 0, 1, 0, 0));
            modulated += bandpassOuts[n].play(carrier*envs[n], 0, 1, 0, 0)*0.5;
            
        }
        
        if (currentPlaying==0){
            output[i * outChannels] = sample_di;
        } else if (currentPlaying==1){
            output[i * outChannels] = modulator;
        } else if (currentPlaying==2){
            output[i * outChannels] = carrier*0.5;
        } else if (currentPlaying==3){
            output[i * outChannels] = modulated;
        }
        
        output[i * outChannels + 1] = output[i * outChannels];
        
        //Hold the values so the draw method can draw them
        waveform[waveIndex] =  output[i * outChannels];
        if (waveIndex < (ofGetWidth() - 1)) {
            ++waveIndex;
        } else {
            waveIndex = 0;
        }
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
    
    if (x>70&&x<300){
        if (y>0.67*viewHeight&&y<=0.72*viewHeight){
            shift1 = 5;
            shift2 = 0;
            shift3 = 0;
            shift4 = 0;
        } else if (y>0.72*viewHeight&&y<=0.77*viewHeight){
            shift1 = 0;
            shift2 = 5;
            shift3 = 0;
            shift4 = 0;
        } else if (y>0.77*viewHeight&&y<=0.82*viewHeight){
            shift1 = 0;
            shift2 = 0;
            shift3 = 5;
            shift4 = 0;
        } else if (y>0.82*viewHeight&&y<=0.87*viewHeight){
            shift1 = 0;
            shift2 = 0;
            shift3 = 0;
            shift4 = 5;
        } else {
            shift1 = 0;
            shift2 = 0;
            shift3 = 0;
            shift4 = 0;
        }
    } else {
        shift1 = 0;
        shift2 = 0;
        shift3 = 0;
        shift4 = 0;
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (x>70&&x<300){
        if (y>0.67*viewHeight&&y<=0.72*viewHeight){
            arrowPosition = viewHeight*0.7;
            currentPlaying = 0;
        } else if (y>0.72*viewHeight&&y<=0.77*viewHeight){
            arrowPosition = viewHeight*0.75;
            currentPlaying = 1;
        } else if (y>0.77*viewHeight&&y<=0.82*viewHeight){
            arrowPosition = viewHeight*0.8;
            currentPlaying = 2;
        } else if (y>0.82*viewHeight&&y<=0.87*viewHeight){
            arrowPosition = viewHeight*0.85;
            currentPlaying = 3;
        }
    }
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
