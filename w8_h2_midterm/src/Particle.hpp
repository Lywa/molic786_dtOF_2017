
#pragma once
#include "ofMain.h"
#include "Ball.h"

class Particle {
	
public:

	Particle();
	~Particle(){}
	
	Particle(ofVec3f _pos, ofVec3f _vel);
	
	void applyForce(ofVec3f force);
	void applyDamping(float strength);
	
    void setup();
    void update();
	void draw();
    void drawLines();
	
	ofVec3f pos, vel, acc;
    
    vector<Ball> balls;
    float radius;        // size
    float x, y;            // position
    float dirX, dirY;    // "direction" (a.k.a. velocity or speed)
  ofColor color;
    
};
