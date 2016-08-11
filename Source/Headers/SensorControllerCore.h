/*
  ==============================================================================

    SensorControllerCore.h
    Created: 10 Aug 2016 11:24:57am
    Author:  czy_jerry

  ==============================================================================
*/

#ifndef SENSORCONTROLLERCORE_H_INCLUDED
#define SENSORCONTROLLERCORE_H_INCLUDED

#include <Kinect.h>
#include "JuceHeader.h"
#include "ProjectHeader.h"

#ifndef SENSORCONTROLLERCORE_CLASS
#define SENSORCONTROLLERCORE_CLASS

class SensorControllerCore : public Thread, public ReferenceCountedObject
{
public:
	SensorControllerCore();
	~SensorControllerCore();

	//检查Kinect Runtime Environment是否运行正常
	bool check();
	//初始化Kinect设备，参数为窗口实际长宽大小
	void Init(int w,int h);
	//释放Kinect设备资源
	void Release();

	////多线程操作入口，此处包含刷新Kinect骨骼节点数据
	void run() override;

	//获得index对应节点的三维坐标
	void GetJointPosition(Point3D &pt, int index);
	//index节点与一个矩形平面（左上角坐标为LeftTop，宽度为w，长度为h，平面的一个法线是点normal1和normal2组成的直线）的碰撞检测
	//dir代表碰撞方向，2为只检测从反面的碰撞，1为只检测从正面的碰撞，0为两方向都检测
	bool RectangleHitTest(Point3D LeftTop, double w, double h, Point3D normal1, Point3D normal2, int index, int dir);
	//与上一个方法类似，不同的是这是检测节点与一个圆形平面的碰撞，center为圆心坐标，r为半径
	bool CircleHitTest(Point3D center, double r, Point3D normal1, Point3D normal2, int index, int dir);
	//判断index节点是否产生挥动速度的绝对值达到speed的挥动动作，direction为挥动方向，0为右挥，1为左挥，2为上挥，3为下挥
	bool IsMoving(int index, int direction, double speed);
	//获取index节点在dimension坐标轴上的移动速度，dimension的值0为x轴，1为y轴，2为z轴
	double GetMoveSpeed(int index, int dimension);
	//获取index1与index2节点在dimension坐标轴上的距离（index1为被减数，index2为减数，结果不取绝对值，可为负）
	double GetDeltaPosition(int index1, int index2, int dimension);
	//判断左手是否握拳，是返回true，非握拳全部返回false
	bool IsLeftHandClosed();
	//判断右手是否握拳，是返回true，非握拳全部返回false
	bool IsRightHandClosed();
	//判断右脚是否踩下，是返回true，否则返回false
	bool IsRightFootStepped();
	//判断左脚是否踩下，是返回true，否则返回false
	bool IsLeftFootStepped();
private:
	//刷新Kinect骨骼节点数据，并存储至对象私有成员中
	void UpdateSensorData();

	//此处可以自由添加私有成员

	int width, height; //窗口的实际长宽
};

#endif

#endif  // SENSORCONTROLLERCORE_H_INCLUDED
