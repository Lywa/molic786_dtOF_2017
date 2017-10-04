//
//  square.cpp
//  w3_h5_portrait2
//
//  Created by Carla on 01/10/2017.
//
//

#include "square.h"
#include <stdio.h>


Square::Square(){
    
    
}



void Square::setup(){

//   int colorArray[180][4]={
//    {227,213,206,alpha},
//    {225,210,203,alpha}
//   
//   
//   };
    
    
    
    
    


}


void Square::update(){
    
    
    
    // make a ball follow the mouse
    
    ofVec2f mouse;
    mouse.x = ofGetMouseX();
    mouse.y = ofGetMouseY();
    
    float pct = .05; // every frame move ball 5% towards the mouse
    
    
    
    
    // change the ball brightness with distance
    
    // float dist = mouse.distance();
    
    // as distance increases, brightness increases:
    alpha = ofMap(mouse.x, 0, 500, 50, 255);
    cout << alpha << endl;

     //alpha=255;
    
}


// define square
void Square::draw(){
    
   
    
    
    for (int x=0; x<ofGetWidth(); x+=50){
        
        
        
        for (int y=0; y<ofGetHeight();y+=50){
            
            //1ST ROW
            
            //1

            if (x==0 && y==0){
            //ofSetColor(ofColor(227,213,206,alpha));
                color.set(227,213,206,alpha);
                //ofColor color_1_1(227,213,206,alpha);
                //ofSetColor(color_1_1);
            
                
            }
            //2
            
            else if (x==50 && y==0){
                
//                ofColor color_1_2(225,210,203,alpha);
//                ofSetColor(color_1_2);
//                cout << color_1_2 << endl;
            
                color.set(225,210,203,alpha);
            }
            
            //3
            else if (x==100 && y==0){
                
//                ofColor color_1_3(ofColor(226,211,204,alpha));
//                ofSetColor(color_1_3);
//                cout << color_1_3 << endl;
                
                color.set(226,211,204,alpha);
            
            }
            
            //4
            else if (x==150 && y==0){
                
//                ofColor color_1_4(220,201,197,alpha);
//                ofSetColor(color_1_4);
//                cout << color_1_4 << endl;
                color.set(220,201,197,alpha);
    
                
            }
            
            //5
            else if (x==200 && y==0){
                
                color.set(181,147,156,alpha);


                
            }
            
            //6
        
            else if (x==250 && y==0){
                
                color.set(220,201,197,alpha);

                

                
            }
            
            //7
            else if (x==300 && y==0){
                
                color.set(229,215,207,alpha);
                
            }
                           
            //8
            else if (x==350 && y==0){
                
                color.set(230,216,207,alpha);
                
            }
            
            //9
            
            else if (x==350 && y==0){
                
                color.set(231,217,207,alpha);
                
            }
            
            //10
            
            else if (x==400 && y==0){
                
                color.set(235,217,209,alpha);
                
            }
            
            //11
            
            else if (x==450 && y==0){
                
                color.set(236,220,207,alpha);
                
            }
            
            //12
            
            else if (x==500 && y==0){
                
                color.set(237,220,209,alpha);
                
            }
            
            
            
            //2ND ROW
            
            //1
            
            if (x==0 && y==50){
               
                color.set(228,214,207,alpha);
                
                
            }
            //2
            
            else if (x==50 && y==50){
                
                color.set(226,211,204,alpha);
            }
            
            //3
            else if (x==100 && y==50){
                
                color.set(185,155,160,alpha);
                
            }
            
            //4
            else if (x==150 && y==50){
                
                
                color.set(102,49,80,alpha);
                
            }
            
            //5
            else if (x==200 && y==50){
                
                color.set(87,37,69,alpha);
            
                
            }
            
            //6
            
            else if (x==250 && y==50){
                
                color.set(115,72,91,alpha);
            
                
            }
            
            //7
            else if (x==300 && y==50){
                
                color.set(229,215,206,alpha);
                
            }
            
            //8
            else if (x==350 && y==50){
                
                color.set(223,207,200,alpha);
                
            }
            
            //9
            
            else if (x==350 && y==50){
                
                color.set(156,108,126,alpha);
                
            }
            
            //10
            
            else if (x==400 && y==50){
                
                color.set(142,93,113,alpha);
                
            }
            
            //11
            
            else if (x==450 && y==50){
                
                color.set(236,220,207,alpha);
                
            }
            
            //12
            
            else if (x==500 && y==50){
                
                color.set(237,221,208,alpha);
                
            }
            
            //3RD ROW
            
            //1
            
            if (x==0 && y==100){
                
                color.set(230,217,210,alpha);
                
                
            }
            //2
            
            else if (x==50 && y==100){
                
                color.set(226,211,204,alpha);
            }
            
            //3
            else if (x==100 && y==100){
                
                color.set(128,82,102,alpha);
                
            }
            
            //4
            else if (x==150 && y==100){
                
                
                color.set(82,34,64,alpha);
                
            }
            
            //5
            else if (x==200 && y==100){
                
                color.set(85,36,66,alpha);
                
                
            }
            
            //6
            
            else if (x==250 && y==100){
                
                color.set(93,38,70,alpha);
                
                
            }
            
            //7
            else if (x==300 && y==100){
                
                color.set(218,200,195,alpha);
                
            }
            
            //8
            else if (x==350 && y==100){
                
                color.set(148,97,114,alpha);
                
            }
            
            //9
            
            else if (x==350 && y==100){
                
                color.set(90,35,68,alpha);
                
            }
            
            //10
            
            else if (x==400 && y==100){
                
                color.set(111,48,84,alpha);
                
            }
            
            //11
            
            else if (x==450 && y==100){
                
                color.set(225,206,194,alpha);
                
            }
            
            //12
            
            else if (x==500 && y==100){
                
                color.set(236,220,205,alpha);
                
            }
            
                           
            //4TH ROW
            
            //1
            
            if (x==0 && y==150){
                
                color.set(231,218,212,alpha);
                
                
            }
            //2
            
            else if (x==50 && y==150){
                
                color.set(226,211,204,alpha);
            }
            
            //3
            else if (x==100 && y==150){
                
                color.set(129,80,103,alpha);
                
            }
            
            //4
            else if (x==150 && y==150){
                
                
                color.set(90,37,69,alpha);
                
            }
            
            //5
            else if (x==200 && y==150){
                
                color.set(80,35,63,alpha);
                
                
            }
            
            //6
            
            else if (x==250 && y==150){
                
                color.set(86,41,68,alpha);
                
                
            }
            
            //7
            else if (x==300 && y==150){
                
                color.set(150,105,124,alpha);
                
            }
            
            //8
            else if (x==350 && y==150){
                
                color.set(87,36,66,alpha);
                
            }
            
            //9
            
            else if (x==350 && y==150){
                
                color.set(83,35,64,alpha);
                
            }
            
            //10
            
            else if (x==400 && y==150){
                
                color.set(95,38,74,alpha);
                
            }
            
            //11
            
            else if (x==450 && y==150){
                
                color.set(187,152,154,alpha);
                
            }
            
            //12
            
            else if (x==500 && y==150){
                
                color.set(236,219,205,alpha);
                
            }
            
            //5TH ROW
            
            //1
            
            if (x==0 && y==200){
                
                color.set(232,219,214,alpha);
                
                
            }
            //2
            
            else if (x==50 && y==200){
                
                color.set(226,211,204,alpha);
            }
            
            //3
            else if (x==100 && y==200){
                
                color.set(131,94,110,alpha);
                
            }
            
            //4
            else if (x==150 && y==200){
                
                
                color.set(66,34,54,alpha);
                
            }
            
            //5
            else if (x==200 && y==200){
                
                color.set(60,34,45,alpha);
                
                
            }
            
            //6
            
            else if (x==250 && y==200){
                
                color.set(66,41,46,alpha);
                
                
            }
            
            //7
            else if (x==300 && y==200){
                
                color.set(68,41,48,alpha);
                
            }
            
            //8
            else if (x==350 && y==200){
                
                color.set(56,30,42,alpha);
                
            }
            
            //9
            
            else if (x==350 && y==200){
                
                color.set(80,33,60,alpha);
                
            }
            
            //10
            
            else if (x==400 && y==200){
                
                color.set(96,40,73,alpha);
                
            }
            
            //11
            
            else if (x==450 && y==200){
                
                color.set(196,168,165,alpha);
                
            }
            
            //12
            
            else if (x==500 && y==200){
                
                color.set(237,221,206,alpha);
                
            }
            
            //6TH ROW
            
            //1
            
            if (x==0 && y==250){
                
                color.set(231,219,215,alpha);
                
                
            }
            //2
            
            else if (x==50 && y==250){
                
                color.set(224,209,204,alpha);
            }
            
            //3
            else if (x==100 && y==250){
                
                color.set(169,151,149,alpha);
                
            }
            
            //4
            else if (x==150 && y==250){
                
                
                color.set(64,44,47,alpha);
                
            }
            
            //5
            else if (x==200 && y==250){
                
                color.set(94,65,62,alpha);
                
                
            }
            
            //6
            
            else if (x==250 && y==250){
                
                color.set(177,130,113,alpha);
                
                
            }
            
            //7
            else if (x==300 && y==250){
                
                color.set(173,128,113,alpha);
                
            }
            
            //8
            else if (x==350 && y==250){
                
                color.set(114,79,72,alpha);
                
            }
            
            //9
            
            else if (x==350 && y==250){
                
                color.set(77,36,54,alpha);
                
            }
            
            //10
            
            else if (x==400 && y==250){
                
                color.set(121,74,91,alpha);
                
            }
            
            //11
            
            else if (x==450 && y==250){
                
                color.set(234,218,204,alpha);
                
            }
            
            //12
            
            else if (x==500 && y==250){
                
                color.set(237,221,207,alpha);
                
            }
            
            
            //7TH ROW
            
            //1
            
            if (x==0 && y==300){
                
                color.set(231,220,217,alpha);
                
                
            }
            //2
            
            else if (x==50 && y==300){
                
                color.set(231,220,217,alpha);
            }
            
            //3
            else if (x==100 && y==300){
                
                color.set(122,103,101,alpha);
                
            }
            
            //4
            else if (x==150 && y==300){
                
                
                color.set(78,54,52,alpha);
                
            }
            
            //5
            else if (x==200 && y==300){
                
                color.set(184,138,120,alpha);
                
                
            }
            
            //6
            
            else if (x==250 && y==300){
                
                color.set(218,165,141,alpha);
                
                
            }
            
            //7
            else if (x==300 && y==300){
                
                color.set(230,179,151,alpha);
                
            }
            
            //8
            else if (x==350 && y==300){
                
                color.set(228,177,145,alpha);
                
            }
            
            //9
            
            else if (x==350 && y==300){
                
                color.set(149,111,101,alpha);
                
            }
            
            //10
            
            else if (x==400 && y==300){
                
                color.set(210,185,177,alpha);
                
            }
            
            //11
            
            else if (x==450 && y==300){
                
                color.set(235,220,206,alpha);
                
            }
            
            //12
            
            else if (x==500 && y==300){
                
                color.set(237,222,209,alpha);
                
            }
            
            //8TH ROW
            
            //1
            
            if (x==0 && y==350){
                
                color.set(232,221,219,alpha);
                
                
            }
            //2
            
            else if (x==50 && y==350){
                
                color.set(224,209,204,alpha);
            }
            
            //3
            else if (x==100 && y==350){
                
                color.set(110,90,89,alpha);
                
            }
            
            //4
            else if (x==150 && y==350){
                
                
                color.set(85,60,58,alpha);
                
            }
            
            //5
            else if (x==200 && y==350){
                
                color.set(196,150,128,alpha);
                
                
            }
            
            //6
            
            else if (x==250 && y==350){
                
                color.set(213,161,138,alpha);
                
                
            }
            
            //7
            else if (x==300 && y==350){
                
                color.set(221,167,138,alpha);
                
            }
            
            //8
            else if (x==350 && y==350){
                
                color.set(225,172,142,alpha);
                
            }
            
            //9
            
            else if (x==350 && y==350){
                
                color.set(202,165,141,alpha);
                
            }
            
            //10
            
            else if (x==400 && y==350){
                
                color.set(236,220,206,alpha);
                
            }
            
            //11
            
            else if (x==450 && y==350){
                
                color.set(238,223,209,alpha);
                
            }
            
            //12
            
            else if (x==500 && y==350){
                
                color.set(242,226,212,alpha);
                
            }
            
            //9TH ROW
            
            //1
            
            if (x==0 && y==400){
                
                color.set(231,222,219,alpha);
                
                
            }
            //2
            
            else if (x==50 && y==400){
                
                color.set(210,197,195,alpha);
            }
            
            //3
            else if (x==100 && y==400){
                
                color.set(165,126,119,alpha);
                
            }
            
            //4
            else if (x==150 && y==400){
                
                
                color.set(120,88,81,alpha);
                
            }
            
            //5
            else if (x==200 && y==400){
                
                color.set(135,100,90,alpha);
                
                
            }
            
            //6
            
            else if (x==250 && y==400){
                
                color.set(99,67,63,alpha);
                
                
            }
            
            //7
            else if (x==300 && y==400){
                
                color.set(181,131,111,alpha);
                
            }
            
            //8
            else if (x==350 && y==400){
                
                color.set(95,65,61,alpha);
                
            }
            
            //9
            
            else if (x==350 && y==400){
                
                color.set(152,117,103,alpha);
                
            }
            
            //10
            
            else if (x==400 && y==400){
                
                color.set(213,195,181,alpha);
                
            }
            
            //11
            
            else if (x==450 && y==400){
                
                color.set(240,225,211,alpha);
                
            }
            
            //12
            
            else if (x==500 && y==400){
                
                color.set(245,228,215,alpha);
                
            }
            
            
            //10TH ROW
            
            //1
            
            if (x==0 && y==450){
                
                color.set(229,220,219,alpha);
                
                
            }
            //2
            
            else if (x==50 && y==450){
                
                color.set(206,194,192,alpha);
            }
            
            //3
            else if (x==100 && y==450){
                
                color.set(190,165,160,alpha);
                
            }
            
            //4
            else if (x==150 && y==450){
                
                
                color.set(165,123,108,alpha);
                
            }
            
            //5
            else if (x==200 && y==450){
                
                color.set(187,138,122,alpha);
                
                
            }
            
            //6
            
            else if (x==250 && y==450){
                
                color.set(160,111,98,alpha);
                
                
            }
            
            //7
            else if (x==300 && y==450){
                
                color.set(148,106,94,alpha);
                
            }
            
            //8
            else if (x==350 && y==450){
                
                color.set(170,123,106,alpha);
                
            }
            
            //9
            
            else if (x==350 && y==450){
                
                color.set(210,173,153,alpha);
                
            }
            
            //10
            
            else if (x==400 && y==450){
                
                color.set(220,202,189,alpha);
                
            }
            
            //11
            
            else if (x==450 && y==450){
                
                color.set(243,226,213,alpha);
                
            }
            
            //12
            
            else if (x==500 && y==450){
                
                color.set(245,229,216,alpha);
                
            }
            
            
            
            //11TH ROW
            
            //1
            
            if (x==0 && y==500){
                
                color.set(228,221,219,alpha);
                
                
            }
            //2
            
            else if (x==50 && y==500){
                
                color.set(205,193,192,alpha);
            }
            
            //3
            else if (x==100 && y==500){
                
                color.set(203,190,189,alpha);
                
            }
            
            //4
            else if (x==150 && y==500){
                
                
                color.set(201,170,158,alpha);
                
            }
            
            //5
            else if (x==200 && y==500){
                
                color.set(186,135,119,alpha);
                
                
            }
            
            //6
            
            else if (x==250 && y==500){
                
                color.set(171,118,104,alpha);
                
                
            }
            
            //7
            else if (x==300 && y==500){
                
                color.set(207,151,133,alpha);
                
            }
            
            //8
            else if (x==350 && y==500){
                
                color.set(180,124,102,alpha);
                
            }
            
            //9
            
            else if (x==350 && y==500){
                
                color.set(210,175,156,alpha);
                
            }
            
            //10
            
            else if (x==400 && y==500){
                
                color.set(239,221,205,alpha);
                
            }
            
            //11
            
            else if (x==450 && y==500){
                
                color.set(244,227,213,alpha);
                
            }
            
            //12
            
            else if (x==500 && y==500){
                
                color.set(246,230,216,alpha);
                
            }
            
            
            //12TH ROW
            
            //1
            
            if (x==0 && y==550){
                
                color.set(230,223,222,alpha);
                
                
            }
            //2
            
            else if (x==50 && y==550){
                
                color.set(204,192,192,alpha);
            }
            
            //3
            else if (x==100 && y==550){
                
                color.set(201,188,188,alpha);
                
            }
            
            //4
            else if (x==150 && y==550){
                
                
                color.set(200,178,170,alpha);
                
            }
            
            //5
            else if (x==200 && y==550){
                
                color.set(197,145,120,alpha);
                
                
            }
            
            //6
            
            else if (x==250 && y==550){
                
                color.set(177,118,106,alpha);
                
                
            }
            
            //7
            else if (x==300 && y==550){
                
                color.set(181,111,101,alpha);
                
            }
            
            //8
            else if (x==350 && y==550){
                
                color.set(190,133,108,alpha);
                
            }
            
            //9
            
            else if (x==350 && y==550){
                
                color.set(208,173,153,alpha);
                
            }
            
            //10
            
            else if (x==400 && y==550){
                
                color.set(242,220,203,alpha);
                
            }
            
            //11
            
            else if (x==450 && y==550){
                
                color.set(244,227,212,alpha);
                
            }
            
            //12
            
            else if (x==500 && y==550){
                
                color.set(246,229,216,alpha);
                
            }
            
            //13TH ROW
            
            //1
            
            if (x==0 && y==600){
                
                color.set(232,225,224,alpha);
                
                
            }
            //2
            
            else if (x==50 && y==600){
                
                color.set(202,190,190,alpha);
            }
            
            //3
            else if (x==100 && y==600){
                
                color.set(197,186,185,alpha);
                
            }
            
            //4
            else if (x==150 && y==600){
                
                
                color.set(184,151,136,alpha);
                
            }
            
            //5
            else if (x==200 && y==600){
                
                color.set(193,146,121,alpha);
                
                
            }
            
            //6
            
            else if (x==250 && y==600){
                
                color.set(191,135,116,alpha);
                
                
            }
            
            //7
            else if (x==300 && y==600){
                
                color.set(177,103,94,alpha);
                
            }
            
            //8
            else if (x==350 && y==600){
                
                color.set(186,140,116,alpha);
                
            }
            
            //9
            
            else if (x==350 && y==600){
                
                color.set(94,68,64,alpha);
                
            }
            
            //10
            
            else if (x==400 && y==600){
                
                color.set(233,202,180,alpha);
                
            }
            
            //11
            
            else if (x==450 && y==600){
                
                color.set(244,227,211,alpha);
                
            }
            
            //12
            
            else if (x==500 && y==600){
                
                color.set(246,229,215,alpha);
                
            }
            
            //14TH ROW
            
            //1
            
            if (x==0 && y==650){
                
                color.set(234,228,226,alpha);
                
                
            }
            //2
            
            else if (x==50 && y==650){
                
                color.set(201,188,188,alpha);
            }
            
            //3
            else if (x==100 && y==650){
                
                color.set(159,131,122,alpha);
                
            }
            
            //4
            else if (x==150 && y==650){
                
                
                color.set(166,121,100,alpha);
                
            }
            
            //5
            else if (x==200 && y==650){
                
                color.set(173,125,103,alpha);
                
                
            }
            
            //6
            
            else if (x==250 && y==650){
                
                color.set(179,128,105,alpha);
                
                
            }
            
            //7
            else if (x==300 && y==650){
                
                color.set(200,148,122,alpha);
                
            }
            
            //8
            else if (x==350 && y==650){
                
                color.set(225,179,151,alpha);
                
            }
            
            //9
            
            else if (x==350 && y==650){
                
                color.set(114,81,74,alpha);
                
            }
            
            //10
            
            else if (x==400 && y==650){
                
                color.set(161,133,123,alpha);
                
            }
            
            //11
            
            else if (x==450 && y==650){
                
                color.set(244,227,211,alpha);
                
            }
            
            //12
            
            else if (x==500 && y==650){
                
                color.set(246,229,215,alpha);
                
            }
            
            //15TH ROW
            
            //1
            
            if (x==0 && y==650){
                
                color.set(229,224,223,alpha);
                
                
            }
            //2
            
            else if (x==50 && y==700){
                
                color.set(103,81,83,alpha);
            }
            
            //3
            else if (x==100 && y==700){
                
                color.set(65,42,44,alpha);
                
            }
            
            //4
            else if (x==150 && y==700){
                
                
                color.set(131,94,83,alpha);
                
            }
            
            //5
            else if (x==200 && y==700){
                
                color.set(158,108,90,alpha);
                
                
            }
            
            //6
            
            else if (x==250 && y==700){
                
                color.set(189,134,113,alpha);
                
                
            }
            
            //7
            else if (x==300 && y==700){
                
                color.set(235,183,156,alpha);
                
            }
            
            //8
            else if (x==350 && y==700){
                
                color.set(200,154,130,alpha);
                
            }
            
            //9
            
            else if (x==350 && y==700){
            
                color.set(144,107,93,alpha);
                
            }
            
            //10
            
            else if (x==400 && y==700){
                
                color.set(118,86,81,alpha);
                
            }
            
            //11
            
            else if (x==450 && y==700){
                
                color.set(243,225,209,alpha);
                
            }
            
            //12
            
            else if (x==500 && y==700){
                
                color.set(245,228,214,alpha);
                
            }
            
            
//            else{
//            
//                ofSetColor(ofColor(0,201,197,alpha));
//
//            
//            
//            }
            
//
//             ofSetColor(ofColor(227,213,206,alpha));
//             cout << color << endl;
            cout << color << endl;
            ofSetColor(color);
            ofDrawRectangle(x,y,50,50);
        }
        
        
//        cout << color << endl;
//        ofDrawRectangle(x,y,50,50);
    }
    
    
    
   
    
}
