
#include "Particle.hpp"

Particle::Particle()
{
}

Particle::Particle(ofVec3f _pos, ofVec3f _vel)
{
	pos = _pos;
	vel = _vel;
}

void Particle::applyForce(ofVec3f force)
{
	acc += force;
}

void Particle::applyDamping(float strength)
{
	acc -= vel.getNormalized() * strength;
}

void Particle::update()
{
	vel += acc;
	pos += vel;
	acc *= 0;
    drawLines();
}

void Particle::draw(){
	
	ofPushStyle();
	ofSetColor(color);
	
	ofDrawCircle(pos, 1);
    ofDrawLine(pos.x, pos.y, pos.x+200, pos.y+200);
    drawLines();
	ofPopStyle();
}

void Particle::drawLines(){
    
    //ofSetColor(255);
    ofDrawLine(pos.x, pos.y, pos.x+200, pos.y+200);
    int _x = pos.x + ofDist(pos.x, pos.y,pos.x+200,pos.y+200);
    int _y = pos.y - ofDist(pos.x, pos.y,pos.x+200,pos.y+200);
    ofDrawCircle(x,y, radius/10);
    ofDrawLine(_x,_y ,x,y);
    ofSetColor(color);
    ofDrawCircle(_x,_y, radius/10);
    //ofSetColor(255);
    int _x2 = _x +ofDist(_x,_y,pos.x+200,pos.y+200);
    int _y2 = _y+ofDist(_x,_y,radius+ofGetWidth()/2,radius+ofGetHeight()/2)/2;
    
    ofDrawLine(_x2,_y2,pos.x,pos.y);
    //ofSetColor(color);
    ofDrawCircle(_x2,_y2, radius/10);
    
    
    
    
}
