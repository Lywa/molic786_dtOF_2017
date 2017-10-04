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
    
}


// define square
void Square::draw(){
    
    alpha=255;


    
    for (int x=0; x<ofGetWidth(); x+=50){
        
        
        
        for (int y=0; y<ofGetHeight();y+=50){
            
            //1ST ROW
            
            //1

            if (x==0 && y==0){
            //ofSetColor(ofColor(227,213,206,alpha));
                
                
                ofColor color_1_1(227,213,206,alpha);
                ofSetColor(color_1_1);
            
                cout << color_1_1 << endl;
            
            }
            //2
            
            if (x==50 && y==0){
                
                ofColor color_1_2(225,210,203,alpha);
                ofSetColor(color_1_2);
                cout << color_1_2 << endl;

            
            }
            
            //3
            if (x==100 && y==0){
                
                ofColor color_1_3(ofColor(226,211,204,alpha));
                ofSetColor(color_1_3);
                cout << color_1_3 << endl;
                
            
            }
            
            //4
            if (x==150 && y==0){
                
                ofColor color_1_4(220,201,197,alpha);
                ofSetColor(color_1_4);
                cout << color_1_4 << endl;

    
                
            }
            
            //5
            if (x==200 && y==0){
                
                ofColor color_1_5(181,147,156,alpha);
                ofSetColor(color_1_5);

                
            }
            
            //6
        
            if (x==250 && y==0){
                
                ofColor color_1_6(220,201,197,alpha);
                ofSetColor(color_1_6);
                

                
            }
            
            //7
            if (x==300 && y==0){
                
                ofColor color_1_7(229,215,207,alpha);
                ofSetColor(color_1_7);
            
                
                
            }
                           
            //8
                           
                           
            
            
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
             ofDrawRectangle(x,y,50,50);
        }
        
        
//        cout << color << endl;
//        ofDrawRectangle(x,y,50,50);
    }
    
    
    
   
    
}
