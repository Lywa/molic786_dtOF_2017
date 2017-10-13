//
//  firework.hpp
//  w06_h02_Fireworks
//
//  Created by Carla on 11/10/2017.
//
//



#include "ofMain.h"
#include "Particlesystem.hpp"
#include "tail.hpp"

class Firework {
public:
    
    Firework();
    void setup();
    void update();
    void update(ofVec3f force, float timeDiff);
    void draw();
    void mouseReleased(int x, int y, int button);
    void setFinalPosition(int x, int y);
    
    
    vector<ParticleSystem> systems;
    ofVec3f gravity;
    
    float lastUpdateTime;	// track frame-by-frame time diff
    Tail tail;
    void applyForce(ofVec3f force);

};



