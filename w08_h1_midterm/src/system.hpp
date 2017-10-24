//
//  system.hpp
//  w08_h1_midterm
//
//  Created by Carla on 23/10/2017.
//

#pragma once
#include "Ball.h"
#include "ofMain.h"
class System {
    
public:        // other classes can access the following functions & variables:
    
    System();                // "constructor" function - required for every class
    // this is automatically called whenever we create a new ball
    
    void setup();
    void update();
    void draw();
    
    
    float radius;        // size
    float x, y;            // position
    float dirX, dirY;    // "direction" (a.k.a. velocity or speed)
    
    ofColor color;
    
    
};




vector<Ball> balls;
