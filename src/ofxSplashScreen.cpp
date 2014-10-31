#include "ofxSplashScreen.h"

#include "ofMain.h"

//----------
ofxSplashScreen::ofxSplashScreen() {
	this->appWindow = nullptr;
	this->splashScreenWindow = nullptr;
}

//----------
void ofxSplashScreen::init(string filename) {
	this->image.loadImage(filename);
}

//----------
void ofxSplashScreen::init(ofPixels & pixels) {
	this->image.setFromPixels(pixels);
	this->image.update();
}

//----------
void ofxSplashScreen::init(ofImage & image) {
	this->image = image;
}

//----------
void ofxSplashScreen::begin(float minimumDuration) {
	if (!this->image.isAllocated()) {
		ofLogError("ofxSplashScreen") << "Cannot show splash screen since no image has been loaded";
		return;
	}
	this->endTime = ofGetElapsedTimef() + minimumDuration;
	this->appWindow = glfwGetCurrentContext();
	
	glfwHideWindow(this->appWindow);
	glfwWindowHint(GLFW_DECORATED, GL_FALSE);
	this->splashScreenWindow = glfwCreateWindow(this->image.getWidth(), this->image.getHeight(), "ofxSplashScreen", NULL, this->appWindow);
	glfwSetWindowPos(this->splashScreenWindow, (ofGetScreenWidth() - this->image.getWidth()) / 2.0f, (ofGetScreenHeight() - this->image.getHeight()) / 2.0f);
	glfwWindowHint(GLFW_DECORATED, GL_TRUE);
	glfwMakeContextCurrent(this->splashScreenWindow);
	
	//set the drawing matrices to normalised coordinates
	ofSetMatrixMode(OF_MATRIX_PROJECTION);
	ofLoadIdentityMatrix();
	ofSetMatrixMode(OF_MATRIX_MODELVIEW);
	ofLoadIdentityMatrix();
	
	//draw the images
	ofClear(0,0,0);
	this->image.update();
	this->image.draw(-1,-1,2,2);
	glfwSwapBuffers(this->splashScreenWindow);
	glFlush();
	
	//set the context back to main for rest of setup
	glfwMakeContextCurrent(this->appWindow);
	ofSetupScreen();
}

//----------
void ofxSplashScreen::end() {
	if (!this->appWindow || !this->splashScreenWindow) {
		return;
	}
	
	while (endTime > ofGetElapsedTimef()) {
		ofSleepMillis(1);
	}
	
	glfwDestroyWindow(this->splashScreenWindow);
	this->splashScreenWindow = 0;
	
	glfwShowWindow(this->appWindow);
}