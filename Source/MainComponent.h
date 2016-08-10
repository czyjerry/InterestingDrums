/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Headers/ProjectHeader.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public Component
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&) override;
    void resized() override;

	void SetHttpTools(ScopedPointer<HTTPTools>);
	void SetSensorController(ScopedPointer<SensorControllerCore>);
	void StartGameLoop();

private:
    //==============================================================================

	bool keyPressed(const KeyPress&);

	KeyPress *kp;

	ScopedPointer<HTTPTools> m_http;
	ScopedPointer<SensorControllerCore> m_kinect;
	ScopedPointer<DataModelCore> m_data;
	ScopedPointer<GlViewCore> m_view;
	ScopedPointer<JuceAudioCore> m_audio;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
