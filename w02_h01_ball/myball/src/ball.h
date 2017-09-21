//ball.h

#pragma once

#include "ofMain.h"


class Ball{
public:
    
    Ball();
    
    void update();
    void draw();
    
    float radius =0.0;
    ofColor color;
    float x, y, w, z;
    float dirX, dirY;
    float randomColor = ofRandom(50, 255);
    float randomAlpha = ofRandom (10,100);
    float x1, x2 ;
    
};

