#pragma once

#include "ofMain.h"
#include "ofxColorMorph.h"

using namespace ofxColorMorph;

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
private:
    glm::vec3 left   = {100, 300, 0.0};
    glm::vec3 right  = {500, 300, 0.0};
    ofColor leftCol  = {255,   0,   0};
    ofColor rightCol = {  0, 255,   0};
};
