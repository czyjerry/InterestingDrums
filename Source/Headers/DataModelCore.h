/*
  ==============================================================================

    DataModelCore.h
    Created: 10 Aug 2016 1:51:56pm
    Author:  czy_jerry

  ==============================================================================
*/

#ifndef DATAMODELCORE_H_INCLUDED
#define DATAMODELCORE_H_INCLUDED

#include "JuceHeader.h"
#include "ProjectHeader.h"

#ifndef DATAMODELCORE_CLASS
#define DATAMODELCORE_CLASS

class DataModelCore :public Thread
{
public:
	DataModelCore();
	DataModelCore(ScopedPointer<HTTPTools>, ScopedPointer<SensorControllerCore>);
	~DataModelCore();

	void run() override;
private:
	ScopedPointer<HTTPTools> m_ht;
	ScopedPointer<SensorControllerCore> m_scc;
};

#endif

#endif  // DATAMODELCORE_H_INCLUDED
