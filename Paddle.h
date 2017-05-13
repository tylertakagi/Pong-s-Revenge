#pragma once
#include "ofMain.h"
#include "Ball.h"

class Paddle {
    
    
public:
    
    int x;
    int y;
    int w;
    int h;
    float v;
    ofColor color;
    
    Paddle();
    Paddle(int x, int y, int w, int h, float v, ofColor color);
    
    void draw();
    void MoveUp();
    void MoveDown();
    void track(Ball *b);
    void paddle_move(Paddle *p);
    void upKey();
    void downKey();
};

