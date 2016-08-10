/*
  ==============================================================================

    SensorControllerCore.h
    Created: 10 Aug 2016 11:24:57am
    Author:  czy_jerry

  ==============================================================================
*/

#ifndef SENSORCONTROLLERCORE_H_INCLUDED
#define SENSORCONTROLLERCORE_H_INCLUDED

#include<Kinect.h>
#include "JuceHeader.h"

class SensorControllerCore : public Thread
{
public:
	SensorControllerCore();
	~SensorControllerCore();

	bool check();
	void run() override;
private:

};

#endif  // SENSORCONTROLLERCORE_H_INCLUDED
