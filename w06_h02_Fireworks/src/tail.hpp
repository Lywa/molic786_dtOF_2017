//
//  tail.hpp
//  w06_h02_Fireworks
//
//  Created by Carla on 11/10/2017.
//
//


#pragma once
#include "ofMain.h"

class Tail {
    
public:
    
    Tail();
    ~Tail(){}
    
    Tail(ofVec3f _pos, float _mass);
    
    void applyForce(ofVec3f force);
    void applyDampingForce(float force);
    
    void update();
    void draw();
    
    
    ofVec3f pos, vel, acc;
    float mass;
    
};