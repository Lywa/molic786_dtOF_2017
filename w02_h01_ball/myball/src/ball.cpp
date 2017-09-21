//ball.cpp

#include "ball.h"

Ball::Ball(){

    radius=10;
    
    
    color = ofColor(randomColor,randomAlpha);
    
    ofSetCircleResolution(50);
    ofEnableAntiAliasing();
    
    x=30;
    y=20;
    w=10;
    z=10;
    
    dirX=3;
    dirY=5;
}


void Ball::update(){

    x+=dirX;
    y+=dirY;
    
    
    
    if (x<=radius || x>= ofGetWidth()-radius){
        
        dirX=-2*dirX;
        
    }
    
    
    if (y<=radius || y>= ofGetHeight()-radius){
        
        dirY=-3*dirY;
        
    }

}

void Ball::draw(){
    
    ofDrawRectRounded(x, y, w, z, radius);
    ofSetColor(color);


}
