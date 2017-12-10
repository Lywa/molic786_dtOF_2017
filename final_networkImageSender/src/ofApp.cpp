#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

	//Set image size
	w = 640;
	h = 480;
	size = w * h * 3;

	//Starting network
	int port = 12345;
	int packetSize = 1024;
	string addr = "127.0.0.1";

	sender.setup( addr, port, packetSize );
	lineNum = 0;
	
	//Starting camera
	grabber.setup(w,h);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	sender.update();
	
	grabber.update();	//Update grabber state
	
	if (grabber.isFrameNew()){	//Check for new frame
		
		//Send frame via network
//		unsigned char * pixels = grabber.getPixels().getData();
//		sender.send( pixels, size, lineNum );
		
		// Send single line over network
		unsigned char * pixels = grabber.getPixels().getData();
		
		int lineStartIndex = w * 3 * lineNum;
		unsigned char * line = pixels + lineStartIndex;
		
		sender.send( line, w * 3, lineNum);
		
		lineNum++;
		if (lineNum >= h) lineNum = 0;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground( 200, 255, 200 );

	//Draw camera image
	ofSetColor( 255 );
	grabber.draw( 20, 20 );
	
	//Print line num
	ofSetColor( 0 );
	ofDrawBitmapString( "Line num = " + ofToString( lineNum ), 20, h + 40 );
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}