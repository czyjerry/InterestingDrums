/*
  ==============================================================================

    GlViewCore.h
    Created: 10 Aug 2016 1:52:22pm
    Author:  czy_jerry

  ==============================================================================
*/

#ifndef GLVIEWCORE_H_INCLUDED
#define GLVIEWCORE_H_INCLUDED

#include "JuceHeader.h"
#include "ProjectHeader.h"

class GlViewCore : public Component
{
public:
	GlViewCore();
	GlViewCore(ScopedPointer<DataModelCore>);
	~GlViewCore();

private:
	ScopedPointer<DataModelCore> m_data;
};


#endif  // GLVIEWCORE_H_INCLUDED
