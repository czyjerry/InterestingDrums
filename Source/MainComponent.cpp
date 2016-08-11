/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "Headers/ProjectHeader.h"


//==============================================================================
MainContentComponent::MainContentComponent() : Thread("Main Component Thread")
{
	setSize(600, 400);

	setWantsKeyboardFocus(true);
	kp = new KeyPress(KeyPress::escapeKey);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::ReleaseIt()
{
	m_kinect->Release();
	m_audio->Release();
	m_data->Release();
	m_view->Release();
	stopThread(1000);
}

bool MainContentComponent::keyPressed(const KeyPress &key)
{
	if (*kp == key)
	{
		ReleaseIt();
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

void MainContentComponent::SetDataModel(ReferenceCountedObjectPtr<DataModelCore> dmc)
{
	m_data = dmc;
}

void MainContentComponent::SetSensorController(ReferenceCountedObjectPtr<SensorControllerCore> scc)
{
	m_kinect = scc;
}

void MainContentComponent::AttachViewToComponent()
{
	m_view->setBounds(getLocalBounds());
	addAndMakeVisible(m_view);
}

void MainContentComponent::StartGameLoop()
{
	m_audio = new JuceAudioCore(m_data);
	m_view = new GlViewCore(m_data);

	AttachViewToComponent();

	m_kinect->Init(SCREEN_WIDTH,SCREEN_HEIGHT);
	m_data->Init(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_view->Init();
	m_audio->Init();

	startThread();

	grabKeyboardFocus();
}

void MainContentComponent::run()
{
	while (!threadShouldExit())
	{
		if (m_data->CheckQuitMessage())
		{
			ReleaseIt();
			JUCEApplication::getInstance()->systemRequestedQuit();
		}
		Sleep(1);
	}
}
