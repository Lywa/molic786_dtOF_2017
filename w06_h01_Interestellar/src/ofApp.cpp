#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowShape(750, 750);
  
   // planet.setup();
    solarsystem.setup();
    ofEnableSmoothing();
    ofSetCircleResolution(100);

    for ( int i=0 ; i <60; i++){
        
        
        float x= ofRandom(0,ofGetWidth());
        float y= ofRandom(0,ofGetHeight());
        Mover mover = Mover(ofVec3f(x,y),0.5);
        mover.color= ofColor(ofRandom((255,255,255),(120,120,120)));

        movers.push_back(mover);
            
    }
    
        
        


}

//--------------------------------------------------------------
void ofApp::update(){
    ofVec3f mousePos =ofVec3f (ofGetMouseX(),ofGetMouseY());
    
    //    for (auto & mover : movers{
    
    for ( int i=0 ; i <movers.size(); i++){
        
        ofVec3f attraction, repulsion;
        ofVec3f dir= mousePos - movers[i].pos;
        
        float dist=dir.length();
        
        if (dist<100){
            
            repulsion = dir.getNormalized() * -0.1 ;
            
            
        }
        
        else if (dist<200){
            
            attraction = dir.getNormalized() * 0.1 ;
            
            
        }
        
        movers[i].applyForce(attraction);
        movers[i].applyForce(repulsion);
        movers[i].applyDampingForce(0.05);
        movers[i].update();
        
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
     ofBackgroundGradient(ofColor(79,126,176), ofColor(0,0,0));
    
    //planet.draw();
    solarsystem.draw();
    
    for (int i=0; i< movers.size(); i++){
        
        movers[i].draw();
        
    }
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
