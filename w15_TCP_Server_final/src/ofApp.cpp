#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // setup the server to listen on 11999
    TCP.setup(11999);
    lastSent = 0;
    
    tempBuff = new unsigned char[buffSize];
    
    // set document
    ofBackground(0);
    ofSetWindowTitle("SlitScan Blending");
    ofSetWindowShape(width, height);
    
    ofSetFrameRate(30);
    
    ofDisableArbTex();    // map image textures properly to of3DPrimitive meshes
    
    // Set local camera
    vid.listDevices();        // just prints all your video cameras to console
    vid.setDeviceID(0);
    
    vid.setup(width, height);    // start default cam at 640x480
    
	// Initialize received image space
	remoteImage.allocate(width, height, OF_IMAGE_COLOR);
	remoteTexture.allocate(remoteImage.getPixels());
	remoteFbo.allocate(width, height, GL_RGBA);
	remoteFbo.begin();
	ofClear(0, 0, 0, 0);
	remoteFbo.end();

    blendMode = OF_BLENDMODE_SCREEN;
}


//--------------------------------------------------------------
void ofApp::update(){
	bool remoteLineReceived = false;
    
    // TCP
	sendDataToConnectedClients();    
	for (int i = 0; i < TCP.getLastID(); i++) {
		if (!TCP.isClientConnected(i)) continue;
		int clientId = i;
		receiveFromConnectedClient(clientId, remoteLineReceived);
	}
    
	// IMAGE
    vid.update();// update web cam
    
    if (vid.isFrameNew())
    {
        // update the slit scans
        slitScan.addLine(vid.getTexture());
    }
	if (remoteLineReceived) {
		// update the second image
		
		addLineFromRemoteEnd(remoteLineNum, width, remoteLine);   
	}
}

void ofApp::receiveFromConnectedClient(int clientId, bool &remoteLineReceived)
{
	string rcvdData;

	// receive message from remote end
	int numReceivedBytes = TCP.receiveRawMsg(clientId, (char*)tempBuff, buffSize);
	int nRcvd = TCP.getNumReceivedBytes(clientId); // this is not very useful. It is larger than the explicitly sent bytes
	
	//if received something store it in a safe place.
	if (numReceivedBytes > 0) {
		for (int i = 0; i < numReceivedBytes; i++)
			// if EndOfLine is received do not store it. 
			//	THIS MIGHT BE TROUBLESOME WITH RGB(0,g,b)/RGB(r,0,b)/RGB(r,g,0)
			if (tempBuff[i] != '\0') 
				rcvdData += tempBuff[i];
		cout << endl << numReceivedBytes << " - " << nRcvd << " - ";
	}
	// if Message has the expected pattern for the upcoming line number.
	if (numReceivedBytes > 0 && rcvdData[0] == 'n') {
		string numLineS;
		for (int i = 1; i < numReceivedBytes; i++)
			numLineS += rcvdData[i];
		remoteLineNum = ofToInt(numLineS);

		cout << " next line will be: " << remoteLineNum;
	}
	// If Message is slightly longer than the expected pattern assume it is a line as long as the width of the screen:
	else if (numReceivedBytes > 6) {
		remoteLineReceived = true;

		//Convert the received rawData into ofPixels
		unsigned char *cstr = new unsigned char[rcvdData.length() + 1];
		strcpy((char*)cstr, rcvdData.c_str());
		remoteLine.setFromPixels(cstr, width, 1, OF_IMAGE_COLOR);
		delete[] cstr;
		//Some useful output...
		cout << " line " << remoteLineNum << " starts with: ";
		for (int i = 0; i < 6; i++)
			cout << +(uint8_t)rcvdData[i] << " ";
	}
}

void ofApp::sendDataToConnectedClients()
{
	// for each client lets send them a message letting them know what port they are connected on
	// we throttle the message sending frequency to once every 100ms
	uint64_t now = ofGetElapsedTimeMillis();
	if (now - lastSent >= 100) {
		for (int i = 0; i < TCP.getLastID(); i++) {
			if (!TCP.isClientConnected(i)) continue;

			TCP.send(i, "hello client - you are connected on port - " + ofToString(TCP.getClientPort(i)));
		}
		lastSent = now;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
    
	remoteFbo.draw(0, 0, width, height);
    ofEnableBlendMode(blendMode);
    slitScan.draw(0,0, width, height);
    
	//remoteTexture.draw(ofGetWidth() / 2 - width / 2, ofGetHeight() / 2 - height / 2, width, height);
    
	//printClientInfoOnScreen();
    ofDisableBlendMode();
}

void ofApp::printClientInfoOnScreen()
{
	// print useful info about server and clients  
	ofSetHexColor(0xDDDDDD);
	ofDrawBitmapString("TCP SERVER Example \n\nconnect on port: " + ofToString(TCP.getPort()), 10, 20);

	ofSetHexColor(0x000000);
	// ofDrawRectangle(10, 60, ofGetWidth()-24, ofGetHeight() - 65 - 15);

	ofSetHexColor(0xDDDDDD);
	// for each connected client lets get the data being sent and lets print it to the screen
	for (unsigned int i = 0; i < (unsigned int)TCP.getLastID(); i++) {

		if (!TCP.isClientConnected(i))continue;

		// give each client its own color
		ofSetColor(255 - i * 30, 255 - i * 20, 100 + i * 40);

		// calculate where to draw the text
		int xPos = 15;
		int yPos = 80 + (12 * i * 4);

		// get the ip and port of the client
		string port = ofToString(TCP.getClientPort(i));
		string ip = TCP.getClientIP(i);
		string info = "client " + ofToString(i) + " -connected from " + ip + " on port: " + port;
		//cout << info << endl;

		// if we don't have a string allocated yet
		// lets create one
		if (i >= storeText.size()) {
			storeText.push_back(string());
		}
	}
}

void ofApp::addLineFromRemoteEnd(int lineNum, int width, ofPixels remoteLine)
{
	for (int i = 0; i < width; i++) {
		remoteImage.setColor(i, lineNum, remoteLine.getColor(i));
	}
	remoteFbo.begin();        // draw offscreen
							   // draw a single line from the webcam image on our fbo
	remoteTexture.loadData(remoteImage.getPixels());
	//remoteTexture.drawSubsection(
	//	0, lineNum, width, 1,    // draw area (x,y,w,h)
	//	0, lineNum, width, 1    // source area
	//);
	remoteTexture.draw(0, 0, width, height);
	
	remoteFbo.end();
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
