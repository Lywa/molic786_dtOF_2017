#include "ofApp.h"




//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1200, 1200);
    ofSetFrameRate(30);
    //ofBackground(255, 255, 255);
    ofSetBackgroundAuto(0);
    
    ofBackground(255);
    ofEnableSmoothing();
    ofSetCircleResolution(40);
    
    halfHeight = ofGetHeight()/2.0;
    color.set(79,113, 217, 10);
}

//--------------------------------------------------------------
void ofApp::update(){
    // Move the X position of the circle with a constant speed
    
    float x;
    x+=0.2;
    
    float MousePosX = ofGetMouseX();
    float MousePosY = ofGetMouseY();
 
    posX += 5.5+x;
    amplitude += 0.3;
    
    
    
    
    // Calculate posY using cos
    posY = halfHeight + cos( ofGetElapsedTimef()*4 ) * amplitude;
    
    // reset posX when posX --> Width
    if(posX > ofGetWidth() + radius) {
        posX = -radius;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofSetColor(color);
    ofDrawCircle(ofGetWidth()-posX*2, posY-600, radius*2);
    
    ofSetColor(ofColor(93,190,187,10));
    ofDrawCircle(posX-300, posY-400, radius*2);
    
    ofSetColor(ofColor(92,159,190,10));
    ofDrawCircle(ofGetWidth()-posX, posY-150, radius);
    
    ofSetColor(ofColor(93,190,187,10));
    ofDrawCircle(posX-100, posY-40, radius/0,5);
    
    
    
    ofSetColor(ofColor(255,255,255,5));
    ofDrawCircle(ofGetWidth()- posX, posY-300, radius);
    
    ofSetColor(color);
    ofDrawCircle(posX, posY, radius);
    
    ofSetColor(ofColor(255,255,255,10));
    ofDrawCircle(ofGetWidth()-posX-100, posY+50, radius/1.5);
    
    
    ofSetColor(ofColor(92,159,190,10));
    ofDrawCircle(posX-200, posY+100, radius/2);
    
    
    ofSetColor(ofColor(93,190,187,10));
    ofDrawCircle(posX-300, posY+300, radius*2);
    
    
    ofSetColor(color);
    ofDrawCircle(ofGetWidth()-posX*2, posY+400, radius*2);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    

    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    
   
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    ofSetColor(255,255, 255);
    ofDrawRectangle(0,0,1200,1200);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
