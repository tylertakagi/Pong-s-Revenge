#include "ofApp.h"
#include "Ball.h"
#include "Paddle.h"
using namespace std;

const int START_SCREEN = 0;
const int GAME_SCREEN = 1;
const int GAME_OVER_SCREEN = 2;

int gameState = START_SCREEN;

void ofApp::setup() {
    ofSetBackgroundColor(0);
    
    myBullet.load("gunShot.mp3");
    myPaddle.load("paddleBlip.mp3");
    mycPaddle.load("cpaddleBlip.mp3");
    noAmmo.load("noAmmo.mp3");
    
    xBall = new Ball( ofGetWidth()/2, ofGetHeight()/2, 15, 1.25, 1.25, 0, 3, ofColor(0, 255, 0) );
    pPaddle = new Paddle( 1, (ofGetHeight() / 2), 20, 100, 0, ofColor(0, 0, 255) );
    cPaddle = new Paddle( (ofGetWidth() / 2) +620, (ofGetHeight() / 2), 20, 100, 0, ofColor(255, 0, 0) );
    bullet = new Ball(-100, -100, 10, 10, 10, 10, 10, ofColor(0,255,0));
}

void ofApp::update() {
    
    pPaddle->paddle_move(pPaddle);
    cPaddle->paddle_move(cPaddle);
    bullet->bulletMove();
    
    if ((xBall->x - xBall->r - 18) <= (pPaddle->x + pPaddle->w)) {
        if (xBall->y >= pPaddle->y) {
            if (xBall->y <= pPaddle->y + pPaddle->h) {
                xBall->xV *= -1.5;
                ++xBall->score;
                myPaddle.play();
            }
        }
    }
    
    if ((xBall->x - xBall->r ) <= (pPaddle->x + pPaddle->w)) {
        if (xBall->y >= pPaddle->y + pPaddle->h) {
          xBall->yV *= -1.5;
        }
    }
    
    if ((xBall->x + xBall->r + 30) >= (cPaddle->x + cPaddle->w)) {
        if (xBall->y >= cPaddle->y) {
            if (xBall->y <= cPaddle->y + cPaddle->h) {
                xBall->xV *= -1.5;
                mycPaddle.play();
            }
        }
    }

    if ((bullet->x + bullet->r) >= (cPaddle->x)) {
        if ((bullet->y) <= (cPaddle->y + cPaddle->h)) {
            if ((bullet->y) >= (cPaddle->y)) {
                cPaddle->v *= 8;
                xBall->score += 1;
                xBall->xV *= 0.5;
                xBall->yV = 0;
                bullet->x = -100;
                bullet->y = -100;
            }
        }
    }
    
    if (bullet->x >= ofGetWindowWidth()) {
        bullet->x = -100;
        bullet->y = -100;
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
    logo.draw( (ofGetWidth()/2) - 355, (ofGetHeight()/2) - 41.5 );

}

void ofApp::drawGameScreen() {
    ofSetColor(0, 255, 0);
    myFont.load("arcade.ttf", 20);
    
    std::string str_score = "Score: ";
    str_score += ofToString(xBall->score);
    
    string blt_counter = "Bullets: ";
    blt_counter += ofToString(bullet->lives);
    
    myFont.drawString(str_score, (ofGetWidth() / 2) - 50, 25);
    myFont.drawString(blt_counter, (ofGetWidth()/2) - 50, 50);
    
    xBall->draw();
    bullet->draw();
    pPaddle->draw();
    cPaddle->draw();
    cPaddle->track(xBall);
    
    
    if (xBall->lives == 3) {
        ofSetColor(0, 255, 0);
        ofDrawCircle((ofGetWindowWidth() - ((xBall->r * 1) + 1)), xBall->r, xBall->r);
        ofDrawCircle((ofGetWindowWidth() - ((xBall->r * 3) + 1)), xBall->r, xBall->r);
        ofDrawCircle((ofGetWindowWidth() - ((xBall->r * 5) + 1)), xBall->r, xBall->r);
    } else if (xBall->lives == 2) {
        ofSetColor(0, 255, 0);
        ofDrawCircle((ofGetWindowWidth() - ((xBall->r  * 1) + 1)), xBall->r , xBall->r );
        ofDrawCircle((ofGetWindowWidth() - ((xBall->r  * 3) + 1)), xBall->r , xBall->r );
    } else if (xBall->lives == 1) {
        ofSetColor(0, 255, 0);
        ofDrawCircle((ofGetWindowWidth() - ((xBall->r  * 1) + 1)), xBall->r , xBall->r );
    } else if (xBall->lives == 0) {
        gameState++;
    }
}

void ofApp::drawGameOverScreen() {
    ofSetColor(0, 255, 0);
    gameOver.load("gameover.png");
    gameOver.draw((ofGetWidth()/2) - 220, (ofGetHeight()/2));
    myFont.drawString("YOUR SCORE IS", (ofGetWidth()/2) - 125, (ofGetHeight()/2) - 50);
    myFont.drawString(ofToString(xBall->score),(ofGetWidth()/2), (ofGetHeight()/2) - 20);
    

    


}

void ofApp::keyPressed(int key) {
    if (key == OF_KEY_RETURN) {
    gameState = (gameState + 1) % 3;
    }
    
    if (key == OF_KEY_TAB) {
        if (bullet->lives <= 10) {
            bullet->x = pPaddle->x + pPaddle->w;
            bullet->y = pPaddle->y + pPaddle->h / 2;
            myBullet.play();
        }
        
        if (bullet->lives < 0) {
            bullet->lives = 0;
        }
        else if (bullet->lives > 0) {
            bullet->lives -= 1;
        }
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
