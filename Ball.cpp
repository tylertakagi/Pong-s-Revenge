#include "Ball.h"
#include "ofMain.h"
#include "Paddle.h"

Ball::Ball () {
    
}

Ball::Ball(float x, float y, int r, float xV, float yV, int score, int lives, ofColor color) {
    this->x = x;
    this->y = y;
    this->r = r;
    this->xV = xV;
    this->yV = yV;
    this->score = score;
    this->lives = lives;
    this->color = color;
}

void Ball::draw() {
    ofSetColor(0, 255, 0);
    ofNoFill();
    ofDrawCircle(x, y, 2*r);
    ofSetCircleResolution(100);
}

void Ball::reset() {
    x = ofGetWidth() / 2;
    y = ofGetHeight() / 2;
    xV = 1.25;
    yV = -1.25;
}

void Ball::bulletMove() {
    x += 20;
}

void Ball::move() {
    y += yV;
    x += xV;
    
    if (x <= r) {
        x = r;
        xV *= -1;
        --score;
        --lives;
    } else if (x >= ofGetWindowWidth() - r) {
        x = ofGetWindowWidth() - r;
        xV = -1.25;
        ++score;
        reset();
    }
    
    if (y <= r) {
        y = r;
        yV *= -1;
    } else if (y >= ofGetWindowHeight() - r) {
        y = ofGetWindowHeight() - r;
        yV *= -1;
    }
    
}


