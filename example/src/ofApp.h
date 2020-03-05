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
    ofColor col1  = {255,  255,   0};
    ofColor col2  = {  0,  0, 255};

    std::vector<std::pair<glm::vec3, ofColor>> colorPalette;
    std::vector<string> types;
};
