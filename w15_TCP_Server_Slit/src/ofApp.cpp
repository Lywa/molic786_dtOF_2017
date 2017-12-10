#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // setup the server to listen on 11999
    TCP.setup(11999);
    // optionally set the delimiter to something else.  The delimiter in the client and the server have to be the same, default being [/TCP]
//    TCP.setMessageDelimiter("\n");
    lastSent = 0;
    
    tempBuff = new unsigned char[buffSize];
    
    // set document

    ofBackground(0);
    ofSetWindowTitle("SlitScan Blending");
    ofSetWindowShape(640, 480);
    
    ofSetFrameRate(30);
    
    ofDisableArbTex();    // map image textures properly to of3DPrimitive meshes
    
    // Set local camera
    vid.listDevices();        // just prints all your video cameras to console
    vid.setDeviceID(0);
    
    vid.setup(640,480);    // start default cam at 640x480
    
    
    blendMode = OF_BLENDMODE_SCREEN;
}


//--------------------------------------------------------------
void ofApp::update(){
    
    
    // TCP
    
    
    // for each client lets send them a message letting them know what port they are connected on
    // we throttle the message sending frequency to once every 100ms
    uint64_t now = ofGetElapsedTimeMillis();
    if(now - lastSent >= 100){
        for(int i = 0; i < TCP.getLastID(); i++){
            if( !TCP.isClientConnected(i) ) continue;
            
            
            TCP.send(i, "hello client - you are connected on port - "+ofToString(TCP.getClientPort(i)) );
        }
        lastSent = now;
    }
    
    for(int i = 0; i < TCP.getLastID(); i++){
        if( !TCP.isClientConnected(i) ) continue;
        
        
        int clientId=i;
        
        
//        TCP.receiveRawBytes(clientId, (char*)tempBuff, buffSize);
//
//        //    same as this:
//        //    TCP.receiveRawBytes(clientId, (char*)img.getPixels().getData(), img.getPixels().getTotalBytes());
//
//        int nRcvd = TCP.getNumReceivedBytes(clientId);
//        //cout<<nRcvd<<endl;
//
//        if (nRcvd==buffSize)
//            texture.loadData(tempBuff, 320, 240, GL_RGB);

        
//        ___________
        
//        string rcvd_msg = TCP.receive(clientId);
//        int lineN= ofToInt(rcvd_msg);
//        cout<<lineN<<endl;
//
//        TCP.receiveRawBytes(clientId,(char*)tempBuff2,buffSize2);
//        cout<<TCP.getNumReceivedBytes(clientId)<<endl;
//        __________
//
        
        TCP.receiveRawBytes(clientId,(char*) tempBuff3,buffSize3);
        cout<<tempBuff3<<endl;
        
    }
    
    
    
    vid.update();// update web cam
    
    if (vid.isFrameNew())
    {
        // update the slit scans
        
        slitScan.addLine(vid.getTexture());
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableBlendMode(blendMode);
    
    slitScan.draw(0,0, 640, 480);
    
    
   
    
    // TCP
    
    
    //ofSetHexColor(0xDDDDDD);
    ofDrawBitmapString("TCP SERVER Example \n\nconnect on port: "+ofToString(TCP.getPort()), 10, 20);
    
    //ofSetHexColor(0x000000);
    // ofDrawRectangle(10, 60, ofGetWidth()-24, ofGetHeight() - 65 - 15);
    
    //ofSetHexColor(0xDDDDDD);
    
    // for each connected client lets get the data being sent and lets print it to the screen
    for(unsigned int i = 0; i < (unsigned int)TCP.getLastID(); i++){
        
        if( !TCP.isClientConnected(i) )continue;
        
        //        // print image:
        //        ofPixels img;
        //
        //        img.allocate(640, 480, GL_RGBA);
        //
        //        img.set(tempBuff);
        
        //        cout<<sizeof(tempBuff)<< endl;
        //
        //        ofImage newImage;
        //        newImage.setFromPixels(img);
        //        newImage.allocate(640, 480,OF_IMAGE_COLOR_ALPHA);
        //
        //        newImage.draw(ofGetWidth()/2-640/2,ofGetHeight()/2-480/2,640,480);
        
        
        texture.draw(ofGetWidth()/2-640/2,ofGetHeight()/2-480/2,640,480);
        
        // give each client its own color
//        ofSetColor(255 - i*30, 255 - i * 20, 100 + i*40);
        
        // calculate where to draw the text
        int xPos = 15;
        int yPos = 80 + (12 * i * 4);
        
        // get the ip and port of the client
        string port = ofToString( TCP.getClientPort(i) );
        string ip   = TCP.getClientIP(i);
        string info = "client "+ofToString(i)+" -connected from "+ip+" on port: "+port;
        
        
        // if we don't have a string allocated yet
        // lets create one
        if(i >= storeText.size() ){
            storeText.push_back( string() );
        }
        
        // receive all the available messages, separated by \n
        // and keep only the last one
        string str;
        string tmp;
        do{
            str = tmp;
            tmp = TCP.receive(i);
        }while(tmp!="");
        
        // if there was a message set it to the corresponding client
        if(str.length() > 0){
            storeText[i] = str;
        }
        
        // draw the info text and the received text bellow it
        ofDrawBitmapString(info, xPos, yPos);
        ofDrawBitmapString(storeText[i], 25, yPos + 20);
        
    }
    
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
