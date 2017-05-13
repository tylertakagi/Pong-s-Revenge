#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "Paddle.h"

class ofApp : public ofBaseApp{

	public:
        Ball* xBall;
        Ball* bullet;
        Paddle* pPaddle;
        Paddle* cPaddle;
    
		void setup();
		void update();
		void draw();
    
        void drawStartScreen();
        void drawGameScreen();
        void drawGameOverScreen();
    
        ofImage logo;
        ofTrueTypeFont myFont;

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
