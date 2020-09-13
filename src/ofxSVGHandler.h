//
//  ofxSVGHandler.hpp
//
//  Created by okuyama on 2020/09/14.
//
#include "ofMain.h"
#include "ofxSVG.h"
class ofxSVGHandler{
public:
    void load(string path="sample.svg");
    void draw();
    void setIsWireFrame(bool toggle);
    bool getIsWireFrame();
    
private:
    void drawWireFrame();
    bool isWireFrame = false;
    ofxSVG svg;
    vector<ofPolyline> outlines;
};
