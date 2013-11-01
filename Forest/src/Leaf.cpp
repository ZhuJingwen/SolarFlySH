//
//  Leaf.cpp
//  Forest
//
//  Created by 朱静文 on 13-10-29.
//
//

#include "Leaf.h"
// ----------------------------------
void Leaf::initialize(float x, float y)
{
    radius = ofRandom(10,30);
    born = ofGetElapsedTimef();
    pos.set(x,y);
    color.setHsb(ofRandom(227,241),200,200);
}

// ----------------------------------
void Leaf::updateMe()
{
    float age = ofGetElapsedTimef() - born;
    color.a = ofMap(age,0,5,255,0);
    
}

// ----------------------------------
void Leaf::drawMe()
{
    ofSetColor(color);
    ofCircle(pos,radius);
}