//ball.h

#pragma once

#include "ofMain.h"


class Ball{
public:
    
    Ball();
    
    void update(ofVec2f force = ofVec2f(0,0)); // update the ball with a force each time    void draw();
    void draw();

    
    float radius =0.0;
    ofColor color;
    float x, y, w, z;
    float dirX, dirY;
    float randomColor = ofRandom(50, 255);
    float randomAlpha = ofRandom (10,100);
    float x1, x2 ;
    
    
    //adding vector for creating gravity
    ofVec2f pos;
    ofVec2f dir;
    ofVec2f acc;
            
};

