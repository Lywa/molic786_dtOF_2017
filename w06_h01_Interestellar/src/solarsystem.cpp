//
//  solarsystem.cpp
//  w06_h01_Interestellar
//
//  Created by Carla on 11/10/2017.
//
//

#include "solarsystem.hpp"

SolarSystem::SolarSystem() {}

void SolarSystem::setup(){
    
    planet.color = ofColor(245,202,79,255);
    planet.size=20;
    planet.setup();
    
    planet2.color = ofColor(204,158,46,255);
    planet2.size= 40;
    planet2.dist= 200;
    planet2.speed=-1000;
    planet2.setup();

    planet3.setup();
    planet3.color = ofColor(255,255,255,255);
    planet3.size=5;
    planet3.dist=120;
    planet3.speed=300;
    
    planet4.color = ofColor(200,200,200);
    planet4.size= 15;
    planet4.dist=300;
    planet4.speed=-80;
    planet4.setup();
    
    
}

void SolarSystem::update(){
    
}


void SolarSystem::draw(){
    
    planet.draw();
    planet2.draw();
    planet3.draw();
    planet4.draw();
}

