#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
     ofSetWindowTitle("SlitScan Blending");
    
    ofBackground(0);
	// ask user for IP address and ports we'll use for connections
	
	remoteIP = ofSystemTextBoxDialog("input remote IP (ex. 127.0.0.1) - where to send our image data");
	
	string rPortStr = ofSystemTextBoxDialog("input remote port (where we'll send data)");
	remotePort = ofToInt(rPortStr);
	
	string lPortStr = ofSystemTextBoxDialog("input local port (where we'll receive image data)");
	localPort = ofToInt(lPortStr);
	
	
	// set up sender to remote IP and port
	
	sender.setup(remoteIP, remotePort);
	
	// set up receiver on local connection port
	
	receiver.setup(localPort);
	
	
	// setup webcam
	
	w = 640;
	h = 480;
	
	grabber.setup(w,h);
	lineNum = 0;
	
	bytesPerLine = w * 3;	// # bytes per line = width * num channels (RGB)
	
	
	// allocate image where we'll store the pixels from the remote, line by line
	
	remoteImg.allocate(w,h,OF_IMAGE_COLOR);
    
    
    // setup the slitscan object
    
    slitScan = SlitScan(640, 480);  // create slit scan
    
    blendMode = OF_BLENDMODE_SCREEN;

}

//--------------------------------------------------------------
void ofApp::update(){
	
	grabber.update();	// update webcam
    
    if (grabber.isFrameNew() )
    {
        // update the slit scans
        
        slitScan.addLine(grabber.getTexture());
        
    }

	
	// RECEIVE
	
	
	// Check if new frame was received automatically
	// (the receiver runs in a separate thread)
	
	if ( receiver.frame() != remoteLineNum ) {
		
		if ( receiver.size() == bytesPerLine ) {	// data size match for 1 line
			
			remoteLineNum = receiver.frame();
			// frame() returns the latest "frame ID" received (we are using this for line number ID)
			
			
			// if this was a whole image we could copy it directly:
			//		remoteImg.setFromPixels(  &receiver.data()[0], w, h, OF_IMAGE_COLOR );
			
			
			// set received data to pixels line
			
			remoteLinePix.setFromPixels( &receiver.data()[0], w, 1, 3);	// data, width, height, num channels
			
			/* -- 
			 note: receiver.data() returns a vector -
			 To get the data array at index i from a vector, you can use &vector[i]
			 -- */
			
			// copy pixel data from line pixels to ofImage:
			
			int lineStart			= remoteLineNum * bytesPerLine;		// the start index of this line in the image data
			unsigned char * imgPtr	= remoteImg.getPixels().getData() + lineStart;
			
			// copy the memory block from the line pixel data to image data
			memcpy(imgPtr, remoteLinePix.getData(), bytesPerLine);
			
			remoteImg.update();	// update the image texture
			
		}
		else if ( receiver.size() != 0 ) {
			
			cout << "ERROR: Network received data with size: " << receiver.size() << " (doesn't match bytes per line)" << endl;
		}
		
	}
	
	
	
	// SEND
	
	
	sender.update();	// tries reconnect to remote if disconnected
	
	if (grabber.isFrameNew()){	// check for new frame
		
		// send whole frame:
		
		//		unsigned char * data = grabber.getPixels().getData();
		//		int size = grabber.getPixels().getTotalBytes();
		//		sender.send( data, size, lineNum );
		
		// send current line:
		
		unsigned char * pixData = grabber.getPixels().getData();
		
		int lineStart = bytesPerLine * lineNum;			// the pixel index at start of line
		unsigned char * line = pixData + lineStart;		// pointer to that pixel
		
		sender.send( line, bytesPerLine, lineNum);		// send the data at pointer, with line size, and line number as frame ID
		
		// increment line number
		
		lineNum++;
		if (lineNum >= h) lineNum = 0;
	}
	
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	
    
    ofEnableBlendMode(blendMode);
	// draw local
	
//    ofSetColor( 200, 255, 200 );
    //ofDrawRectangle( 0,0, ofGetWidth()*.5,ofGetHeight() );
//
	// draw webcam image
    
  
    
    slitScan.draw(20,20, 640, 480);
	
	//ofSetColor( 255 );
	//grabber.draw( 20, 20 );
	
	// print local line num
	
//    ofSetColor( 0 );
//    ofDrawBitmapString( "Local line num = " + ofToString( lineNum ), 20, h + 40 );
//
//    ofDrawBitmapString( "Sending to remote IP: " + remoteIP + " : " + ofToString( remotePort ), 20, h + 60 );
	
	
//
    // draw remote

   // ofTranslate( ofGetWidth() * .5, 0 );


//    ofSetColor( 200, 200, 255 );
    //ofDrawRectangle( 0,0, ofGetWidth()*.5,ofGetHeight() );

    // draw received image
//    ofSetColor( 255 );
    remoteImg.draw( 20, 20 );

//
    // print remote line num and FPS
//    ofSetColor( 0 );
    ofDrawBitmapString( "Remote line num = " + ofToString( remoteLineNum ), 20, h + 40 );

    ofDrawBitmapString( "Receiving on local port: " + ofToString( localPort ), 20, h + 60 );

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
