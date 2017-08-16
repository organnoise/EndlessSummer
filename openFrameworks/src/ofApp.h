#pragma once

#include "ofMain.h"
#include "ofxHAPAVPlayer.h"

class ofApp : public ofBaseApp{

public:
		void setup();
		void update();
		void draw();
        void rando();
        void keyPressed(int key);
    
private:
    
    enum Orientation{
        left,
        right
    };
    
    enum Character {
        Kevin,
        Jim,
        Oz,
        Finch
    };
    
        ofxHAPAVPlayer player;
        ofSoundPlayer music;
        ofSoundPlayer noise;
    
        struct clip{
            string name;
            int start;
            int stop;
            Orientation orientation;
            Character character;
        };
    
        clip* current;
        bool reCalc;
        int change;
        int pChange;
        bool flip;
        Orientation pOrientation;
        Character pCharacter;
    

    
        string main = "theBoys_r.mov";
        string song = "InTooDeep.mp3";
        string sound = "Talking2.mp3";
        //struct for defining components of each clip
        clip clip[16] = {
                          {"Kevin_1", 0, 32, right, Kevin},
                          {"Kevin_1r", 34, 65, left, Kevin},
                          {"Kevin_2", 66, 94, left, Kevin},
                          {"Kevin_2r", 96, 122, right, Kevin},
                          {"Jim_1", 124, 166, left, Jim},
                          {"Jim_1r", 168, 209, right, Jim},
                          {"Jim_2", 211, 241, right, Jim},
                          {"Jim_2r", 243, 272, left, Jim},
                          {"Oz_1", 274, 292, left, Oz},
                          {"Oz_1r", 294, 313, right, Oz},
                          {"Oz_2", 315, 347, left, Oz},
                          {"Oz_2r", 349, 381, right, Oz},
                          {"Finch_1", 383, 445, right, Finch},
                          {"Finch_1r", 447, 508, left, Finch},
                          {"Finch_2", 510, 555, right, Finch},
                          {"Finch_2r", 557, 600, left, Finch}

                    };
    
    
    
};
