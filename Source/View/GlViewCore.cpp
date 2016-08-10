/*
  ==============================================================================

    GlViewCore.cpp
    Created: 10 Aug 2016 2:17:09pm
    Author:  czy_jerry

  ==============================================================================
*/

#include "../Headers/GlViewCore.h"

GlViewCore::GlViewCore()
{

}

GlViewCore::GlViewCore(ScopedPointer<DataModelCore> p_data)
{
	m_data = p_data;
}

GlViewCore::~GlViewCore()
{

}
