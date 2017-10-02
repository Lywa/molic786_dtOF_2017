#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowShape(600, 750);
    
    
   // color = ofColor(red,green, blue, alpha);
    
    
    ofBackground(255);
    
    //float red=0;
    //float green=0;
    //float blue= 0;

    alpha =255;
    
    

}

//--------------------------------------------------------------
void ofApp::update(){

    ofVec2f mouse;
    mouse.x = ofGetMouseX();
    mouse.y = ofGetMouseY();
    
    float pct= .1;
    
    // change the ball brightness with distance
    
    
    
    
    
    // as distance increases, brightness increases:
    alpha = ofMap(0.1, mouse.x, mouse.y, 0, 255);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //1ST ROW
    
    //1
    ofSetColor(ofColor(227,213,206,alpha));
    ofDrawRectangle(0,0,50,50);
    //2
    ofSetColor(ofColor(225,210,203,alpha));
    ofDrawRectangle(50,0,50,50);
    
    //3
    ofSetColor(ofColor(226,211,204,alpha));
    ofDrawRectangle(100,0,50,50);
    
    //4
    ofSetColor(ofColor(220,201,197,alpha));
    ofDrawRectangle(150,0,50,50);
    //5
    ofSetColor(ofColor(181,147,156,alpha));
    ofDrawRectangle(200,0,50,50);
    
    //6
    ofSetColor(ofColor(220,201,197,alpha));
    ofDrawRectangle(250,0,50,50);
    
    //7
    ofSetColor(ofColor(229,215,207,alpha));
    ofDrawRectangle(300,0,50,50);
    
    //8
    ofSetColor(ofColor(230,216,207,alpha));
    ofDrawRectangle(350,0,50,50);
    
    //9
    ofSetColor(ofColor(231,217,207,alpha));
    ofDrawRectangle(400,0,50,50);
    
    //10
    ofSetColor(ofColor(235,217,209,alpha));
    ofDrawRectangle(450,0,50,50);
    
    //11
    ofSetColor(ofColor(236,220,207,alpha));
    ofDrawRectangle(500,0,50,50);
    
    //12
    ofSetColor(ofColor(237,220,209,alpha));
    ofDrawRectangle(550,0,50,50);
    
    
    //ofSetColor(ofColor(237,221,209,alpha));
    //ofDrawRectangle(600,0,50,50);
    
    
    // 2ND ROW
    
  
    
    //1
    ofSetColor(ofColor(228,214,207,alpha));
    ofDrawRectangle(0,50,50,50);
    
    //2
    ofSetColor(ofColor(226,211,204,alpha));
    ofDrawRectangle(50,50,50,50);
    
    //3
    ofSetColor(ofColor(185,155,160,alpha));
    ofDrawRectangle(100,50,50,50);
    
    //4
    ofSetColor(ofColor(102,49,80,alpha));
    ofDrawRectangle(150,50,50,50);
    
    //5
    ofSetColor(ofColor(87,37,69,alpha));
    ofDrawRectangle(200,50,50,50);
    
    //6
    ofSetColor(ofColor(115,72,91,alpha));
    ofDrawRectangle(250,50,50,50);
    
    //7
    ofSetColor(ofColor(229,215,206,alpha));
    ofDrawRectangle(300,50,50,50);
    
    //8
    ofSetColor(ofColor(223,207,200,alpha));
    ofDrawRectangle(350,50,50,50);
    
    //9
    ofSetColor(ofColor(156,108,126,alpha));
    ofDrawRectangle(400,50,50,50);
    //10
    ofSetColor(ofColor(142,93,113,alpha));
    ofDrawRectangle(450,50,50,50);
    
    //11
    ofSetColor(ofColor(236,220,207,alpha));
    ofDrawRectangle(500,50,50,50);
    
    //12
    ofSetColor(ofColor(237,221,208,alpha));
    ofDrawRectangle(550,50,50,50);
    
    
    
    // 3rd ROW
    
    
    
    //1
    ofSetColor(ofColor(230,217,210,alpha));
    ofDrawRectangle(0,100,50,50);
    
    //2
    ofSetColor(ofColor(226,211,204,alpha));
    ofDrawRectangle(50,100,50,50);
    
    //3
    ofSetColor(ofColor(128,82,102,alpha));
    ofDrawRectangle(100,100,50,50);
    
    //4
    ofSetColor(ofColor(82,34,64,alpha));
    ofDrawRectangle(150,100,50,50);
    
    //5
    ofSetColor(ofColor(85,36,66,alpha));
    ofDrawRectangle(200,100,50,50);
    
    //6
    ofSetColor(ofColor(93,38,70,alpha));
    ofDrawRectangle(250,100,50,50);
    
    //7
    ofSetColor(ofColor(218,200,195,alpha));
    ofDrawRectangle(300,100,50,50);
    
    //8
    ofSetColor(ofColor(148,97,114,alpha));
    ofDrawRectangle(350,100,50,50);
    
    //9
    ofSetColor(ofColor(90,35,68,alpha));
    ofDrawRectangle(400,100,50,50);
    //10
    ofSetColor(ofColor(111,48,84,alpha));
    ofDrawRectangle(450,100,50,50);
    
    //11
    ofSetColor(ofColor(225,206,194,alpha));
    ofDrawRectangle(500,100,50,50);
    
    //12
    ofSetColor(ofColor(236,220,205,alpha));
    ofDrawRectangle(550,100,50,50);
    
    // 4th ROW
    
    
    
    //1
    ofSetColor(ofColor(231,218,212,alpha));
    ofDrawRectangle(0,150,50,50);
    
    //2
    ofSetColor(ofColor(226,211,204,alpha));
    ofDrawRectangle(50,150,50,50);
    
    //3
    ofSetColor(ofColor(129,80,103,alpha));
    ofDrawRectangle(100,150,50,50);
    
    //4
    ofSetColor(ofColor(90,37,69,alpha));
    ofDrawRectangle(150,150,50,50);
    
    //5
    ofSetColor(ofColor(80,35,63,alpha));
    ofDrawRectangle(200,150,50,50);
    
    //6
    ofSetColor(ofColor(86,41,68,alpha));
    ofDrawRectangle(250,150,50,50);
    
    //7
    ofSetColor(ofColor(150,105,124,alpha));
    ofDrawRectangle(300,150,50,50);
    
    //8
    ofSetColor(ofColor(87,36,66,alpha));
    ofDrawRectangle(350,150,50,50);
    
    //9
    ofSetColor(ofColor(83,35,64,alpha));
    ofDrawRectangle(400,150,50,50);
    //10
    ofSetColor(ofColor(95,38,74,alpha));
    ofDrawRectangle(450,150,50,50);
    
    //11
    ofSetColor(ofColor(187,152,154,alpha));
    ofDrawRectangle(500,150,50,50);
    
    //12
    ofSetColor(ofColor(236,219,205,alpha));
    ofDrawRectangle(550,150,50,50);
   
    
    // 5th ROW
    
    
    
    //1
    ofSetColor(ofColor(232,219,214,alpha));
    ofDrawRectangle(0,200,50,50);
    
    //2
    ofSetColor(ofColor(226,211,204,alpha));
    ofDrawRectangle(50,200,50,50);
    
    //3
    ofSetColor(ofColor(131,94,110,alpha));
    ofDrawRectangle(100,200,50,50);
    
    //4
    ofSetColor(ofColor(66,34,54,alpha));
    ofDrawRectangle(150,200,50,50);
    
    //5
    ofSetColor(ofColor(60,34,45,alpha));
    ofDrawRectangle(200,200,50,50);
    
    //6
    ofSetColor(ofColor(66,41,46,alpha));
    ofDrawRectangle(250,200,50,50);
    
    //7
    ofSetColor(ofColor(68,41,48,alpha));
    ofDrawRectangle(300,200,50,50);
    
    //8
    ofSetColor(ofColor(56,30,42,alpha));
    ofDrawRectangle(350,200,50,50);
    
    //9
    ofSetColor(ofColor(80,33,60,alpha));
    ofDrawRectangle(400,200,50,50);
    //10
    ofSetColor(ofColor(96,40,73,alpha));
    ofDrawRectangle(450,200,50,50);
    
    //11
    ofSetColor(ofColor(196,168,165,alpha));
    ofDrawRectangle(500,200,50,50);
    
    //12
    ofSetColor(ofColor(237,221,206,alpha));
    ofDrawRectangle(550,200,50,50);
    
    
    // 6TH ROW
    
    
    
    //1
    ofSetColor(ofColor(231,219,215,alpha));
    ofDrawRectangle(0,250,50,50);
    
    //2
    ofSetColor(ofColor(224,209,204,alpha));
    ofDrawRectangle(50,250,50,50);
    
    //3
    ofSetColor(ofColor(169,151,149,alpha));
    ofDrawRectangle(100,250,50,50);
    
    //4
    ofSetColor(ofColor(64,44,47,alpha));
    ofDrawRectangle(150,250,50,50);
    
    //5
    ofSetColor(ofColor(94,65,62,alpha));
    ofDrawRectangle(200,250,50,50);
    
    //6
    ofSetColor(ofColor(177,130,113,alpha));
    ofDrawRectangle(250,250,50,50);
    
    //7
    ofSetColor(ofColor(173,128,113,alpha));
    ofDrawRectangle(300,250,50,50);
    
    //8
    ofSetColor(ofColor(114,79,72,alpha));
    ofDrawRectangle(350,250,50,50);
    
    //9
    ofSetColor(ofColor(77,36,54,alpha));
    ofDrawRectangle(400,250,50,50);
    //10
    ofSetColor(ofColor(121,74,91,alpha));
    ofDrawRectangle(450,250,50,50);
    
    //11
    ofSetColor(ofColor(234,218,204,alpha));
    ofDrawRectangle(500,250,50,50);
    
    //12
    ofSetColor(ofColor(237,221,207,alpha));
    ofDrawRectangle(550,250,50,50);
    
    
    // 7TH ROW
    
    
    
    //1
    ofSetColor(ofColor(231,220,217,alpha));
    ofDrawRectangle(0,300,50,50);
    
    //2
    ofSetColor(ofColor(231,220,217,alpha));
    ofDrawRectangle(50,300,50,50);
    
    //3
    ofSetColor(ofColor(122,103,101,alpha));
    ofDrawRectangle(100,300,50,50);
    
    //4
    ofSetColor(ofColor(78,54,52,alpha));
    ofDrawRectangle(150,300,50,50);
    
    //5
    ofSetColor(ofColor(184,138,120,alpha));
    ofDrawRectangle(200,300,50,50);
    
    //6
    ofSetColor(ofColor(218,165,141,alpha));
    ofDrawRectangle(250,300,50,50);
    
    //7
    ofSetColor(ofColor(230,179,151,alpha));
    ofDrawRectangle(300,300,50,50);
    
    //8
    ofSetColor(ofColor(228,177,145,alpha));
    ofDrawRectangle(350,300,50,50);
    
    //9
    ofSetColor(ofColor(149,111,101,alpha));
    ofDrawRectangle(400,300,50,50);
    //10
    ofSetColor(ofColor(210,185,177,alpha));
    ofDrawRectangle(450,300,50,50);
    
    //11
    ofSetColor(ofColor(235,220,206,alpha));
    ofDrawRectangle(500,300,50,50);
    
    //12
    ofSetColor(ofColor(237,222,209,alpha));
    ofDrawRectangle(550,300,50,50);
    
    // 8TH ROW
    
    
    
    //1
    ofSetColor(ofColor(232,221,219,alpha));
    ofDrawRectangle(0,350,50,50);
    
    //2
    ofSetColor(ofColor(224,209,204,alpha));
    ofDrawRectangle(50,350,50,50);
    
    //3
    ofSetColor(ofColor(110,90,89,alpha));
    ofDrawRectangle(100,350,50,50);
    
    //4
    ofSetColor(ofColor(85,60,58,alpha));
    ofDrawRectangle(150,350,50,50);
    
    //5
    ofSetColor(ofColor(196,150,128,alpha));
    ofDrawRectangle(200,350,50,50);
    
    //6
    ofSetColor(ofColor(213,161,138,alpha));
    ofDrawRectangle(250,350,50,50);
    
    //7
    ofSetColor(ofColor(221,167,138,alpha));
    ofDrawRectangle(300,350,50,50);
    
    //8
    ofSetColor(ofColor(225,172,142,alpha));
    ofDrawRectangle(350,350,50,50);
    
    //9
    ofSetColor(ofColor(202,165,141,alpha));
    ofDrawRectangle(400,350,50,50);
    //10
    ofSetColor(ofColor(236,220,206,alpha));
    ofDrawRectangle(450,350,50,50);
    
    //11
    ofSetColor(ofColor(238,223,209,alpha));
    ofDrawRectangle(500,350,50,50);
    
    //12
    ofSetColor(ofColor(242,226,212,alpha));
    ofDrawRectangle(550,350,50,50);
    
    
    // 9TH ROW
    
    
    
    //1
    ofSetColor(ofColor(231,222,219,alpha));
    ofDrawRectangle(0,400,50,50);
    
    //2
    ofSetColor(ofColor(210,197,195,alpha));
    ofDrawRectangle(50,400,50,50);
    
    //3
    ofSetColor(ofColor(165,126,119,alpha));
    ofDrawRectangle(100,400,50,50);
    
    //4
    ofSetColor(ofColor(120,88,81,alpha));
    ofDrawRectangle(150,400,50,50);
    
    //5
    ofSetColor(ofColor(135,100,90,alpha));
    ofDrawRectangle(200,400,50,50);
    
    //6
    ofSetColor(ofColor(99,67,63,alpha));
    ofDrawRectangle(250,400,50,50);
    
    //7
    ofSetColor(ofColor(181,131,111,alpha));
    ofDrawRectangle(300,400,50,50);
    
    //8
    ofSetColor(ofColor(95,65,61,alpha));
    ofDrawRectangle(350,400,50,50);
    
    //9
    ofSetColor(ofColor(152,117,103,alpha));
    ofDrawRectangle(400,400,50,50);
    //10
    ofSetColor(ofColor(213,195,181,alpha));
    ofDrawRectangle(450,400,50,50);
    
    //11
    ofSetColor(ofColor(240,225,211,alpha));
    ofDrawRectangle(500,400,50,50);
    
    //12
    ofSetColor(ofColor(245,228,215,alpha));
    ofDrawRectangle(550,400,50,50);
    
    
    // 10TH ROW
    
    
    
    //1
    ofSetColor(ofColor(229,220,219,alpha));
    ofDrawRectangle(0,450,50,50);
    
    //2
    ofSetColor(ofColor(206,194,192,alpha));
    ofDrawRectangle(50,450,50,50);
    
    //3
    ofSetColor(ofColor(190,165,160,alpha));
    ofDrawRectangle(100,450,50,50);
    
    //4
    ofSetColor(ofColor(165,123,108,alpha));
    ofDrawRectangle(150,450,50,50);
    
    //5
    ofSetColor(ofColor(187,138,122,alpha));
    ofDrawRectangle(200,450,50,50);
    
    //6
    ofSetColor(ofColor(160,111,98,alpha));
    ofDrawRectangle(250,450,50,50);
    
    //7
    ofSetColor(ofColor(148,106,94,alpha));
    ofDrawRectangle(300,450,50,50);
    
    //8
    ofSetColor(ofColor(170,123,106,alpha));
    ofDrawRectangle(350,450,50,50);
    
    //9
    ofSetColor(ofColor(210,173,153,alpha));
    ofDrawRectangle(400,450,50,50);
    //10
    ofSetColor(ofColor(220,202,189,alpha));
    ofDrawRectangle(450,450,50,50);
    
    //11
    ofSetColor(ofColor(243,226,213,alpha));
    ofDrawRectangle(500,450,50,50);
    
    //12
    ofSetColor(ofColor(245,229,216,alpha));
    ofDrawRectangle(550,450,50,50);
    
    
    // 11TH ROW
    
    
    
    //1
    ofSetColor(ofColor(228,221,219,alpha));
    ofDrawRectangle(0,500,50,50);
    
    //2
    ofSetColor(ofColor(205,193,192,alpha));
    ofDrawRectangle(50,500,50,50);
    
    //3
    ofSetColor(ofColor(203,190,189,alpha));
    ofDrawRectangle(100,500,50,50);
    
    //4
    ofSetColor(ofColor(201,170,158,alpha));
    ofDrawRectangle(150,500,50,50);
    
    //5
    ofSetColor(ofColor(186,135,119,alpha));
    ofDrawRectangle(200,500,50,50);
    
    //6
    ofSetColor(ofColor(171,118,104,alpha));
    ofDrawRectangle(250,500,50,50);
    
    //7
    ofSetColor(ofColor(207,151,133,alpha));
    ofDrawRectangle(300,500,50,50);
    
    //8
    ofSetColor(ofColor(180,124,102,alpha));
    ofDrawRectangle(350,500,50,50);
    
    //9
    ofSetColor(ofColor(210,175,156,alpha));
    ofDrawRectangle(400,500,50,50);
    //10
    ofSetColor(ofColor(239,221,205,alpha));
    ofDrawRectangle(450,500,50,50);
    
    //11
    ofSetColor(ofColor(244,227,213,alpha));
    ofDrawRectangle(500,500,50,50);
    
    //12
    ofSetColor(ofColor(246,230,216,alpha));
    ofDrawRectangle(550,500,50,50);
    
    
    // 12TH ROW
    
    
    
    //1
    ofSetColor(ofColor(230,223,222,alpha));
    ofDrawRectangle(0,550,50,50);
    
    //2
    ofSetColor(ofColor(204,192,192,alpha));
    ofDrawRectangle(50,550,50,50);
    
    //3
    ofSetColor(ofColor(201,188,188,alpha));
    ofDrawRectangle(100,550,50,50);
    
    //4
    ofSetColor(ofColor(200,178,170,alpha));
    ofDrawRectangle(150,550,50,50);
    
    //5
    ofSetColor(ofColor(197,145,120,alpha));
    ofDrawRectangle(200,550,50,50);
    
    //6
    ofSetColor(ofColor(177,118,106,alpha));
    ofDrawRectangle(250,550,50,50);
    
    //7
    ofSetColor(ofColor(181,111,101,alpha));
    ofDrawRectangle(300,550,50,50);
    
    //8
    ofSetColor(ofColor(190,133,108,alpha));
    ofDrawRectangle(350,550,50,50);
    
    //9
    ofSetColor(ofColor(208,173,153,alpha));
    ofDrawRectangle(400,550,50,50);
    //10
    ofSetColor(ofColor(242,220,203,alpha));
    ofDrawRectangle(450,550,50,50);
    
    //11
    ofSetColor(ofColor(244,227,212,alpha));
    ofDrawRectangle(500,550,50,50);
    
    //12
    ofSetColor(ofColor(246,229,216,alpha));
    ofDrawRectangle(550,550,50,50);


    // 13TH ROW
    
    
    
    //1
    ofSetColor(ofColor(232,225,224,alpha));
    ofDrawRectangle(0,600,50,50);
    
    //2
    ofSetColor(ofColor(202,190,190,alpha));
    ofDrawRectangle(50,600,50,50);
    
    //3
    ofSetColor(ofColor(197,186,185,alpha));
    ofDrawRectangle(100,600,50,50);
    
    //4
    ofSetColor(ofColor(184,151,136,alpha));
    ofDrawRectangle(150,600,50,50);
    
    //5
    ofSetColor(ofColor(193,146,121,alpha));
    ofDrawRectangle(200,600,50,50);
    
    //6
    ofSetColor(ofColor(191,135,116,alpha));
    ofDrawRectangle(250,600,50,50);
    
    //7
    ofSetColor(ofColor(177,103,94,alpha));
    ofDrawRectangle(300,600,50,50);
    
    //8
    ofSetColor(ofColor(186,140,116,alpha));
    ofDrawRectangle(350,600,50,50);
    
    //9
    ofSetColor(ofColor(94,68,64,alpha));
    ofDrawRectangle(400,600,50,50);
    //10
    ofSetColor(ofColor(233,202,180,alpha));
    ofDrawRectangle(450,600,50,50);
    
    //11
    ofSetColor(ofColor(244,227,211,alpha));
    ofDrawRectangle(500,600,50,50);
    
    //12
    ofSetColor(ofColor(246,229,215,alpha));
    ofDrawRectangle(550,600,50,50);

    // 15TH ROW
    
    
    
    //1
    ofSetColor(ofColor(234,228,226,alpha));
    ofDrawRectangle(0,650,50,50);
    
    //2
    ofSetColor(ofColor(201,188,188,alpha));
    ofDrawRectangle(50,650,50,50);
    
    //3
    ofSetColor(ofColor(159,131,122,alpha));
    ofDrawRectangle(100,650,50,50);
    
    //4
    ofSetColor(ofColor(166,121,100,alpha));
    ofDrawRectangle(150,650,50,50);
    
    //5
    ofSetColor(ofColor(173,125,103,alpha));
    ofDrawRectangle(200,650,50,50);
    
    //6
    ofSetColor(ofColor(179,128,105,alpha));
    ofDrawRectangle(250,650,50,50);
    
    //7
    ofSetColor(ofColor(200,148,122,alpha));
    ofDrawRectangle(300,650,50,50);
    
    //8
    ofSetColor(ofColor(225,179,151,alpha));
    ofDrawRectangle(350,650,50,50);
    
    //9
    ofSetColor(ofColor(114,81,74,alpha));
    ofDrawRectangle(400,650,50,50);
    //10
    ofSetColor(ofColor(161,133,123,alpha));
    ofDrawRectangle(450,650,50,50);
    
    //11
    ofSetColor(ofColor(244,227,211,alpha));
    ofDrawRectangle(500,650,50,50);
    
    //12
    ofSetColor(ofColor(246,229,215,alpha));
    ofDrawRectangle(550,650,50,50);
    
    // 15TH ROW
    
    
    
    //1
    ofSetColor(ofColor(229,224,223,alpha));
    ofDrawRectangle(0,700,50,50);
    
    //2
    ofSetColor(ofColor(103,81,83,alpha));
    ofDrawRectangle(50,700,50,50);
    
    //3
    ofSetColor(ofColor(65,42,44,alpha));
    ofDrawRectangle(100,700,50,50);
    
    //4
    ofSetColor(ofColor(131,94,83,alpha));
    ofDrawRectangle(150,700,50,50);
    
    //5
    ofSetColor(ofColor(158,108,90,alpha));
    ofDrawRectangle(200,700,50,50);
    
    //6
    ofSetColor(ofColor(189,134,113,alpha));
    ofDrawRectangle(250,700,50,50);
    
    //7
    ofSetColor(ofColor(235,183,156,alpha));
    ofDrawRectangle(300,700,50,50);
    
    //8
    ofSetColor(ofColor(200,154,130,alpha));
    ofDrawRectangle(350,700,50,50);
    
    //9
    ofSetColor(ofColor(144,107,93,alpha));
    ofDrawRectangle(400,700,50,50);
    //10
    ofSetColor(ofColor(118,86,81,alpha));
    ofDrawRectangle(450,700,50,50);
    
    //11
    ofSetColor(ofColor(243,225,209,alpha));
    ofDrawRectangle(500,700,50,50);
    
    //12
    ofSetColor(ofColor(245,228,214,alpha));
    ofDrawRectangle(550,700,50,50);
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
