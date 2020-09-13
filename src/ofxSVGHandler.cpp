//
//  ofxSVGHandler.cpp
//  logoWireFramer
//
//  Created by okuyama on 2020/09/14.
//

#include "ofxSVGHandler.h"

void ofxSVGHandler::load(string path){
    svg.load(path);
    for (ofPath p: svg.getPaths()){
        p.setPolyWindingMode(OF_POLY_WINDING_ODD);
        const vector<ofPolyline>& lines = p.getOutline();
        for(const ofPolyline & line: lines){
            outlines.push_back(line.getResampledBySpacing(1));
        }
    }
}

void ofxSVGHandler::draw(){
    ofPushMatrix();
    ofScale(1.0,-1.0,1.0);
    ofTranslate(-svg.getWidth()/2,-svg.getHeight()/2.0);
    
    if(isWireFrame){
        drawWireFrame();
    }else{
        svg.draw();
    }
    ofPopMatrix();
}

void ofxSVGHandler::drawWireFrame(){
    ofNoFill();
    for (ofPolyline & line: outlines){
        int num = line.size();
        ofBeginShape();
        for (int j = 0; j < num; j++){
            ofVertex(line[j]);
        }
        ofEndShape();
    }
    ofFill();
}

void ofxSVGHandler::setIsWireFrame(bool toggle){
    isWireFrame = toggle;
}
bool ofxSVGHandler::getIsWireFrame(){
    return  isWireFrame;
}
