#pragma once
#include "ofMain.h"


class Ball {

public:
    float x;
    float y;
    int r;
    int score;
    float xV;
    float yV;
    
    ofColor color;
    
    Ball();
    Ball(float x, float y, int s, float xV, float xY, int score, ofColor color);
    
    void draw();
    void move();
    void collide();
    void bulletMove();
};
