#include "trackerNode.h"

//--------------------------------------------------------------
trackerNode::trackerNode() {

	position= ofVec3f(0,0,0);
	angle	= tilt = pan = roll = 0;		
	scale	= 1;
	target.setParent(*this);
	target.setPosition(0,0,0);
	initParent();
}

//--------------------------------------------------------------
void trackerNode::customDraw() {

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
void trackerNode::initParent() {
	parent.resetTransform();

	parent.setPosition(position);
	ofQuaternion quat = ofQuaternion(angle, tilt, pan, roll);
	parent.setOrientation(quat);
	parent.setScale(scale*1000);

	setParent(parent);
}

//--------------------------------------------------------------
void trackerNode::setTilt(float v) {
	tilt=v;
	cout << "tilt" << tilt << endl;	
	initParent();
}

//--------------------------------------------------------------
void trackerNode::setPan(float v) {
	pan=v;
	cout << "pan" << pan << endl;	
	initParent();
}

//--------------------------------------------------------------
void trackerNode::setRoll(float v) {
	roll=v;
	cout << "roll" << roll << endl;	
	initParent();
}

//--------------------------------------------------------------
void trackerNode::setAngle(float v) {
	angle=v;
	cout << "angle" << angle << endl;	
	initParent();
}

//--------------------------------------------------------------
void trackerNode::setScale(float v) {
	scale=v;
	cout << "scale" << scale << endl;	
	initParent();
}

//--------------------------------------------------------------
float trackerNode::getTilt() {
	return tilt;
	cout << "tilt" << tilt << endl;	
}

//--------------------------------------------------------------
float trackerNode::getPan() {
	return pan;
	cout << "pan" << pan << endl;		
}

//--------------------------------------------------------------
float trackerNode::getRoll() {
	return roll;
	cout << "roll" << roll << endl;		
}

//--------------------------------------------------------------
float trackerNode::getAngle() {
	return angle;
	cout << "angle" << angle << endl;		
}

//--------------------------------------------------------------
float trackerNode::getScale() {
	return scale;
}
	