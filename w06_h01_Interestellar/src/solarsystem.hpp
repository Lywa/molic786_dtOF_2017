//
//  solarsystem.hpp
//  w06_h01_Interestellar
//
//  Created by Carla on 11/10/2017.
//
//


#pragma once
#include "ofMain.h"
#include "planet.hpp"

class SolarSystem{
    
public:
    
    SolarSystem();
    
    void setup();
    void update();
    void draw();
    
    
    ofColor color;
    float x, y;
    Planet planet;
    Planet planet2;
    Planet planet3;
    Planet planet4;
    

    
    
    
    
    
    
    
    
};
