#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(60);
    ofSetVerticalSync(TRUE);
    
    ofEnableAlphaBlending();
    ofBackground(255);
   
    branch.loadImage("Branch.png");
    
    //To get in the light data, now use a growing data instead
    light = 0;

}

//--------------------------------------------------------------
void testApp::update(){
    //To get the different time from Shanghai and New York
    timeSH = (ofGetUnixTime()+28800)%86400; //to change it to Shanghai Time
    timeNY = (ofGetUnixTime()-14400)%86400;
    
    //To monitor the time and light
    ofSetWindowTitle("light="+ofToString(light)+"time"+ofToString(timeSH));
    
    //To let the leaf class update and if the leaf die out, it will be erased
    for (int i = 0; i<leaf.size(); i++) {
        leaf[i].updateMe();
        if (leaf[i].color.a <1) {
            leaf.erase(leaf.begin()+i);
        }
    }
    
    //To let the leaf grow when light colleted
    if ((light % 100) == 0) {
        //r = ofRandom(0,300);
        float a = ofRandom(0,250);
        float b = ofRandom(0,300);
        Leaf l;
        angle = ofRandom(360);
        float x = a*cos(angle)+0.5*ofGetWidth();
        float y = b*sin(angle)+0.5*ofGetHeight();
        l.initialize(x, y);
        leaf.push_back(l);
    }
    
    //To update the light data
    light = light +1;
}

//--------------------------------------------------------------
void testApp::draw(){
   //To draw the sun according to time
    timepercentSH = timeSH/86400;
    timepercentNY = timeNY/86400;
    sunSHx = 100;
    sunSHy = 768*timeSH/86400;
    sunNYx = 924;
    sunNYy = 768*timeNY/86400;
    
    ofSetColor(215,25,32);
    ofCircle(sunSHx,sunSHy,50);
    ofCircle(sunNYx,sunNYy,50);
    
    //To show the time from Shanghai and New York
    hourSH = timeSH/3600;
    minuteSH = (timeSH%3600)/60;
    secondSH = (timeSH%3600)%60;
    hourNY = timeNY/3600;
    minuteNY = (timeNY%3600)/60;
    secondNY = (timeNY%3600)%60;
    
    //To write the time
    ofSetColor(20);
    ofDrawBitmapString("SH time "+ofToString(hourSH)+":"+ofToString(minuteSH)+":"+ofToString(secondSH), 20,748);
    ofDrawBitmapString("NY time "+ofToString(hourNY)+":"+ofToString(minuteSH)+":"+ofToString(secondSH), 880,748);
    
    //To draw the leaf
    for (int i = 0; i<leaf.size(); i++) {
        leaf[i].drawMe();
    }
    
    //To draw the brunch
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofSetColor(255);
    branch.draw(0,0,ofGetWidth(),ofGetHeight());
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
