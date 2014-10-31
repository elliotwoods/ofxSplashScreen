#pragma once

#include "ofImage.h"
#include "ofAppGLFWWindow.h"

class ofxSplashScreen {
public:
	ofxSplashScreen();
	void init(string filename);
	void init(ofPixels &);
	void init(ofImage &);

	void begin(float minimumDuration = 3.0f);
	void end();
protected:
	float endTime;
	ofImage image;
	GLFWwindow * appWindow, * splashScreenWindow;
};