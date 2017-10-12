//
//  mover.cpp
//  w06_h01_Interestellar
//
//  Created by Carla on 11/10/2017.
//
//

#include "ofMain.h"
#include "mover.hpp"

Mover::Mover(){
    
    pos.set(ofRandom(ofGetWidth(),ofGetHeight()));
    
    mass= ofRandom(0,10);
    
}

Mover::Mover(ofVec3f _pos, float _mass){
    
    pos = _pos;
    mass = _mass;
    
    
}

void Mover::update(){
    
    
    vel += acc;
    pos += vel;
    
    acc *= 0;
    
    
}

void Mover::applyForce(ofVec3f force){
    
    //force = mass * acceleration
    
    //acc= force / mass
    
    acc += force/ mass;
    
}

void Mover::applyDampingForce(float force){
    
    acc -= vel.getNormalized()* force;
    
    
    
}



void Mover::draw(){
    
    ofPushMatrix();
    ofTranslate(pos);
    //    ofRotate(angle);
    
    ofSetColor(color);
    ofDrawCircle(0,0, mass*2);
    
    ofPopMatrix();
    
    
    
}
