#include "ofApp.h"
#include "ball.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    /*for (int i= 0; i<NBALLS; i++){
     
     myBall[i].setup();
     
     }*/
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ball.update();
    ball2.update();
    
    /*for (int i= 0; i<NBALLS; i++){
     
     myBall[i].update();
     
     }*/
    
}



//--------------------------------------------------------------
void ofApp::draw(){
    
    ball.draw();
    ball2.draw();
    
    /*for (int i= 0; i<NBALLS; i++){
     
     myBall[i].draw();
     
     }*/
    
   

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
