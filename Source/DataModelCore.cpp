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

DataModelCore::DataModelCore(ScopedPointer<HTTPTools> p_ht, ScopedPointer<SensorControllerCore> p_scc) : Thread("Data Model Thread")
{
	m_ht  = p_ht;
	m_scc = p_scc;
}

DataModelCore::~DataModelCore()
{

}

void DataModelCore::run()
{

}
