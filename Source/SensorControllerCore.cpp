/*
  ==============================================================================

    SensorControllerCore.cpp
    Created: 10 Aug 2016 2:18:25pm
    Author:  czy_jerry

  ==============================================================================
*/

#include "Headers/SensorControllerCore.h"

#pragma comment (lib, "kinect20.lib")

SensorControllerCore::SensorControllerCore() : Thread("Sensor Controller Thread")
{

}

SensorControllerCore::~SensorControllerCore()
{

}

bool SensorControllerCore::check()
{

	return true;
}


void SensorControllerCore::run()
{

}
