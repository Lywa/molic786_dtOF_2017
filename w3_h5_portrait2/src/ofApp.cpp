#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofSetWindowShape(600, 750);
    
    ofBackground(255);
    
    //float red=0;
    //float green=0;
    //float blue= 0;
    
    alpha =255;
    
   

    for (int x=0; x<ofGetWidth(); x+=50){
        
        
        Square tempSquare; // temporary square
        grid.push_back(tempSquare);
        
        // copy the temporary square into the grid vector
        // (push_back() adds the square to the end of the vector, increasing the vector's size by 1)
        
        for (int y=0; y<ofGetHeight();y+=50){
            
            Square tempSquare;
            grid.push_back(tempSquare);
            
            // copy the temporary sqaure into the grid vector
            // (push_back() adds the squareto the end of the vector, increasing the vector's size by 1)
            
            
        }
        
        
        
    }
    
    //r= ofRandom(255);
    // g= ofRandom (255);
    //b= ofRandom(255);
    
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
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
    
    for (int i=0; i<grid.size();i++){
        
        
        
        grid[i].update();
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    for (int i=0; i<grid.size();i++){
        
        
        
        grid[i].draw();        
        
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
