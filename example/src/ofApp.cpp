#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle( "fps: " + ofToString( ofGetFrameRate(), 1 ) );
}

//--------------------------------------------------------------
void ofApp::draw(){
    glm::vec3 target = {mouseX, mouseY, 0.0};
    //color type
    //RGB, HSL, HSB, HSV, LUV, LAB, HunterLAB, LCH, CMY, CMYK, YXY
    ofColor color = colorMorph(target, left, leftCol, right, rightCol, type::HSL);
    
    ofSetColor(leftCol);
    ofDrawRectangle(left, 50, 50);
    ofSetColor(rightCol);
    ofDrawRectangle(right, 50, 50);
    
    ofSetColor(color);
    ofDrawRectangle(target, 50, 50);
}
