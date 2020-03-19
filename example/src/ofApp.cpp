#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofRectMode(OF_RECTMODE_CENTER);
    
    //Gui
    gui.setup();
    window = true;
    
    for(auto i=0; i < 12; ++i){
        glm::vec3 left = {270, 120+i*40, 0.0};
        glm::vec3 right = {670, 120+i*40, 0.0};
        for(auto j = 0; j <= 400; j += 40){
            glm::vec3 pos = {j+270, 120+i*40, 0.0};
            ofColor color = colorMorph(pos, left, col1, right, col2, static_cast<type>(i));
            colorPalette.push_back(std::make_pair(pos, color));
        }
    }
    
    types = {"RGB", "HSL", "HSV", "HSB", "LUV", "LAB", "HunterLAB", "LCH", "CMY", "CMYK", "YXY", "XYZ"};
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle( "fps: " + ofToString( ofGetFrameRate(), 1 ) );
//    ofLog() << color;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    gui.begin();
    if(window){
        ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiSetCond_Once);
        ImGui::SetNextWindowSize(ImVec2(250, 500), ImGuiSetCond_Once);
        ImGui::Begin("Gui", &window);
        ImGui::ColorPicker3("left color", &guiCol1[0]);
        ImGui::ColorPicker3("right color", &guiCol2[0]);
        col1 = guiCol1;
        col2 = guiCol2;
        if(ImGui::Button("generate")){
            generate(col1, col2);
        }
        ImGui::End();
    }
    gui.end();
    
    for(auto&& c : colorPalette){
        ofSetColor(c.second);
        ofDrawRectangle(c.first, 30, 30);
    }
    
    ofSetColor(255);
    for(auto i = 0; i < 12; ++i){
        ofDrawBitmapString(types.at(i), 710, 140+i*40);
    }
}

void ofApp::generate(ofColor col1, ofColor col2){
    for(auto i=0; i < 12; ++i){
        glm::vec3 left = {270, 120+i*40, 0.0};
        glm::vec3 right = {670, 120+i*40, 0.0};
        for(auto j = 0; j <= 400; j += 40){
            glm::vec3 pos = {j+270, 120+i*40, 0.0};
            ofColor color = colorMorph(pos, left, col1, right, col2, static_cast<type>(i));
            colorPalette.push_back(std::make_pair(pos, color));
        }
    }
}
