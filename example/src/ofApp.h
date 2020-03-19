#pragma once

#include "ofMain.h"
#include "ofxColorMorph.h"
#include "ofxImGui.h"

using namespace ofxColorMorph;

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void generate(ofColor col1, ofColor col2);
private:
    ofColor col1  = {255,  0,   0};
    ofColor col2  = {  0,  0, 255};
    ofColor color;
    ofFloatColor guiCol1;
    ofFloatColor guiCol2;

    std::vector<std::pair<glm::vec3, ofColor>> colorPalette;
    std::vector<string> types;
    
    //Gui
    ofxImGui::Gui gui;
    bool window;
};
