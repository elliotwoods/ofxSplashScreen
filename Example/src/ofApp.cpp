#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup2(){
	//notice we change the setup function to be called setup2, and we run it on the second frame
	this->splashScreen.init("splashScreen.png");
	this->splashScreen.begin();
	//perform some heavy functions
	this->splashScreen.end();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (ofGetFrameNum() == 1) {
		this->setup2();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
