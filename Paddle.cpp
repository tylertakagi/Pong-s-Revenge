#include "Paddle.h"
#include "Ball.h"

Paddle::Paddle() {

}

Paddle::Paddle( int x, int y, int w, int h, float v, ofColor color) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->v = 0;
    this->color = color;
}

void Paddle::draw() {
    ofSetColor(color);
    ofDrawRectangle(x, y, w, h);
}

void Paddle::upKey() {
    y += 20;
}

void Paddle::downKey() {
    y -= 20;
}

void Paddle::MoveUp() {
    v += 1;
}

void Paddle::MoveDown() {
    v -= 1;
}


void Paddle::track(Ball *b) {
    if (b->y >= y + h) {
        MoveUp();
    } else if (b->y <= y) {
        MoveDown();
    }

}

void Paddle::paddle_move(Paddle *p) {
    y += v;
    if (y + w >= ofGetWidth()) {
        y = ofGetWidth() - w;
        v *= -0.1;
    }
    
    if (y <= 0) {
        y = 0;
        v *= -0.1;
    }
}
