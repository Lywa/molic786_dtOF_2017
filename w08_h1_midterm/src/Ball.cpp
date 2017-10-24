#include "Ball.h"

// constructor
Ball::Ball() {
    
    // inside the constructor you initialize the object's variables
    
    // random radius between 10 and 50
    radius = ofRandom(50,100);
    
    // random color
    float red    = ofRandom(0,255);
    float green    = ofRandom(0,255);
    float blue    = ofRandom(0,255);
    color = ofColor(red, green, blue);
    
    // random position in window
    x = ofRandom(radius, ofGetWidth()  - radius);
    y = ofRandom(radius, ofGetHeight() - radius);
    
    // random x and y speeds/directions between -10 and 10
    dirX = ofRandom(-2,2);
    dirY = ofRandom(-2,2);
}

// update position, etc.
void Ball::update() {
    
    x+=dirX;    // move along x by amount of dirX
    y+=dirY;    // move along y by amount of dirY
    
    // check for bounces at edges of window:
    
    // check left
    if (x <= radius) {
        x = radius;            // set the position back to the edge of window
        dirX = -dirX;        // and reverse direction
    }
    // check right
    else if (x >= ofGetWidth() - radius) {
        x = ofGetWidth() - radius;            // similar to above
        dirX = -dirX;
    }
    
    // check top and bottom
    if (y <= radius) {
        y = radius;
        dirY = -dirY;
    }
    else if (y >= ofGetHeight() - radius) {
        y = ofGetHeight() - radius;
        dirY = -dirY;
    }
    
    drawLines();
}


// draw the ball
void Ball::draw() {
    
    ofSetColor(color);
    ofDrawLine(x,y,radius+ofGetWidth()/2,radius+ofGetHeight()/2);// set the GLOBAL color
    ofDrawCircle(x,y, radius/10);        // and drawç
    ofDrawCircle(radius+ofGetWidth()/2,radius+ofGetHeight()/2, radius/10);
    drawLines();
    
}

void Ball::drawLines(){
    
    //ofSetColor(255);
    ofDrawLine(x,y,radius+ofGetWidth()/2,radius+ofGetHeight()/2);
    int _x = x + ofDist(x, y,radius+ofGetWidth()/2,radius+ofGetHeight()/2)/2;
    int _y = y - ofDist(x, y,radius+ofGetWidth()/2,radius+ofGetHeight()/2)/2;
    ofDrawCircle(x,y, radius/10);
    ofDrawLine(_x,_y ,x,y);
    ofSetColor(color);
    ofDrawCircle(_x,_y, radius/10);
    //ofSetColor(255);
    int _x2 = _x +ofDist(_x,_y,radius+ofGetWidth()/2,radius+ofGetHeight()/2)/2;
    int _y2 = _y+ofDist(_x,_y,radius+ofGetWidth()/2,radius+ofGetHeight()/2)/2;
    
    ofDrawLine(_x2,_y2,x,y);
    //ofSetColor(color);
    ofDrawCircle(_x2,_y2, radius/10);
   
    
    
    
}



