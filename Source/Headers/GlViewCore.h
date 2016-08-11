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

class GlViewCore : public Component, public ReferenceCountedObject, private OpenGLRenderer
{
public:
	GlViewCore();
	GlViewCore(ReferenceCountedObjectPtr<DataModelCore>);
	~GlViewCore();

	//��ʼ��OpenGL
	void Init();
	//�ͷ�OpenGL��Դ
	void Release();

	//���ി�麯������OpenGL�����Ĵ���ʱ����
	void newOpenGLContextCreated() override;
	//���ി�麯������OpenGL����������ʱ����
	void openGLContextClosing() override;
	//��Ϸ������Ⱦ������
	void renderOpenGL() override;

private:
	ReferenceCountedObjectPtr<DataModelCore> m_data; //��Ϸ�߼����ݶ���ȫָ��
	OpenGLContext openGLContext; //OpenGL������
};


#endif  // GLVIEWCORE_H_INCLUDED
