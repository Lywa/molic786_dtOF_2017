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
    
    x = ofRandom(radius, ofGetWidth()  - radius);
    y = ofRandom(radius, ofGetHeight() - radius);
    w = ofRandom(radius, ofGetWidth()  - radius);
    z = ofRandom(radius, ofGetHeight() - radius);
    
    
    // random x and y speeds/directions between -5 and 5

    dirX= ofRandom(-5,5);
    dirY= ofRandom(-5,5);}


// update position, etc.

void Ball::update(){

    x+=dirX;
    y+=dirY;
    
    
    
    if (x<=radius || x>= ofGetWidth()-radius){
        
        dirX=-1*dirX;
        
    }
    
    
    if (y<=radius || y>= ofGetHeight()-radius){
        
        dirY=-1*dirY;
        
    }

}

// draw the square
void Ball::draw(){
    
    ofSetColor(color);
    
    ofDrawRectRounded(x, y, w, z, radius);
    


}
