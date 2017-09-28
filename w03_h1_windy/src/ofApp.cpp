#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
   
    gravity = ofVec2f(0,0); // start with no gravity force
    
    ofBackground(255);
    
    int numBalls = 1;
    
    // fill our vector
    for (int i = 0; i < numBalls; i++) {		// loop 40 times
        
        Ball tempBall;					// create a temporary ball
        balls.push_back(tempBall);		// copy the temporary ball into the balls vector
        // (push_back() adds the ball to the end of the vector, increasing the vector's size by 1)
    }
    
}


//--------------------------------------------------------------
void ofApp::update(){
    
    // mouse position alters gravity
    gravity.x = ofMap(ofGetMouseX(), 0, ofGetWidth(), -1, 1);
    gravity.y = ofMap(ofGetMouseY(), 0, ofGetHeight(), -.1, 3);
    
    
    // update each ball in our vector
    for (int i = 0; i < balls.size(); i++) {	// one way to loop through a whole vector
        
        balls[i].update(gravity);	// we can access an individual ball by its "index" number in the vector
        // e.g. balls[0] is the first ball in the vector, balls[1] is the second ball, etc.
        // (note that vectors always start at 0, not 1!!)
    }
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < balls.size(); i++) {
        
        balls[i].draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // using '+' key we add a new rectangle
    
    if ( key == '+'){
        
        Ball tempBall;					// create a temporary ball
        balls.push_back(tempBall);		// copy the temporary ball into the balls vector
        // (push_back() adds the ball to the end of the vector, increasing the vector's size by 1)
    
    
    }
    
    
     // using '-' key we erase one rectangle, in this case the first element of the vector
    if ( key == '-'){
        
        balls.erase(balls.begin());
        
    }
    
    
    // using 'e' key we erase all the rectangles, the clear refers to the size of the vector, which now is 0.
    if ( key == 'e'){
        
        balls.clear();
        
    }
    
    
    
    

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
    
    // pressing the mouse we can see a black bg

    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    // Releasing the mouse we can see a white bg again++
    ofBackground(255);
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