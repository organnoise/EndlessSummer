#include "ofApp.h"
using namespace std;


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofHideCursor();
    
    rando();
    //ofSetFrameRate(24.16);
    player.load("videos/" + main);
    music.load(song);
    noise.load(sound);
    
    music.setLoop(true);
    noise.setLoop(true);
    
    current = &clip[change];
    
    player.setFrame(current->start);
    player.setLoopState(OF_LOOP_NORMAL);
    player.play();
    
    music.play();
    noise.play();
    
    music.setVolume(0.8);
    noise.setVolume(0.35);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    player.update();
    
    if(player.getCurrentFrame() == current->stop){
        
        pOrientation = current -> orientation;
        pCharacter = current -> character;
        pChange = change;
        
        while(change == pChange
              || clip[change].character == pCharacter
              || clip[change].orientation == pOrientation){
                    rando();
        }

        current = &clip[change];
        player.setFrame(current->start);
        ofBackground(0);
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    player.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
void ofApp::rando(){
    change = (int)ofRandom(15);
}

void ofApp::keyPressed(int key){
    switch (key){
            case 'f':
            ofToggleFullscreen();
            break;
    }
}
