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

	//根据命令行参数判断用户并登陆，或无参数匿名登录开始单机游戏
	bool SetLoginParams(StringArray);
	//初始化，参数为屏幕长宽
	void Init(int,int);
	//释放游戏资源
	void Release();
	//检查是否请求退出
	bool CheckQuitMessage();

	//多线程操作入口，此处包含游戏循环
	void run() override;

private:
	//游戏循环
	void GameLoop();

	ReferenceCountedObjectPtr<SensorControllerCore> m_scc; //Kinect传感器对象安全指针
	int width, height; //窗口长宽
	bool shouldQuit; //是否请求退出
	long lastTick; //上一帧滴答数
};

#endif

#endif  // DATAMODELCORE_H_INCLUDED
