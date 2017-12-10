#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"
#include "SlitScan.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
	void receiveFromConnectedClient(int clientId, bool &remoteLineReceived);
	void sendDataToConnectedClients();
    void draw();

	void printClientInfoOnScreen();

	void addLineFromRemoteEnd(int lineNum, int width, ofPixels remoteLine);
    
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
    
    ofxTCPServer TCP;
    ofxTCPClient tcpClient;
    
	int remoteLineNum;
	ofPixels remoteLine;
	ofImage remoteImage;
    char pixelsClient;
    unsigned char* tempBuff;

	int width = 640;
	int height = 480;

    int buffSize = width*height*3;


	ofFbo remoteFbo;
    ofTexture remoteTexture;
    
    vector <string> storeText;
    uint64_t lastSent;
    
    string eventString;
    string timeString;
    
    ofVideoGrabber vid;
    
    SlitScan slitScan;
    
    ofBlendMode blendMode;

};
