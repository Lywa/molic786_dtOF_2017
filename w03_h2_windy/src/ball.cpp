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
    
    pos.x = ofRandom(0, ofGetWidth()/2);
    pos.y = ofRandom(0, ofGetHeight()/2);
    w = ofRandom(0, ofGetWidth()/2);
    z = ofRandom(0, ofGetHeight()/2);
    
    
    // random x and y speeds/directions between -5 and 5

    dir.x= ofRandom(-5,5);
    dir.y= ofRandom(-5,5);

}


// update position, etc.

void Ball::update(ofVec2f force){

    //x+=dirX;
    //y+=dirY;
    
    acc = force;
    
    
    dir+=acc;
    
    pos+=dir;
    //cout << pos << endl;
    
    // check for bounces at edges of window:
    
    // check left
    if (pos.x <= 0) {
        pos.x = 0;			// set the position back to the edge of window
        dir.x = -.7 * dir.x;		// and reverse direction
    }
    // check right
    else if (pos.x >= ofGetWidth() - w) {
        pos.x= ofGetWidth() - w;			// similar to above
        dir.x = -.7 * dir.x; // slow down
    }
    
    // check top and bottom
    if (pos.y <= 0) {
        pos.y = 0;
        dir.y = -.7 * dir.y;
    }
    else if (pos.y >= ofGetHeight() - z) {
        pos.y = ofGetHeight() - z;
        dir.y = -.7 * dir.y;
    }

    

}

void Ball::applyForce(ofVec2f windForce){
    acc += windForce;
    dir+=acc;
    pos+=dir;
}

// draw the square
void Ball::draw(){
    
    ofSetColor(color);
    
    ofDrawRectRounded(pos.x, pos.y, w, z, radius);
    

}
