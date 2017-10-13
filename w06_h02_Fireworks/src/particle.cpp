//
//  particle.cpp
//  w06_h02_Fireworks
//
//  Created by Carla on 11/10/2017.
//
//


#include "particle.hpp"

Particle::Particle()
{
    lifespan = 1.; // seconds
}

Particle::Particle(ofVec3f _pos)
{
    pos = _pos;
    vel.x = ofRandom(-4, 4);
    vel.y = ofRandom(-1, -5);
    lifespan = 1.;
}

void Particle::applyForce(ofVec3f force){
    acc += force;
}

void Particle::update(float timeDiff){ // how much time has passed since last frame?
    vel += acc;
    pos += vel;
    acc *= 0;
    
    lifespan -= timeDiff;
    if (lifespan < 0.) lifespan = 0.;
}

void Particle::draw(){
    ofPushStyle();
    float hue = ofMap(lifespan, 0., 3., 0, 255);
    //ofSetColor(ofColor::fromHsb(hue,hue,hue));
    ofSetColor(ofColor(255));
    ofDrawRectangle(pos.x, pos.y, 1, 2);
    ofDrawCircle(pos, 1);
    ofPopStyle();
}

