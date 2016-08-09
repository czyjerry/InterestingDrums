/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (600, 400);

	setWantsKeyboardFocus(true);
	kp = new KeyPress(KeyPress::escapeKey);

	StartGameLoop();
}

MainContentComponent::~MainContentComponent()
{
}

bool MainContentComponent::keyPressed(const KeyPress &key)
{
	if (*kp == key)
	{
		JUCEApplication::getInstance()->systemRequestedQuit();
	}
	return true;
}

void MainContentComponent::paint (Graphics& g)
{
	grabKeyboardFocus();
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
	Desktop& desktop = Desktop::getInstance();
	desktop.setKioskModeComponent(getTopLevelComponent());
}

void MainContentComponent::StartGameLoop()
{

}
