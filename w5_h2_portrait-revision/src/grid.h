//
//  grid.hpp
//  square_n
//
//  Created by Carla on 04/10/2017.
//
//

#pragma once

#include "ofMain.h"
#include "square.h"


class Grid {
public:
    
    Grid();
    
    void setup();
    void update();
    void draw();
    
    void changeSquareAlphaAt(float x_, float y_);
    
    
    
protected:
    int number_of_rows;
    int squares_per_row;
    vector<Square> squares;
    vector<vector <Square> > pixels;
    
    void setSquareColors();
    
};

