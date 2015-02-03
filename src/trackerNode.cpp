#include "tracker.h"

//--------------------------------------------------------------
tracker::tracker() {

	position= ofVec3f(-30,-600,0);			// Some values in case there is no tracker
	angle	= tilt = pan = roll = 0;		
	scale	= 2;							
	target.setParent(*this);
	target.setPosition(.33,0,0);			//	target.setPosition(.33,0,0);
	initParent();
}

//--------------------------------------------------------------
void tracker::customDraw() {

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
void tracker::initParent() {
	parent.resetTransform();

	parent.setPosition(position);
	ofQuaternion quat = ofQuaternion(angle, tilt, pan, roll);
	parent.setOrientation(quat);
	parent.setScale(scale*1000);

	setParent(parent);
}

//--------------------------------------------------------------
void tracker::setTilt(float v) {
	tilt=v;
	cout << "tilt" << tilt << endl;	
	initParent();
}

//--------------------------------------------------------------
void tracker::setPan(float v) {
	pan=v;
	cout << "pan" << pan << endl;	
	initParent();
}

//--------------------------------------------------------------
void tracker::setRoll(float v) {
	roll=v;
	cout << "roll" << roll << endl;	
	initParent();
}

//--------------------------------------------------------------
void tracker::setAngle(float v) {
	angle=v;
	cout << "angle" << angle << endl;	
	initParent();
}

//--------------------------------------------------------------
void tracker::setScale(float v) {
	scale=v;
	cout << "scale" << scale << endl;	
	initParent();
}

//--------------------------------------------------------------
float tracker::getTilt() {
	return tilt;
	cout << "tilt" << tilt << endl;	
}

//--------------------------------------------------------------
float tracker::getPan() {
	return pan;
	cout << "pan" << pan << endl;		
}

//--------------------------------------------------------------
float tracker::getRoll() {
	return roll;
	cout << "roll" << roll << endl;		
}

//--------------------------------------------------------------
float tracker::getAngle() {
	return angle;
	cout << "angle" << angle << endl;		
}

//--------------------------------------------------------------
float tracker::getScale() {
	return scale;
}
	