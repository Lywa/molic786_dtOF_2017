//
//  tail.cpp
//  w06_h02_Fireworks
//
//  Created by Carla on 11/10/2017.
//
//

#include "tail.hpp"

Tail::Tail()
{
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
    
    mass = ofRandom(5,10);
}

Tail::Tail(ofVec3f _pos, float _mass){
    pos = _pos;
    mass = _mass;
}

void Tail::applyForce(ofVec3f force)
{
    // force = mass * acceleration
    // acc = force / mass
    
    acc += force/mass;
}

void Tail::applyDampingForce(float force)
{
    acc -= vel.getNormalized() * force;
    // we use a "normalized" velocity (i.e. magnitude of 1)
    // because damping force should be constant
    // no matter what our velocity's magnitude (speed)
    
}

void Tail::update()
{
    vel += acc;
    pos += vel;
    
    acc *= 0;
}

void Tail::draw()
{
    ofPushStyle();
    float hue = ofMap(mass, 1, 10, 100, 150);
    ofSetColor( ofColor::fromHsb(hue, 255, 250) );
    
    ofDrawCircle(pos, mass);
    
    ofPopStyle();
}






