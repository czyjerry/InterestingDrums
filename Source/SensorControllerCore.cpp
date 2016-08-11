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
	//Check whether Kinect Runtime Environment is running correctly
	return true;
}

void SensorControllerCore::UpdateSensorData()
{

}

void SensorControllerCore::run()
{
	while (!threadShouldExit())
	{
		UpdateSensorData();
		Sleep(1);
	}
}

void SensorControllerCore::Init(int w, int h)
{
	width = w;
	height = h;

	//Kinect Sensor Initialization Code Here!

	startThread();
}

void SensorControllerCore::Release()
{
	stopThread(1000);
}

void SensorControllerCore::GetJointPosition(Point3D & pt, int index)
{
}

bool SensorControllerCore::RectangleHitTest(Point3D LeftTop, double w, double h, Point3D normal1, Point3D normal2, int index, int dir)
{
	return false;
}

bool SensorControllerCore::CircleHitTest(Point3D center, double r, Point3D normal1, Point3D normal2, int index, int dir)
{
	return false;
}

bool SensorControllerCore::IsMoving(int index, int direction, double speed)
{
	return false;
}

double SensorControllerCore::GetMoveSpeed(int index, int dimension)
{
	return 0.0;
}

double SensorControllerCore::GetDeltaPosition(int index1, int index2, int dimension)
{
	return 0.0;
}

bool SensorControllerCore::IsLeftHandClosed()
{
	return false;
}

bool SensorControllerCore::IsRightHandClosed()
{
	return false;
}

bool SensorControllerCore::IsRightFootStepped()
{
	return false;
}

bool SensorControllerCore::IsLeftFootStepped()
{
	return false;
}
