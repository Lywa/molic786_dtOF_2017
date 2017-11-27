//
//  SlitScan.cpp
//  3DSlitScan
//
//  Created by Tyler on 11/3/17.
//
//

#include "SlitScanExt.hpp"


SlitScanExt::SlitScanExt()
: SlitScanExt(640,480)    // default call alternate constructor below
{}

SlitScanExt::SlitScanExt( int w, int h )
{
    width = w;
    height = h;
    
    // always pre-allocate FBOs
    fboExt.allocate( width, height);
    
    lineNum = 0;
}


void SlitScanExt::addLine( ofTexture source )
{
    fboExt.begin();        // draw offscreen
    
    // draw a single line from the webcam image on our fbo
    source.drawSubsection
    (
     0, lineNum, width, 1,    // draw area (x,y,w,h)
     0, lineNum, width, 1    // source area
     );
    
    fboExt.end();
    
    lineNum = (lineNum+1) % height;
    // increment lineNum by 1, and at height, reset to 0
    
}

void SlitScanExt::draw(float x, float y, float w, float h)
{
    fboExt.draw(x,y,w,h);
}

void SlitScanExt::bind()
{
    fboExt.getTexture().bind();
}

void SlitScanExt::unbind()
{
    fboExt.getTexture().unbind();
}

ofPixels SlitScanExt::getPixels()
{
    ofPixels pixExt;
    fboExt.readToPixels(pixExt);
    return pixExt;
}






