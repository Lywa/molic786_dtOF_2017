#pragma once

#include "ofMain.h"
#include "SlitScan.hpp"
#include "SlitScanExt.hpp"

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
    
    ofVideoGrabber vid;
    ofVideoGrabber vidExt;
//    RemoteVideoSource vidExt;
    
    SlitScan slitScan;
    //    SlitScanRetime slitScanRetime;
    SlitScan slitScanExt;
    
    ofMesh mesh;
    ofMesh meshExt;
    
    ofMesh combinedMesh;
    
    ofFbo combinedFbo;
    
    
    ofEasyCam cam;
    float rotation = 180;
    
    bool bDrawWireframe = false;
    bool bDrawPoints = false;
    
    
    ofBlendMode blendMode;
    string eventString;
    string timeString;
    
    ofImage screenImage; // store a "screenshot" of each frame
    
    
};

