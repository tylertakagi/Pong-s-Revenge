#include "ofApp.h"
#include "Ball.h"
#include "Paddle.h"
using namespace std;

const int START_SCREEN = 0;
const int GAME_SCREEN = 1;
const int GAME_OVER_SCREEN = 2;

int gameState = START_SCREEN;

void ofApp::setup() {
    ofSetBackgroundColor(55);
    xBall = new Ball( ofGetWidth()/2, ofGetHeight()/2, 15, 5, 5, 0, ofColor(0, 255, 0) );
    pPaddle = new Paddle( 5, (ofGetHeight() / 2), 20, 100, 0, ofColor(0, 0, 255) );
    cPaddle = new Paddle( (ofGetWidth() / 2) +600, (ofGetHeight() / 2), 20, 100, 0, ofColor(255, 0, 0) );
    bullet = new Ball(-100, -100, 0, 10, 10, 0, ofColor(0,0,255));
}

void ofApp::update() {
    
    pPaddle->paddle_move(pPaddle);
    cPaddle->paddle_move(cPaddle);
    
    if ((xBall->x - xBall->r) <= (pPaddle->x + pPaddle->w)) {
        if (xBall->y >= pPaddle->y) {
            if (xBall->y <= pPaddle->y + pPaddle->h) {
                xBall->xV *= -1;
                ++xBall->score;
            }
        }
    }
    
    if ((xBall->x - xBall->r) <= (pPaddle->x + pPaddle->w)) {
        if (xBall->y >= pPaddle->y +30) {
          xBall->yV *= -1;
        }
    }
    
    if ((xBall->x + xBall->r + 30) >= (cPaddle->x + cPaddle->w)) {
        if (xBall->y >= cPaddle->y) {
            if (xBall->y <= cPaddle->y + cPaddle->h) {
                xBall->xV *= -1;
            }
        }
    }
}

void ofApp::draw() {
// DONT TOUCH
    if (gameState == START_SCREEN) {
        drawStartScreen();
    } else if (gameState == GAME_SCREEN) {
        drawGameScreen();
        xBall->move();
    } else if (gameState == GAME_OVER_SCREEN) {
        drawGameOverScreen();
    }
}

void ofApp::drawStartScreen() {
    logo.load("logo.png");
    logo.draw( (ofGetWidth()/2) - 378, (ofGetHeight()/2) - 41.5 );
}

void ofApp::drawGameScreen() {
    ofSetColor(0, 255, 0);
    myFont.load("spaceAge.ttf", 20);
    
    std::string str_score = "Score: ";
    str_score += ofToString(xBall->score);
    
    myFont.drawString(str_score, (ofGetWidth() / 2) - 50, 20);
    
    xBall->draw();
    pPaddle->draw();
    cPaddle->draw();
    cPaddle->track(xBall);

}

void ofApp::drawGameOverScreen() {
    ofDrawBitmapString("GAME OVER", ofGetWidth() / 2, ofGetHeight() / 2);

}

void ofApp::keyPressed(int key) {
    if (key == OF_KEY_RETURN) {
    gameState = (gameState + 1) % 3;
    }
    
    if (key == OF_KEY_UP) {
        pPaddle->upKey();
    }
    
    if (key == OF_KEY_DOWN) {
        pPaddle->downKey();
    }
}

void ofApp::keyReleased(int key) {

}

void ofApp::mouseMoved(int x, int y ) {
    pPaddle->y = y;

}

void ofApp::mouseDragged(int x, int y, int button) {

}

void ofApp::mousePressed(int x, int y, int button) {

}

void ofApp::mouseReleased(int x, int y, int button) {

}


void ofApp::mouseEntered(int x, int y) {

}

void ofApp::mouseExited(int x, int y) {

}

void ofApp::windowResized(int w, int h) {

}

void ofApp::gotMessage(ofMessage msg) {

}

void ofApp::dragEvent(ofDragInfo dragInfo) {

}
