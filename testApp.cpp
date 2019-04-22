#include "testApp.h"
//--------------------------------------------------------------

// Delauney triangulation sketch
// Implemented with the ofxDelauney addon

// The aim is to create an animation in which the dots of the triangles of the 3D structure mesh are randomly connected to form new lines and triangles
// To do so, the points (junctions of the triangles) are stored in an array 'pts'
// Triangles are spontaneously created with random points


void testApp::setup(){
    ofEnableSmoothing();
    ofBackground(0);
    
    // 'merged.png' is the uv of the 3d structure
    // It is used as the background
    back.load("merged.png");
    
    // uv points
    // I've used 12 points
    // Note : this is not the final version of the uvmap
    pts[0].x = 50;
    pts[0].y = 350;
    pts[1].x = 8;
    pts[1].y = 391;
    pts[2].x = 33;
    pts[2].y = 440;
    pts[3].x = 131;
    pts[3].y = 446;
    pts[4].x = 250;
    pts[4].y = 500;
    pts[5].x = 302;
    pts[5].y = 499;
    pts[6].x = 404;
    pts[6].y = 463;
    pts[7].x = 316;
    pts[7].y = 401;
    pts[8].x = 425;
    pts[8].y = 261;
    pts[9].x = 322;
    pts[9].y = 223;
    pts[10].x = 187;
    pts[10].y = 273;
    pts[11].x = 100;
    pts[11].y = 338;
    
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------

void testApp::draw(){

// Cursor
// To check the coordinates of the points when the sketch is running
// And to store these points in the array 'pts'
    ofPoint p;
    p.x = ofGetMouseX();
    p.y = ofGetMouseY();
    ofSetLineWidth(2);
    ofSetColor(255);
    ofDrawLine (p.x, p.y, p.x + 2, p.y + 2);
    ofDrawBitmapString(ofGetMouseX(), 50, 50);
    ofDrawBitmapString(ofGetMouseY(), 50, 70);
    ofDrawBitmapString("'r' to reset", ofPoint(10,20));
    
    
// Background
    ofSetColor(255);
    back.draw(0,0);
    
// Fill the vector 'triangulation' with the points...
    if(ofGetFrameNum() % 5 == 0){
        if (triangulation.getNumPoints() < 11){
        int r = ofRandom(11);
        triangulation.addPoint(pts[r]);
        }
// ... while removing some points of the array
// to keep creating the random effect
        if (triangulation.getNumPoints() >= 11){
        int t1 = ofRandom(1, 11);
        int t2 = ofRandom(1, 11);
        int t3 = ofRandom(1, 11);
        int t4 = ofRandom(1, 11);

        triangulation.removePointAtIndex(triangulation.getNumPoints());
        triangulation.removePointAtIndex(triangulation.getNumPoints() - t1);
        triangulation.removePointAtIndex(triangulation.getNumPoints() - t2);
        triangulation.removePointAtIndex(triangulation.getNumPoints() - t3);
        triangulation.removePointAtIndex(triangulation.getNumPoints() - t4);

        }
    }

// Draw the randomly formed triangles
    ofNoFill();
    triangulation.triangulate();
    triangulation.draw();

    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'r'){
        triangulation.reset();
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
