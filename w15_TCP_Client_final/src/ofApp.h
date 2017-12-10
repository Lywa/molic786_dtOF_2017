#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"
#include "SlitScan.hpp"

class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    
    ofxTCPClient tcpClient;
    string msgTx, msgRx;
    
    ofTrueTypeFont  mono;
    ofTrueTypeFont  monosm;
    
    ofImage imgClient;
    ofImage imgServer;
    //    ofImage img;
    
    //    ofPixels pixelsClient;
    
    float counter;
    int connectTime;
    int deltaTime;
    
    int size;
    
    ofVideoGrabber vid;
    
    SlitScan slitScan;
    
    ofBlendMode blendMode;
    
    
};



