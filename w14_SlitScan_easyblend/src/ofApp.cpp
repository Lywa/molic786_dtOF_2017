#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetWindowTitle("SlitScan Blending");
    ofSetWindowShape(640, 480);
    
    ofSetFrameRate(30);
    
    ofDisableArbTex();    // map image textures properly to of3DPrimitive meshes
    
    // enable web cam
    
    vid.listDevices();        // just prints all your video cameras to console
    vid.setDeviceID(0);
    vidExt.setDeviceID(1);
    
    vid.setup(640,480);    // start default cam at 640x480
    vidExt.setup(640,480);
    
    // setup the slitscan object
    
    slitScan = SlitScan(640, 480);  // create slit scan
    slitScanExt= SlitScan(640, 480);
    
    // setup the mesh
    
    mesh = ofMesh::plane(640, 480, 128, 96);
    meshExt = ofMesh::plane(640, 480, 128, 96);
    
    //
    eventString = "Screen";
    blendMode = OF_BLENDMODE_SCREEN;
    
    combinedFbo.allocate(640,480,GL_RGBA);
    combinedMesh = mesh;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    vid.update();// update web cam
    vidExt.update();
    
    if (vid.isFrameNew() || vidExt.isFrameNew())
    {
        // update the slit scans
        
        slitScan.addLine(vid.getTexture());
        slitScanExt.addLine(vidExt.getTexture());
       
    }
    
    
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableBlendMode(blendMode);
    
    slitScan.draw(0,0, 640, 480);
    slitScanExt.draw(0,0, 640, 480);
    
    ofDisableBlendMode();
    
    
   
    
    
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



