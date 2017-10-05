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

void Square::setup(){
    alpha = 255;
}

void Square::update(){
    //Should update alpha here
}

// define square
void Square::draw(){
    ofSetColor(color);
    ofDrawRectangle(x,y,w,h);
    // cout << color << endl;
}

bool Square::containsPosition(float posX, float posY){
    
    ofRectangle rect = ofRectangle(x,y,w,h);
    cout << ofToString(rect) << endl;
    cout << ofToString(rect.inside(posX, posY)) << endl;
    
    return rect.inside(posX, posY);
}
