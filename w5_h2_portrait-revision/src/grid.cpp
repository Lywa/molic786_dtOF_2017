//  grid.cpp
//  square_n
//
//  Created by Carla on 04/10/2017.
//
//


#include "grid.h"

Grid::Grid() {
    
    
}

void Grid::setup(){
    // Initialize vector of vectors to represent a matrix of squares.
    number_of_rows = ofGetHeight()/50;
    squares_per_row = ofGetWidth()/50;
    
    for (int s=0;s<number_of_rows; s+=1) {
        vector<Square> temp_vect;
        pixels.push_back(temp_vect);
        for(int sq = 0; sq<squares_per_row; sq+=1) {
            Square temp_square;
            
            temp_square.setup();
            temp_square.x = sq*50;
            temp_square.y = s*50;
            
            pixels[s].push_back(temp_square);
        }
    }
    this->setSquareColors();
}

void Grid::update(){
    for (int s=0;s<pixels.size(); s+=1) {
        for(int sq = 0; sq<pixels[s].size(); sq+=1) {
            pixels[s][sq].update();
        }
    }
}

void Grid::draw(){
    for (int s=0;s<pixels.size(); s+=1) {
        for(int sq = 0; sq<pixels[s].size(); sq+=1) {
            pixels[s][sq].draw();
        }
    }
}

//void Grid::changeSquareAlphaAt(float x_, float y_){
//    int alpha = 10;
//    for (int s=0;s<pixels.size(); s+=1) {
//        for(int sq = 0; sq<pixels[s].size(); sq+=1) {
//            if (squares[i].containsPosition(x_, y_)) {
//                pixels[s][sq].color.a = alpha;
////              cout << squares[i].x << "," << squares[i].y << endl;
////              cout << ofToString(squares[i].color) << "," <<squares[i].alpha << endl;
//            }
//        }
//    }
//}

void Grid::changeSquareAlphaAt(float x_, float y_){
    float sq_x, sq_y;
    sq_x = floor(x_ / 50);
    sq_y = floor(y_ / 50);
    
    for (int s=0;s<pixels.size(); s+=1) {
        for(int sq = 0; sq<pixels[s].size(); sq+=1) {
            pixels[s][sq].color.a = 255;
        }
    }
    
    
    //
    //
    if ((sq_x+1 < pixels[0].size()) && (sq_y+1 < pixels.size())){
        
        pixels[sq_y+1][sq_x+1].color.a = 150;
        
        
    }
    
    if ((sq_y-1 > 0) && (sq_x-1 > 0)){
        
        pixels[sq_y-1][sq_x-1].color.a = 150;
        
        
    }
    
    if ( ( sq_y+1 < pixels.size()) && (sq_x-1 > 0) ){
        
        pixels[sq_y+1][sq_x-1].color.a = 150;
        
    }
    
    if ( (sq_y-1 > 0) && (sq_x+1 < pixels[0].size()) ){
        
        pixels[sq_y-1][sq_x+1].color.a = 150;
        
    }
    
    if ( sq_y+1 < pixels.size()){
        
        pixels[sq_y+1][sq_x].color.a = 150;
        
        
        
    }
    
    if (sq_x+1 < pixels[0].size()) {
        pixels[sq_y][sq_x+1].color.a = 150;
        
    }
    
    
    if (sq_x-1 > 0) {
        pixels[sq_y][sq_x-1].color.a = 150;
    }
    
    if (sq_y-1 > 0){
        
        pixels[sq_y-1][sq_x].color.a = 150;
        
        
    }
    
    if ((sq_x > 0 ) && (sq_x < pixels[0].size()) && ( sq_y > 0) && ( sq_y < pixels.size()) ) {
        
        pixels[sq_y][sq_x].color.a = 80;
    }
    
    
    
    // center pixel
    // pixels[sq_y][sq_x].color.a = 100;
    
    
    // pixels around the mouse pixel
    
    
    //    pixels[sq_y][sq_x-1].color.a = 150;
    //    pixels[sq_y][sq_x+1].color.a = 150;
    //    pixels[sq_y+1][sq_x].color.a = 150;
    //    pixels[sq_y-1][sq_x].color.a = 150;
    //
    //
    //    pixels[sq_y+1][sq_x+1].color.a = 150;
    //    pixels[sq_y-1][sq_x-1].color.a = 150;
    //    pixels[sq_y+1][sq_x-1].color.a = 150;
    //    pixels[sq_y-1][sq_x+1].color.a = 150;
    
    
    
    
    
    
    //            cout << squares[i].x << "," << squares[i].y << endl;
    //            cout << ofToString(squares[i].color) << "," <<squares[i].alpha << endl;
    //            squares[i].alpha = 0;
}


void Grid::setSquareColors() {
    int alpha = 255;
    pixels[0][0].color.set (227,213,206,alpha);
    pixels[0][1].color.set (225,210,203,alpha);
    pixels[0][2].color.set (226,211,204,alpha);
    pixels[0][3].color.set (220,201,197,alpha);
    pixels[0][4].color.set (181,147,156,alpha);
    pixels[0][5].color.set (220,201,197,alpha);
    pixels[0][6].color.set (229,215,207,alpha);
    pixels[0][7].color.set (230,216,207,alpha);
    pixels[0][8].color.set (231,217,207,alpha);
    pixels[0][9].color.set (235,217,209,alpha);
    pixels[0][10].color.set (236,220,207,alpha);
    pixels[0][11].color.set (237,220,209,alpha);
    pixels[1][0].color.set (228,214,207,alpha);
    pixels[1][1].color.set (226,211,204,alpha);
    pixels[1][2].color.set (185,155,160,alpha);
    pixels[1][3].color.set (102,49,80,alpha);
    pixels[1][4].color.set (87,37,69,alpha);
    pixels[1][5].color.set (115,72,91,alpha);
    pixels[1][6].color.set (229,215,206,alpha);
    pixels[1][7].color.set (223,207,200,alpha);
    pixels[1][8].color.set (156,108,126,alpha);
    pixels[1][9].color.set (142,93,113,alpha);
    pixels[1][10].color.set (236,220,207,alpha);
    pixels[1][11].color.set (237,221,208,alpha);
    pixels[2][0].color.set (230,217,210,alpha);
    pixels[2][1].color.set (226,211,204,alpha);
    pixels[2][2].color.set (128,82,102,alpha);
    pixels[2][3].color.set (82,34,64,alpha);
    pixels[2][4].color.set (85,36,66,alpha);
    pixels[2][5].color.set (93,38,70,alpha);
    pixels[2][6].color.set (218,200,195,alpha);
    pixels[2][7].color.set (148,97,114,alpha);
    pixels[2][8].color.set (90,35,68,alpha);
    pixels[2][9].color.set (111,48,84,alpha);
    pixels[2][10].color.set(225,206,194,alpha);
    pixels[2][11].color.set(236,220,205,alpha);
    pixels[3][0].color.set (231,218,212,alpha);
    pixels[3][1].color.set (226,211,204,alpha);
    pixels[3][2].color.set (129,80,103,alpha);
    pixels[3][3].color.set (90,37,69,alpha);
    pixels[3][4].color.set (80,35,63,alpha);
    pixels[3][5].color.set (86,41,68,alpha);
    pixels[3][6].color.set (150,105,124,alpha);
    pixels[3][7].color.set (87,36,66,alpha);
    pixels[3][8].color.set (83,35,64,alpha);
    pixels[3][9].color.set (95,38,74,alpha);
    pixels[3][10].color.set(187,152,154,alpha);
    pixels[3][11].color.set(236,219,205,alpha);
    pixels[4][0].color.set (232,219,214,alpha);
    pixels[4][1].color.set (226,211,204,alpha);
    pixels[4][2].color.set (131,94,110,alpha);
    pixels[4][3].color.set (66,34,54,alpha);
    pixels[4][4].color.set (60,34,45,alpha);
    pixels[4][5].color.set (66,41,46,alpha);
    pixels[4][6].color.set (68,41,48,alpha);
    pixels[4][7].color.set (56,30,42,alpha);
    pixels[4][8].color.set (80,33,60,alpha);
    pixels[4][9].color.set (96,40,73,alpha);
    pixels[4][10].color.set(196,168,165,alpha);
    pixels[4][11].color.set(237,221,206,alpha);
    pixels[5][0].color.set (231,219,215,alpha);
    pixels[5][1].color.set (224,209,204,alpha);
    pixels[5][2].color.set (169,151,149,alpha);
    pixels[5][3].color.set (64,44,47,alpha);
    pixels[5][4].color.set (94,65,62,alpha);
    pixels[5][5].color.set (177,130,113,alpha);
    pixels[5][6].color.set (173,128,113,alpha);
    pixels[5][7].color.set (114,79,72,alpha);
    pixels[5][8].color.set (77,36,54,alpha);
    pixels[5][9].color.set (121,74,91,alpha);
    pixels[5][10].color.set(234,218,204,alpha);
    pixels[5][11].color.set(237,221,207,alpha);
    pixels[6][0].color.set (231,220,217,alpha);
    pixels[6][1].color.set (231,220,217,alpha);
    pixels[6][2].color.set (122,103,101,alpha);
    pixels[6][3].color.set (78,54,52,alpha);
    pixels[6][4].color.set (184,138,120,alpha);
    pixels[6][5].color.set (218,165,141,alpha);
    pixels[6][6].color.set (230,179,151,alpha);
    pixels[6][7].color.set (228,177,145,alpha);
    pixels[6][8].color.set (149,111,101,alpha);
    pixels[6][9].color.set (210,185,177,alpha);
    pixels[6][10].color.set(235,220,206,alpha);
    pixels[6][11].color.set(237,222,209,alpha);
    pixels[7][0].color.set (232,221,219,alpha);
    pixels[7][1].color.set (224,209,204,alpha);
    pixels[7][2].color.set (110,90,89,alpha);
    pixels[7][3].color.set (85,60,58,alpha);
    pixels[7][4].color.set (196,150,128,alpha);
    pixels[7][5].color.set (213,161,138,alpha);
    pixels[7][6].color.set (221,167,138,alpha);
    pixels[7][7].color.set (225,172,142,alpha);
    pixels[7][8].color.set (202,165,141,alpha);
    pixels[7][9].color.set (236,220,206,alpha);
    pixels[7][10].color.set(238,223,209,alpha);
    pixels[7][11].color.set(242,226,212,alpha);
    pixels[8][0].color.set (231,222,219,alpha);
    pixels[8][1].color.set (210,197,195,alpha);
    pixels[8][2].color.set (165,126,119,alpha);
    pixels[8][3].color.set (120,88,81,alpha);
    pixels[8][4].color.set (135,100,90,alpha);
    pixels[8][5].color.set (99,67,63,alpha);
    pixels[8][6].color.set (181,131,111,alpha);
    pixels[8][7].color.set (95,65,61,alpha);
    pixels[8][8].color.set (152,117,103,alpha);
    pixels[8][9].color.set (213,195,181,alpha);
    pixels[8][10].color.set(240,225,211,alpha);
    pixels[8][11].color.set(245,228,215,alpha);
    pixels[9][0].color.set (229,220,219,alpha);
    pixels[9][1].color.set (206,194,192,alpha);
    pixels[9][2].color.set (190,165,160,alpha);
    pixels[9][3].color.set (165,123,108,alpha);
    pixels[9][4].color.set (187,138,122,alpha);
    pixels[9][5].color.set (160,111,98,alpha);
    pixels[9][6].color.set (148,106,94,alpha);
    pixels[9][7].color.set (170,123,106,alpha);
    pixels[9][8].color.set (210,173,153,alpha);
    pixels[9][9].color.set (220,202,189,alpha);
    pixels[9][10].color.set(243,226,213,alpha);
    pixels[9][11].color.set(245,229,216,alpha);
    pixels[10][0].color.set (228,221,219,alpha);
    pixels[10][1].color.set (205,193,192,alpha);
    pixels[10][2].color.set (203,190,189,alpha);
    pixels[10][3].color.set (201,170,158,alpha);
    pixels[10][4].color.set (186,135,119,alpha);
    pixels[10][5].color.set (171,118,104,alpha);
    pixels[10][6].color.set (207,151,133,alpha);
    pixels[10][7].color.set (180,124,102,alpha);
    pixels[10][8].color.set (210,175,156,alpha);
    pixels[10][9].color.set (239,221,205,alpha);
    pixels[10][10].color.set(244,227,213,alpha);
    pixels[10][11].color.set(246,230,216,alpha);
    pixels[11][0].color.set (230,223,222,alpha);
    pixels[11][1].color.set (204,192,192,alpha);
    pixels[11][2].color.set (201,188,188,alpha);
    pixels[11][3].color.set (200,178,170,alpha);
    pixels[11][4].color.set (197,145,120,alpha);
    pixels[11][5].color.set (177,118,106,alpha);
    pixels[11][6].color.set (181,111,101,alpha);
    pixels[11][7].color.set (190,133,108,alpha);
    pixels[11][8].color.set (208,173,153,alpha);
    pixels[11][9].color.set (242,220,203,alpha);
    pixels[11][10].color.set(244,227,212,alpha);
    pixels[11][11].color.set(246,229,216,alpha);
    pixels[12][0].color.set (232,225,224,alpha);
    pixels[12][1].color.set (202,190,190,alpha);
    pixels[12][2].color.set (197,186,185,alpha);
    pixels[12][3].color.set (184,151,136,alpha);
    pixels[12][4].color.set (193,146,121,alpha);
    pixels[12][5].color.set (191,135,116,alpha);
    pixels[12][6].color.set (177,103,94,alpha);
    pixels[12][7].color.set (186,140,116,alpha);
    pixels[12][8].color.set (94,68,64,alpha);
    pixels[12][9].color.set (233,202,180,alpha);
    pixels[12][10].color.set(244,227,211,alpha);
    pixels[12][11].color.set(246,229,215,alpha);
    pixels[13][0].color.set (234,228,226,alpha);
    pixels[13][1].color.set (201,188,188,alpha);
    pixels[13][2].color.set (159,131,122,alpha);
    pixels[13][3].color.set (166,121,100,alpha);
    pixels[13][4].color.set (173,125,103,alpha);
    pixels[13][5].color.set (179,128,105,alpha);
    pixels[13][6].color.set (200,148,122,alpha);
    pixels[13][7].color.set (225,179,151,alpha);
    pixels[13][8].color.set (114,81,74,alpha);
    pixels[13][9].color.set (161,133,123,alpha);
    pixels[13][10].color.set(244,227,211,alpha);
    pixels[13][11].color.set(246,229,215,alpha);
    pixels[14][0].color.set (229,224,223,alpha);
    pixels[14][1].color.set (103,81,83,alpha);
    pixels[14][2].color.set (65,42,44,alpha);
    pixels[14][3].color.set (131,94,83,alpha);
    pixels[14][4].color.set (158,108,90,alpha);
    pixels[14][5].color.set (189,134,113,alpha);
    pixels[14][6].color.set (235,183,156,alpha);
    pixels[14][7].color.set (200,154,130,alpha);
    pixels[14][8].color.set (144,107,93,alpha);
    pixels[14][9].color.set (118,86,81,alpha);
    pixels[14][10].color.set(243,225,209,alpha);
    pixels[14][11].color.set(245,228,214,alpha);
}
