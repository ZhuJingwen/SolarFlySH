#pragma once

#include "ofMain.h"
#include"Leaf.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    ofImage branch;
    vector<Leaf> leaf;
    int light;
    int timeSH,timeNY;
    float timepercentSH, timepercentNY;
    int hourSH, minuteSH, secondSH,hourNY,minuteNY,secondNY;
    float angle,r, sunSHx, sunSHy, sunNYx, sunNYy;
    
};
