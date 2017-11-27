#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    ofSetFrameRate(30);
    
    ofDisableArbTex();    // map image textures properly to of3DPrimitive meshes
    
    // enable web cam
    
    vid.listDevices();        // just prints all your video cameras to console
    vid.setDeviceID(0);
    vidExt.setDeviceID(1);
    
    vid.setup(640,480);    // start default cam at 640x480
    vidExt.setup(640,480);
    
    // setup the slitscan object
    
    slitScan = SlitScan(640, 480);  // create slit scan
    slitScanExt= SlitScan(640, 480);
    
    // setup the mesh
    
    mesh = ofMesh::plane(640, 480, 128, 96);
    meshExt = ofMesh::plane(640, 480, 128, 96);
    //
    eventString = "Screen";
    blendMode = OF_BLENDMODE_ADD;
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    vid.update();// update web cam
    vidExt.update();
    
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
    
    
    if (vidExt.isFrameNew())
    {
        // update the slit scan
        
        slitScanExt.addLine(vidExt.getTexture());
        
        
        // update the mesh z based on slit scan brightness:
        
        // grab the pixels to read color
        ofPixels pixExt = slitScanExt.getPixels();
        
        // loop through the mesh
        for (int i=0; i<meshExt.getVertices().size(); i++)
        {
            
            ofVec3f vert    = meshExt.getVertex(i);
            
            float imgX    = ofMap(vert.x, -320, 320, 0, pixExt.getWidth()-1);
            float imgY    = ofMap(vert.y, -240, 240, 0, pixExt.getHeight()-1);
            ofColor color    = pixExt.getColor(imgX, imgY);
            vert.z    = ofMap( color.getBrightness(), 0, 255, 0, 10);
            
            // update vert z
            meshExt.setVertex(i, vert);
        }
    }
    
    
    // increment scene rotation
    
    //    rotation -= 0.1;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // Draw first lawer. Video (Local)
    //vid.draw(ofGetWidth()/2-640/2,ofGetHeight()/2-480/2,640,480);
    
    
    cam.begin();
    ofEnableDepthTest();
    
    // rotate scene
    ofRotateX(rotation);
    
    slitScanExt.bind();
    if (bDrawPoints)
        meshExt.drawVertices();
    else
        meshExt.draw();
    slitScanExt.unbind();
    
    if (bDrawWireframe)
        meshExt.drawWireframe();
    
    
    
    
    //ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofEnableBlendMode(blendMode);
    
    //
    //    // rotate scene
    //    ofRotateX(rotation);
    //
    
    
    slitScan.bind();
    if (bDrawPoints)
        mesh.drawVertices();
    else
        mesh.draw();
    slitScan.unbind();
    
    if (bDrawWireframe)
        mesh.drawWireframe();
    
    
    
    
    ofDisableDepthTest();
    cam.end();
    
    ofDisableBlendMode();
    
    // on screen text
    stringstream ss;
    ss
    << "'W': draw wireframe [" << bDrawWireframe << "]" << endl
    << "'P': draw point cloud [" << bDrawPoints << "]";
    ofDrawBitmapStringHighlight(ss.str(), 20, 20);
    
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


