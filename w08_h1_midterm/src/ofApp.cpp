#include "ofApp.h"

//--------------------------------------------------------------


void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
    ofBackground(0);
    
    int numBalls = 15;
    
    // fill our vector
    for (int i = 0; i < numBalls; i++) {
        balls.push_back(Ball());
    }
    
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    int baud = 9600;
    serial.setup(1, 9600); //open the first device and talk to it at 57600 baud
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < balls.size(); i++) {
        balls[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < balls.size(); i++) {
        balls[i].draw();
    }
    
    // now, take a "screenshot" of the frame
    screenImage.grabScreen(0,0,ofGetWidth(),ofGetHeight());
    
    // resize the screenshot to 10x10 pixelsçç
    
    int nCols = 5;
    // int nCols = 10;
    int nRows = 10;
    // int nRows
    
    screenImage.resize(nCols,nRows);
    
    
    // sample colors from the screenshot, and draw as a grid overlay:
    
    // overlay opacity based on mouse x
    float alpha = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255, true);
    
    ofSetColor(0, alpha);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());    // draw black rect to clear screen
    
    
    
    
    
    // grid square size for drawing:
    float width = ofGetWidth() / (float)nCols;
    float height = ofGetHeight() / (float)nRows;
    
    
    //    serial.writeByte('G');
    //    serial.writeByte('B');
    
//    serial.writeByte(0);
//    serial.writeByte(255);
//    serial.writeByte(0);
//    serial.writeByte(0);
//
    
    for (int y=0; y<nRows; y++) {
        for (int x=0; x<nCols; x++) {
            
            // sample the color of the screenshot at this grid pos
            ofColor color = screenImage.getColor(x,y);
            color.a = alpha;
            
            // draw a rectangle on screen
            
            ofSetColor(color);
            ofDrawRectangle(x * width, y * height, width, height);
            
            /*
             add serial data send code here
             */
            int pixelNum = y * nCols + x;
            
            int r = color.r;
            int g = color.g;
            int b = color.b;
            
            if (color.r > 254)
                r = 254;
            if (color.g > 254)
                g = 254;
            if (color.b > 254)
                b = 254;
            serial.writeByte(255);
            serial.writeByte(pixelNum);
            serial.writeByte(r);
            serial.writeByte(g);
            serial.writeByte(b);

            
            unsigned char byte_back = 0;
            byte_back = serial.readByte();
            if ( byte_back == OF_SERIAL_ERROR )
                printf("an error occurred");
            else
                printf("arduino sent is %d", byte_back);
        }
    }
    //serial.writeByte(400);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if ( key == '+'){
        
        Ball tempBall;                    // create a temporary ball
        balls.push_back(tempBall);        // copy the temporary ball into the balls vector
        // (push_back() adds the ball to the end of the vector, increasing the vector's size by 1)
        
        
    }
    
    // using '-' key we erase one rectangle, in this case the first element of the vector
    if ( key == '-'){
        
        balls.erase(balls.begin());
        
    }
    
    if ( key == '1'){
        
        for (int i=0; i<balls.size(); i++)
        {
            balls[i].radius =  0;
            
        }
        
    }
    
    if ( key == '2'){
        
        for (int i=0; i<balls.size(); i++)
        {
            balls[i].radius =  50;
            
        }
        
    }
    
    if ( key == '3'){
        
        for (int i=0; i<balls.size(); i++)
        {
            balls[i].radius =  100;
            
        }
        
    }
    
    if ( key == '4'){
        
        for (int i=0; i<balls.size(); i++)
        {
            balls[i].radius =  150;
            
        }
        
    }
    if ( key == '5'){
        
        for (int i=0; i<balls.size(); i++)
        {
            balls[i].radius =  200;
            
        }
        
    }
    
    if ( key == '6'){
        
        for (int i=0; i<balls.size(); i++)
        {
            balls[i].radius =  250;
            
        }
        
    }
    if ( key == '7'){
        
        for (int i=0; i<balls.size(); i++)
        {
            balls[i].radius =  300;
            
        }
        
    }
    
    if ( key == '8'){
        
        for (int i=0; i<balls.size(); i++)
        {
            balls[i].radius =  350;
            
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
    for (int i=0; i<balls.size(); i++)
    {
        //        balls[i].x =  ofGetMouseX();
        //        balls[i].y =  ofGetMouseY();
        
        balls[i].color.set(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
        
    }
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
