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

	//初始化OpenGL
	void Init();
	//释放OpenGL资源
	void Release();

	//父类纯虚函数，在OpenGL上下文创建时调用
	void newOpenGLContextCreated() override;
	//父类纯虚函数，在OpenGL上下文销毁时调用
	void openGLContextClosing() override;
	//游戏界面渲染主函数
	void renderOpenGL() override;

private:
	ReferenceCountedObjectPtr<DataModelCore> m_data; //游戏逻辑数据对象安全指针
	OpenGLContext openGLContext; //OpenGL上下文
};


#endif  // GLVIEWCORE_H_INCLUDED
