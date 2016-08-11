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

class JuceAudioCore: public ReferenceCountedObject
{
public:
	JuceAudioCore();
	JuceAudioCore(ReferenceCountedObjectPtr<DataModelCore>);
	~JuceAudioCore();

	//初始化音频设备
	void Init();
	//释放音频设备及资源
	void Release();
private:
	ReferenceCountedObjectPtr<DataModelCore> m_data; //游戏逻辑数据对象安全指针
};


#endif  // JUCEAUDIOCORE_H_INCLUDED
