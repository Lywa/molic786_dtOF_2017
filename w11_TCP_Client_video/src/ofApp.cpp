#include "ofApp.h"

#define RECONNECT_TIME 400

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(20, 20, 20);
    
    imgClient.load("imgClient.jpg");
    
    
    // our send and recieve strings
    msgTx    = "";
    msgRx    = "";
    
    // connect to the server - if this fails or disconnects
    // we'll check every few seconds to see if the server exists
    tcpClient.setup("127.0.0.1", 11999);
    
    // optionally set the delimiter to something else.  The delimiter in the client and the server have to be the same
    tcpClient.setMessageDelimiter("\n");
    
    connectTime = 0;
    deltaTime = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofPixels pixelsClient = imgClient.getPixels();
    cout<< pixelsClient.getData() << endl;
    //pixelsClient.allocate(640, 480, OF_IMAGE_COLOR);
    
    img.setFromPixels(pixelsClient);
    
    if(tcpClient.isConnected()){
        // we are connected - lets try to receive from the server
        string str = tcpClient.receive();
        if( str.length() > 0 ){
            msgRx = str;
        }
    }else{
        msgTx = "";
        // if we are not connected lets try and reconnect every 5 seconds
        deltaTime = ofGetElapsedTimeMillis() - connectTime;
        
        if( deltaTime > 5000 ){
            tcpClient.setup("127.0.0.1", 11999);
            connectTime = ofGetElapsedTimeMillis();
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //ofSetColor(20, 20, 20);
    
    //imgClient.draw(0,0,640,480);
    img.draw(ofGetWidth()/2-640/2,ofGetHeight()/2-480/2,640,480);
    
    ofDrawBitmapString("openFrameworks TCP Send Image", 15, 30);
    
    if(tcpClient.isConnected()){
        if(!msgTx.empty()){
            ofDrawBitmapString("sending:", 15, 55);
            ofDrawBitmapString(msgTx, 85, 55);
        }else{
            ofDrawBitmapString("status: type something to send data to port 11999", 15, 55);
        }
        ofDrawBitmapString("from server: \n" + msgRx, 15, 270);
    }else{
        ofDrawBitmapString("status: server not found. launch server app and check ports!\n\nreconnecting in "+ofToString( (5000 - deltaTime) / 1000 )+" seconds", 15, 55);
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // you can only type if you're connected
    // we accumulate 1 line of text and send every typed character
    // on the next character after a breakline we clear the buffer
    if(tcpClient.isConnected()){
        if(key == OF_KEY_RETURN) key = '\n';
        if(key == OF_KEY_BACKSPACE || key == OF_KEY_DEL){
            if( !msgTx.empty()){
                msgTx = msgTx.substr(0, msgTx.size()-1);
            }
        }else{
            msgTx += (char) key;
        }
        tcpClient.send(msgTx);
        if (!msgTx.empty() && msgTx.back() == '\n') {
            msgTx.clear();
        }
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

