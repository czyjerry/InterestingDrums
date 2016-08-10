/*
  ==============================================================================

    JuceAudioCore.h
    Created: 10 Aug 2016 1:52:39pm
    Author:  czy_jerry

  ==============================================================================
*/

#ifndef JUCEAUDIOCORE_H_INCLUDED
#define JUCEAUDIOCORE_H_INCLUDED


#include "JuceHeader.h"
#include "ProjectHeader.h"

class JuceAudioCore
{
public:
	JuceAudioCore();
	JuceAudioCore(ScopedPointer<DataModelCore>);
	~JuceAudioCore();

private:
	ScopedPointer<DataModelCore> m_data;
};


#endif  // JUCEAUDIOCORE_H_INCLUDED
