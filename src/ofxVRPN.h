#pragma once

#include "ofMain.h"
//#include "trackerNode.h"

// VRPN
#include "vrpn_Connection.h" // Missing this file?  Get the latest VRPN distro at
#include "vrpn_Tracker.h"    //    ftp://ftp.cs.unc.edu/pub/packages/GRIP/vrpn


class ofxVRPN
{
public:
	
	ofxVRPN();
	~ofxVRPN();
	
	bool	setup( std::string hostname, int port );
	void	addTracker( std::string trackerName );
	
	
	void	update();
	void	updateTracker();
	void	draw();
//	tracker getData();
	bool	getIsConnected();
	
	ofVec3f getPosition();
	ofQuaternion getOrientation();
	
	// to activate or deactivate log
	bool	bUseLog, bUseAutoLog;
	ofNode	nodeT;
	
private:
	vrpn_Connection *connection;
	vrpn_Tracker_Remote *vrpnTracker;
	
	int			port;
	std::string hostname;
	std::string trackerName;
	char	connectionName[128];
	
	bool	bconnected;
	
	//--> Internal Event for ofxVRPN
    void callBackFunc(ofxEventManager::Event& e);
    ofxEventManager::Event eventObj;

	
	// Callback prototype from VRPN
	void VRPN_CALLBACK handle_pos (void *, const vrpn_TRACKERCB t);
};


