//
//  system.cpp
//  w08_h1_midterm
//
//  Created by Carla on 23/10/2017.
//

#include "system.hpp"

System::System(){
    
    
}
void System::setup(){
    
    int numBalls = 5;
    
    // fill our vector
    for (int i = 0; i < numBalls; i++) {
        balls.push_back(Ball());
    }
    
}

//--------------------------------------------------------------
void System::update(){
    
    for (int i = 0; i < balls.size(); i++) {
        balls[i].update();
    }
}

//--------------------------------------------------------------
void System::draw(){
    
    
    for (int i = 0; i < balls.size(); i++) {
        balls[i].draw();
    }
   
    
}
