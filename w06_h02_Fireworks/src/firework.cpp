//
//  firework.cpp
//  w06_h02_Fireworks
//
//  Created by Carla on 11/10/2017.
//
//

#include "firework.hpp"

Firework::Firework(){

}

//--------------------------------------------------------------
void Firework::setup(){
    
    ofBackground(0);
    
    gravity = ofVec2f(0,.25);
    
    lastUpdateTime = ofGetElapsedTimef();
    
}

//--------------------------------------------------------------
void Firework::update(){
    
    // time elapsed since last frame
    float timeDiff = ofGetElapsedTimef() - lastUpdateTime;
    
    // update the particle systems
    
    for (int i=0; i<systems.size(); i++)
    {
        systems[i].update(gravity, timeDiff);	// update
    }
    
    lastUpdateTime = ofGetElapsedTimef();
    
}

//--------------------------------------------------------------
void Firework::draw(){
    
    ofBackgroundGradient(ofColor::pink, ofColor::goldenRod);
    
    for (int i=0; i<systems.size(); i++)
    {
        systems[i].draw();
    }
    
}


//--------------------------------------------------------------
void Firework::mouseReleased(int x, int y, int button){
    
    systems.push_back( ParticleSystem(ofVec2f(x,y)) );	// construct new particle system
    
}

