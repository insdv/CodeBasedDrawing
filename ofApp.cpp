#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	 fbo.allocate(ofGetWidth(), ofGetHeight());

	fbo.begin();
	ofClear(245, 243, 238, 255);
	fbo.end();
}

//--------------------------------------------------------------
void ofApp::update() {


	
}

//--------------------------------------------------------------
void ofApp::draw(){

    fbo.begin();

	if (bMousePressed == true) {

		ofPoint diff = ofPoint(mouseX, mouseY) - prevMouse;
		float speed = diff.length();

		if (speed < 2) {

			pauseSize += 0.3;

			if (pauseSize > 40) {
				pauseSize = 40;
			}

			ofSetColor(0, 0, 0, 10);
			ofDrawCircle(mouseX, mouseY, pauseSize);

		} else {

			pauseSize = 2;

			ofSetColor(0, 0, 0, 100);
			ofDrawLine(prevMouse.x, prevMouse.y, mouseX, mouseY);
		}

		prevMouse = ofPoint(mouseX, mouseY);
	}

	fbo.end();

	ofSetColor(255);
	fbo.draw(0, 0);
	}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


	  fbo.begin();
	ofClear(245, 243, 238, 255);
	fbo.end();

	pauseSize = 2;
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

    bMousePressed = true;
	prevMouse = ofPoint(x, y);
	pauseSize = 2;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

	    bMousePressed = false;

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
