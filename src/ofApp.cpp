#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);

    width  = ofGetWidth();
    height = ofGetHeight();

    // Initial Allocation
    //
    fluid.allocate(width, height, .5);

    // Seting the gravity set up & injecting the background image
    //
    fluid.dissipation = 0.999;
    fluid.velocityDissipation = 0.99;

    fluid.setGravity(ofVec2f(0.0, .1));
    // fluid.setGravity(ofVec2f(0.0,0.0098));

    //  Set obstacle
    //

    fluid.begin();
    //ofClear(0,0,0, 0);// Black.

    // Draw the font.
    font.loadFont("Arial",70);
    font.setLetterSpacing(1.2);
    font.align = font.CENTER;

    ofSetColor(255, 255, 255);
    font.drawString("The Hidden Message!", ofGetWidth()/2, ofGetHeight()/2, 300);

    fluid.end();


    //ofTexture tex = fbo.getTextureReference();
    //fluid.setObstacles(tex);

    // Adding constant forces
    //

    for(float x = .2; x <= .9; x += .1)
    {
        addSource(x, .25);
    }

    //ofSetWindowShape(width, height);
}

void ofApp::addSource(float x, float y)
{
    fluid.addConstantForce(ofPoint(width*x,height*y), ofPoint(0,-3), ofFloatColor(0.5,0.1,0.0), 10.f);
}

//--------------------------------------------------------------
void ofApp::update(){

    // Adding temporal Force
    //
    ofPoint m = ofPoint(mouseX,mouseY);
    ofPoint d = (m - oldM)*10.0;
    oldM = m;
    ofPoint c = ofPoint(640*0.5, 480*0.5) - m;
    c.normalize();
    fluid.addTemporalForce(m, d, ofFloatColor(c.x,c.y,0.5)*sin(ofGetElapsedTimef()),3.0f);

    //fluid.setGravity(ofVec2f(.1*sin(ofGetElapsedTimef()),.1*cos(ofGetElapsedTimef())));

    //  Update
    //
    fluid.update();

    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray, ofColor::black, OF_GRADIENT_LINEAR);

    fluid.draw();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 'p')
        bPaint = !bPaint;
    if( key == 'o')
        bObstacle = !bObstacle;
    if( key == 'b')
        bBounding = !bBounding;
    if( key == 'c')
        bClear = !bClear;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
