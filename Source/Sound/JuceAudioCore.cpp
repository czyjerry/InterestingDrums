/*
  ==============================================================================

    JuceAudioCore.cpp
    Created: 10 Aug 2016 2:17:36pm
    Author:  czy_jerry

  ==============================================================================
*/

#include "../Headers/JuceAudioCore.h"

JuceAudioCore::JuceAudioCore()
{

}

JuceAudioCore::JuceAudioCore(ScopedPointer<DataModelCore> p_data)
{
	m_data = p_data;
}

JuceAudioCore::~JuceAudioCore()
{

}
