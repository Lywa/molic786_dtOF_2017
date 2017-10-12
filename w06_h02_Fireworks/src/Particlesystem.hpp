//
//  Particlesystem.hpp
//  w06_h02_Fireworks
//
//  Created by Carla on 12/10/2017.
//
//

#pragma once
#include "ofMain.h"
#include "particle.hpp"


class ParticleSystem {
public:
    
    ParticleSystem();
    
    ParticleSystem(ofVec3f _pos);
    void update(ofVec3f force, float timeDiff);
    void draw();
    
    vector<Particle> particles;
    ofVec3f pos;
    
    float lifespan;
    
};
