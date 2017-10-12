//
//  particle.hpp
//  w06_h02_Fireworks
//
//  Created by Carla on 11/10/2017.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    
    Particle();    
    Particle(ofVec3f _pos);
    
    void applyForce(ofVec3f force);
    
    void update(float timeDiff); // timeDiff = time elapsed since last frame in seconds
    void draw();
    
    ofVec3f pos, vel, acc;
    
    float lifespan;	// seconds
};
