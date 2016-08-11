/*
  ==============================================================================

    DataModelCore.h
    Created: 10 Aug 2016 1:51:56pm
    Author:  czy_jerry

  ==============================================================================
*/

#ifndef DATAMODELCORE_H_INCLUDED
#define DATAMODELCORE_H_INCLUDED

#include "JuceHeader.h"
#include "ProjectHeader.h"

#ifndef DATAMODELCORE_CLASS
#define DATAMODELCORE_CLASS

class DataModelCore :public Thread, public ReferenceCountedObject
{
public:
	DataModelCore();
	DataModelCore(ReferenceCountedObjectPtr<SensorControllerCore>);
	~DataModelCore();

	//���������в����ж��û�����½�����޲���������¼��ʼ������Ϸ
	bool SetLoginParams(StringArray);
	//��ʼ��������Ϊ��Ļ����
	void Init(int,int);
	//�ͷ���Ϸ��Դ
	void Release();
	//����Ƿ������˳�
	bool CheckQuitMessage();

	//���̲߳�����ڣ��˴�������Ϸѭ��
	void run() override;

private:
	//��Ϸѭ��
	void GameLoop();

	ReferenceCountedObjectPtr<SensorControllerCore> m_scc; //Kinect����������ȫָ��
	int width, height; //���ڳ���
	bool shouldQuit; //�Ƿ������˳�
	long lastTick; //��һ֡�δ���
};

#endif

#endif  // DATAMODELCORE_H_INCLUDED
