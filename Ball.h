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
    int lives;
    
    ofColor color;
    
    Ball();
    Ball(float x, float y, int s, float xV, float xY, int score, int lives, ofColor color);
    
    void draw();
    void move();
    void collide();
    void reset();
    void bulletMove();
};
