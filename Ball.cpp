#include "Ball.h"
#include "ofMain.h"
#include "Paddle.h"

Ball::Ball () {
    
}

Ball::Ball(float x, float y, int r, float xV, float yV, int score, ofColor color) {
    this->x = x;
    this->y = y;
    this->r = r;
    this->xV = xV;
    this->yV = yV;
    this->score = score;
    this->color = color;
}

void Ball::draw() {
    ofSetColor(color);
    ofDrawCircle(x, y, 2*r);
    ofSetCircleResolution(100);
}

void Ball::move() {
    x += xV;
    y += yV;
    
    if (x <= r) {
        x = r;
        xV *= -1;
    }
    else if (x >= ofGetWindowWidth() - r) {
        x = ofGetWindowWidth() - r;
        xV *= -1;
    }
    
    if (y <= r) {
        y = r;
        yV *= -1;
    }
    else if (y >= ofGetWindowHeight() - r) {
        y = ofGetWindowHeight() - r;
        yV *= -1;
    }
}

void Ball::bulletMove() {
    x += 1;
}
