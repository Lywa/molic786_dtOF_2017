//
//  mover.hpp
//  w06_h01_Interestellar
//
//  Created by Carla on 11/10/2017.
//
//

#pragma once
#include "ofMain.h"

class Mover{
    
public:
    
    //constructor
    Mover();
    //destructor
    //~Mover(){}
    
    Mover (ofVec3f _pos, float mass);
    
    void update();
    void draw();
    void applyForce(ofVec3f force);
    void applyDampingForce( float force);
    
    ofVec3f pos, vel, acc;
    float mass;
    ofColor color;
    
    
    
    
    
};
