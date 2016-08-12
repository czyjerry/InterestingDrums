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

GlViewCore::GlViewCore(ReferenceCountedObjectPtr<DataModelCore> p_data)
{
	m_data = p_data;
}

GlViewCore::~GlViewCore()
{
	openGLContext.detach();
}

void GlViewCore::Init()
{
	openGLContext.setRenderer(this);
	openGLContext.attachTo(*this);
	openGLContext.setComponentPaintingEnabled(false);
	//openGLContext.setSwapInterval(60);
	openGLContext.setContinuousRepainting(true);
}

void GlViewCore::newOpenGLContextCreated()
{
	// nothing to do in this case - we'll initialise our shaders + textures
	// on demand, during the render callback.
}

void GlViewCore::openGLContextClosing()
{
	// When the context is about to close, you must use this callback to delete
	// any GPU resources while the context is still current.
}

void GlViewCore::renderOpenGL()
{
	// This is a virtual method in OpenGLRenderer, and is called when it's time
	// to do your GL rendering.
}

void GlViewCore::Release()
{

}
