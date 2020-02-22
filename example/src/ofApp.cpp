#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofRectMode(OF_RECTMODE_CENTER);
    
    
    for(auto i=0; i < 11; ++i){
        glm::vec3 left = {70, 100+i*40, 0.0};
        glm::vec3 right = {470, 100+i*40, 0.0};
        for(auto j = 0; j < 400; j += 40){
            glm::vec3 pos = {j+70, 50+i*40, 0.0};
            ofColor color = colorMorph(pos, left, col1, right, col2, static_cast<type>(i));
            colorPalette.push_back(std::make_pair(pos, color));
        }
    }
    
    types = {"RGB", "HSL", "HSB", "HSV", "LUV", "LAB", "HunterLAB", "LCH", "CMY", "CMYK", "YXY"};
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle( "fps: " + ofToString( ofGetFrameRate(), 1 ) );
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(auto&& c : colorPalette){
        ofSetColor(c.second);
        ofDrawRectangle(c.first, 30, 30);
    }
    for(auto i = 0; i < 11; ++i){
        ofDrawBitmapString(types.at(i), 480, 70+i*40);
    }
}
