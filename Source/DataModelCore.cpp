/*
  ==============================================================================

    DataModelCore.cpp
    Created: 10 Aug 2016 2:18:02pm
    Author:  czy_jerry

  ==============================================================================
*/

#include "Headers/DataModelCore.h"

DataModelCore::DataModelCore() : Thread("Data Model Thread")
{
}

DataModelCore::DataModelCore(ReferenceCountedObjectPtr<SensorControllerCore> p_scc) : Thread("Data Model Thread")
{
	m_scc = p_scc;
	shouldQuit = false;
	lastTick = 0;
}

DataModelCore::~DataModelCore()
{

}

bool DataModelCore::SetLoginParams(StringArray /*sa*/)
{

	return true;
}

void DataModelCore::run()
{
	while (!threadShouldExit())
	{
		if (!shouldQuit)
		{
			if(GetTickCount() - lastTick >= 1000 / FPS) GameLoop();
		}
		else Sleep(1);
	}
}

void DataModelCore::Init(int w, int h)
{
	width = w;
	height = h;

	startThread();
}

void DataModelCore::Release()
{
	stopThread(1000);
}

bool DataModelCore::CheckQuitMessage()
{
	return shouldQuit;
}

void DataModelCore::GameLoop()
{

}