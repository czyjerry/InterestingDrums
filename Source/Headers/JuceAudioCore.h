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

	//��ʼ����Ƶ�豸
	void Init();
	//�ͷ���Ƶ�豸����Դ
	void Release();
private:
	ReferenceCountedObjectPtr<DataModelCore> m_data; //��Ϸ�߼����ݶ���ȫָ��
};


#endif  // JUCEAUDIOCORE_H_INCLUDED
