//square.h

#pragma once

#include "ofMain.h"


class Square{
public:
    
    Square();
    
    void setup();
    void update();
    void draw();
    
    bool containsPosition(float posX, float posY);
    
    
    ofColor color;
    float x, y;
    float w=50;
    float h=50;
    float alpha;
    
};

