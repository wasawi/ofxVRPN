#include "dataTracker.h"

//--------------------------------------------------------------
dataTracker::dataTracker() {

	position= ofVec3f(-30,-600,0);			// Some values in case there is no tracker
	angle	= tilt = pan = roll = 0;		
	scale	= 2;							
	target.setParent(*this);
	target.setPosition(.33,0,0);			//	target.setPosition(.33,0,0);
	initParent();
}

//--------------------------------------------------------------
void dataTracker::customDraw() {

//	parent.draw();
//	ofDrawAxis(.2);

//	Draw box;	
	ofSetColor(ofColor::white);
	ofBox(.01);
//	Draw TRACKER;	
	ofPushStyle();
	ofSetLineWidth(5);
	ofVec3f startTracker;
	ofVec3f endTracker = target.getPosition()-ofVec3f(.1,0,0);
	ofLine(startTracker,endTracker);
	ofPopStyle();
//	Draw red line;
	ofSetColor(ofColor::red);
	ofLine(endTracker,target.getPosition());

}

//--------------------------------------------------------------
void dataTracker::initParent() {
	parent.resetTransform();

	parent.setPosition(position);
	ofQuaternion quat = ofQuaternion(angle, tilt, pan, roll);
	parent.setOrientation(quat);
	parent.setScale(scale*1000);

	setParent(parent);
}

//--------------------------------------------------------------
void dataTracker::setTilt(float v) {
	tilt=v;
	cout << "tilt" << tilt << endl;	
	initParent();
}

//--------------------------------------------------------------
void dataTracker::setPan(float v) {
	pan=v;
	cout << "pan" << pan << endl;	
	initParent();
}

//--------------------------------------------------------------
void dataTracker::setRoll(float v) {
	roll=v;
	cout << "roll" << roll << endl;	
	initParent();
}

//--------------------------------------------------------------
void dataTracker::setAngle(float v) {
	angle=v;
	cout << "angle" << angle << endl;	
	initParent();
}

//--------------------------------------------------------------
void dataTracker::setScale(float v) {
	scale=v;
	cout << "scale" << scale << endl;	
	initParent();
}

//--------------------------------------------------------------
float dataTracker::getTilt() {
	return tilt;
	cout << "tilt" << tilt << endl;	
}

//--------------------------------------------------------------
float dataTracker::getPan() {
	return pan;
	cout << "pan" << pan << endl;		
}

//--------------------------------------------------------------
float dataTracker::getRoll() {
	return roll;
	cout << "roll" << roll << endl;		
}

//--------------------------------------------------------------
float dataTracker::getAngle() {
	return angle;
	cout << "angle" << angle << endl;		
}

//--------------------------------------------------------------
float dataTracker::getScale() {
	return scale;
}
	