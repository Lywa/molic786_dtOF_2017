#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofSetWindowShape(600, 750);
    
    ofBackground(255);
    
    //float red=0;
    //float green=0;
    //float blue= 0;
    
    //alpha =255;
    
    
    grid.setup();
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    grid.update();
    
    
    //    // make a ball follow the mouse
    //
    //    ofVec2f mouse;
    //    mouse.x = ofGetMouseX();
    //    mouse.y = ofGetMouseY();
    //
    //    float pct = .05; // every frame move ball 5% towards the mouse
    //
    //
    //
    //
    //    // change the ball brightness with distance
    //
    //   // float dist = mouse.distance();
    //
    //    // as distance increases, brightness increases:
    //    alpha = ofMap(mouse.x, 0, 500, 50, 255);
    //    cout << alpha << endl;
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    grid.draw();
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    grid.changeSquareAlphaAt(x, y);
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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
