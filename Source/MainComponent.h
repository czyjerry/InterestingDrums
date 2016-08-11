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
class MainContentComponent   : public Component, public Thread
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&) override;
    void resized() override;

	void SetDataModel(ReferenceCountedObjectPtr<DataModelCore>);
	void SetSensorController(ReferenceCountedObjectPtr<SensorControllerCore>);
	void StartGameLoop();

	void run() override;
private:
    //==============================================================================

	void ReleaseIt();
	void AttachViewToComponent();
	bool keyPressed(const KeyPress&);

	KeyPress *kp;

	ReferenceCountedObjectPtr<SensorControllerCore> m_kinect;
	ReferenceCountedObjectPtr<DataModelCore> m_data;
	ReferenceCountedObjectPtr<GlViewCore> m_view;
	ReferenceCountedObjectPtr<JuceAudioCore> m_audio;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
