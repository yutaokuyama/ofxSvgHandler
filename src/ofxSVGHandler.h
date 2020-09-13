//
//  ofxSVGHandler.hpp
//  logoWireFramer
//
//  Created by okuyama on 2020/09/14.
//
#include "ofMain.h"
#include "ofxSVG.h"
class ofxSVGHandler{
public:
    void load(string path="sample.svg");
    void draw();
    void drawWireFrame();
    void setIsWireFrame(bool toggle);
    bool getIsWireFrame();
    
private:
    bool isWireFrame = false;
    ofxSVG svg;
    vector<ofPolyline> outlines;
};
