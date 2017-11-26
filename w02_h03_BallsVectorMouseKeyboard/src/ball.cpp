//ball.cpp

#include "ball.h"

Ball::Ball(){

    // random radius between 2 and 10
    radius = ofRandom(2,10);
    
    
    
    // random color
    float red	= ofRandom(0,255);
    float green	= ofRandom(0,255);
    float blue	= ofRandom(0,255);
    float alpha = ofRandom(0,255);
    color = ofColor(red, green, blue, alpha);
    
    
    //Redefine edges
    ofSetCircleResolution(50);
    ofEnableAntiAliasing();
    
    x = ofRandom(0, ofGetWidth()/2);
    y = ofRandom(0, ofGetHeight()/2);
    w = ofRandom(0, ofGetWidth()/2);
    z = ofRandom(0, ofGetHeight()/2);
    
    
    // random x and y speeds/directions between -5 and 5

    dirX= ofRandom(-5,5);
    dirY= ofRandom(-5,5);}


// update position, etc.

void Ball::update(){

    x+=dirX;
    y+=dirY;
    
    
    
    if (x<=0 || x>= ofGetWidth()-w){
        dirX=-1*dirX;
    }
    
    
    if (y<=0 || y>= ofGetHeight()-z){
        dirY=-1*dirY;
    }
    

    
    
   

}

// draw the square
void Ball::draw(){
    
    ofSetColor(color);
    
    ofDrawRectRounded(x, y, w, z, radius);
    


}
