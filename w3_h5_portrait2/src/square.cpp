//
//  square.cpp
//  w3_h5_portrait2
//
//  Created by Carla on 01/10/2017.
//
//

#include "square.h"
#include <stdio.h>


Square::Square(){
    
    
}



void Square::update(){
    
}


// define square
void Square::draw(){
    
    
    for (int x=0; x<ofGetWidth(); x+=50){
        
        
        
        for (int y=0; y<ofGetHeight();y+=50){
            
            ofSetColor(ofColor(227,213,206));
            
            ofDrawRectangle(x,y,50,50);
            
            
            
        }
        
        
        
    }
    
    
   
    
}
