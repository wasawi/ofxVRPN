#pragma once

#include "ofMain.h"
#include "ofNode.h"

class tracker : public ofNode
{
public:
	tracker();
	void customDraw();
	void drawBox();
	void initParent();

	void setTilt(float v);
	void setPan(float v);
	void setRoll(float v);
	void setAngle(float v);
	void setScale(float v);

	float getTilt();
	float getPan();
	float getRoll();
	float getAngle();
	float getScale();

	ofNode target;
	
	//Other Tracker and Sound status Variables
	float playsoundelapsedtime;
	bool wiiButtonA;
	bool wiiButtonB;
	string filename;
	int time;

private:
	ofVec3f position;
	float angle, tilt, pan, roll;
	float scale;
	ofNode parent;
};