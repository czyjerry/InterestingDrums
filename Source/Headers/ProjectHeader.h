/*
  ==============================================================================

    ProjectHeader.h
    Created: 10 Aug 2016 3:21:38pm
    Author:  czy_jerry

  ==============================================================================
*/

#ifndef PROJECTHEADER_H_INCLUDED
#define PROJECTHEADER_H_INCLUDED

#define SCREEN_WIDTH getWidth()
#define SCREEN_HEIGHT getHeight()

#define FPS 60.0

struct Point3D
{
	double x;
    double y;
    double z;
};

#include"SensorControllerCore.h"

#ifdef SENSORCONTROLLERCORE_CLASS
#include"DataModelCore.h"
#endif

#ifdef DATAMODELCORE_CLASS
#include"GlViewCore.h"
#include"JuceAudioCore.h"
#endif

#endif  // PROJECTHEADER_H_INCLUDED
