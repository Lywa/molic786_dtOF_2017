#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    // setup the server to listen on 11999
    TCP.setup(11999);
    // optionally set the delimiter to something else.  The delimiter in the client and the server have to be the same, default being [/TCP]
    TCP.setMessageDelimiter("\n");
    lastSent = 0;
    
    
    ofBackground(0);
    
    ofSetFrameRate(30);
    
    ofDisableArbTex();    // map image textures properly to of3DPrimitive meshes
    
    // enable web cam
    
    vid.listDevices();        // just prints all your video cameras to console
    
    vid.setup(640,480);    // start default cam at 640x480
    
    // setup the slitscan object
    
    slitScan = SlitScan(640, 480);  // create slit scan
    
    // setup the mesh
    
    mesh = ofMesh::plane(640, 480, 128, 96);
    
    //
    eventString = "Add";
    blendMode = OF_BLENDMODE_ALPHA;
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //ofBackground(20, 20, 20);
    
    // VIDEO
    
    
    vid.update();        // update web cam
    
    if (vid.isFrameNew())
    {
        // update the slit scan
        
        slitScan.addLine(vid.getTexture());
        
        
        // update the mesh z based on slit scan brightness:
        
        // grab the pixels to read color
        ofPixels pix = slitScan.getPixels();
        
       
        // loop through the mesh
        for (int i=0; i<mesh.getVertices().size(); i++)
        {
            
            ofVec3f vert    = mesh.getVertex(i);
            
            float imgX    = ofMap(vert.x, -320, 320, 0, pix.getWidth()-1);
            float imgY    = ofMap(vert.y, -240, 240, 0, pix.getHeight()-1);
            ofColor color    = pix.getColor(imgX, imgY);
            vert.z    = ofMap( color.getBrightness(), 0, 255, 0, 10);
            
            // update vert z
            mesh.setVertex(i, vert);
        }
    }
    
    // increment scene rotation
    
    //    rotation -= 0.1;
    
    
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
   
    int clientId=TCP.getLastID();

    TCP.receiveRawBytes(clientId,(char*)tempBuff, TCP.getNumReceivedBytes(clientId));
    cout<<TCP.getNumReceivedBytes(clientId)<<endl;
   
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //VIDEO
    // shifting background hue
    float sinTime = sin(ofGetElapsedTimef() * .1);
    float bgHue = ofMap( sinTime, -1, 1, 0, 255);
    //ofBackground( ofColor::fromHsb(bgHue,255,255) );
    
    //    ofBackground(0, 0, 0);
    
    //ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    /* ofEnableBlendMode(blendMode);
    
   
    
    cam.begin();
    ofEnableDepthTest();
    
    // rotate scene
    ofRotateX(rotation);
    
    
    
    slitScan.bind();
    if (bDrawPoints)
        mesh.drawVertices();
    else
        mesh.draw();
    slitScan.unbind();
    
    if (bDrawWireframe)
        mesh.drawWireframe();
    
    
    
    //    slitScanRetime.bind();
    //    if (bDrawPoints)
    //        mesh.drawVertices();
    //    else
    //        mesh.draw();
    //    slitScanRetime.unbind();
    //
    //    if (bDrawWireframe)
    //        mesh.drawWireframe();
    
    
    
    
    ofDisableDepthTest();
    cam.end();*/
    
    
   
    
    
    ofDrawRectangle(300, 200, 100, 100);

   
    ofDisableBlendMode();

    
    // on screen text
    stringstream ss;
    ss
    << "'W': draw wireframe [" << bDrawWireframe << "]" << endl
    << "'P': draw point cloud [" << bDrawPoints << "]";
    ofDrawBitmapStringHighlight(ss.str(), 20, 20);
    
    
    
    // TCP

    
    ofSetHexColor(0xDDDDDD);
    ofDrawBitmapString("TCP SERVER Example \n\nconnect on port: "+ofToString(TCP.getPort()), 10, 20);
    
    ofSetHexColor(0x000000);
   // ofDrawRectangle(10, 60, ofGetWidth()-24, ofGetHeight() - 65 - 15);
    
    ofSetHexColor(0xDDDDDD);
    
    // for each connected client lets get the data being sent and lets print it to the screen
    for(unsigned int i = 0; i < (unsigned int)TCP.getLastID(); i++){
        
        if( !TCP.isClientConnected(i) )continue;
        
        // print image:
        ofPixels img;
        
        img.allocate(640, 480, GL_RGBA);
        //img.set(*tempBuff);
        img.setFromPixels(const unsigned char *tempBuff, 640, 480, GL_RGBA);
        cout<<sizeof(tempBuff)<< endl;
        
        
        ofImage newImage;
        newImage.setFromPixels(img);
        newImage.allocate(640, 480,OF_IMAGE_COLOR_ALPHA);
        
        newImage.draw(ofGetWidth()/2-640/2,ofGetHeight()/2-480/2,640,480);
        
    
        
        // give each client its own color
        ofSetColor(255 - i*30, 255 - i * 20, 100 + i*40);
        
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
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'w' || key == 'W')
    {
        bDrawWireframe = !bDrawWireframe;
    }
    else if (key == 'p' || key == 'P')
    {
        bDrawPoints = !bDrawPoints;
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

