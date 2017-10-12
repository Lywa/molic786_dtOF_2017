#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowShape(750, 750);
  
   // planet.setup();
    solarsystem.setup();
    ofEnableSmoothing();
    ofSetCircleResolution(100);

    
    
    // create particles
    for ( int i=0 ; i <600; i++){
        
        
        float x= ofRandom(0,ofGetWidth());
        float y= ofRandom(0,ofGetHeight());
        Mover mover = Mover(ofVec3f(x,y),0.5);
        mover.color= ofColor(ofRandom((255,255,255),(120,120,120)));

        movers.push_back(mover);
            
    }
    
    //create asteroids
    for (int i = 0; i < numAsteroids; i++) {
        Asteroids asteroids_tmp = Asteroids();
        asteroids_tmp.setup();
        asteroids.push_back(asteroids_tmp);
    }
    blackhole.mass = 0;
    blackhole.color = ofColor(255, 0, 255);
    

        


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
    
    
    
    float attractionStrength = blackhole.mass/10000;
    float dampingStrength = 0.1;
    
    // update spatial_bodies[i] 1 - small mass
    
    for (int i = 0; i < asteroids.size(); i++) {
        
        ofVec3f dir1 = blackhole.pos - asteroids[i].pos;	// black_hole is target
        ofVec3f attraction1 = dir1 * attractionStrength;
        
        
        asteroids[i].applyForce(attraction1);
        asteroids[i].applyDampingForce(dampingStrength);
        asteroids[i].update();
    }
    blackhole.update();
    


}

//--------------------------------------------------------------
void ofApp::draw(){
    
     ofBackgroundGradient(ofColor(79,126,176), ofColor(0,0,0));
    
    //planet.draw();
    solarsystem.draw();
    
    for (int i=0; i< movers.size(); i++){
        
        movers[i].draw();
        
    }
    
    drawBlackholes();
    drawAsteroids();
    
}


void ofApp::drawBlackholes()
{
    blackhole.color= ofColor(0);
    blackhole.draw();
}

void ofApp::drawAsteroids() {
    for (int i = 0; i < asteroids.size(); i++)
    {
        asteroids[i].draw();
    }
}

void ofApp::relocateAsteroids() {
    for (int i = 0; i < asteroids.size(); i++)
    {
        asteroids[i].pos = ofVec3f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
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
    blackHoleOpen= true;
    
    
    blackhole.mass = ofMap(ofGetMouseX(),0, ofGetWidth(), 1, 100);
    blackhole.pos = ofVec3f(x, y);

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    
    blackHoleOpen= false;
    
    
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
