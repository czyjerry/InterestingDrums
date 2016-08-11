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

	//���Kinect Runtime Environment�Ƿ���������
	bool check();
	//��ʼ��Kinect�豸������Ϊ����ʵ�ʳ����С
	void Init(int w,int h);
	//�ͷ�Kinect�豸��Դ
	void Release();

	////���̲߳�����ڣ��˴�����ˢ��Kinect�����ڵ�����
	void run() override;

	//���index��Ӧ�ڵ����ά����
	void GetJointPosition(Point3D &pt, int index);
	//index�ڵ���һ������ƽ�棨���Ͻ�����ΪLeftTop�����Ϊw������Ϊh��ƽ���һ�������ǵ�normal1��normal2��ɵ�ֱ�ߣ�����ײ���
	//dir������ײ����2Ϊֻ���ӷ������ײ��1Ϊֻ�����������ײ��0Ϊ�����򶼼��
	bool RectangleHitTest(Point3D LeftTop, double w, double h, Point3D normal1, Point3D normal2, int index, int dir);
	//����һ���������ƣ���ͬ�������Ǽ��ڵ���һ��Բ��ƽ�����ײ��centerΪԲ�����꣬rΪ�뾶
	bool CircleHitTest(Point3D center, double r, Point3D normal1, Point3D normal2, int index, int dir);
	//�ж�index�ڵ��Ƿ�����Ӷ��ٶȵľ���ֵ�ﵽspeed�ĻӶ�������directionΪ�Ӷ�����0Ϊ�һӣ�1Ϊ��ӣ�2Ϊ�ϻӣ�3Ϊ�»�
	bool IsMoving(int index, int direction, double speed);
	//��ȡindex�ڵ���dimension�������ϵ��ƶ��ٶȣ�dimension��ֵ0Ϊx�ᣬ1Ϊy�ᣬ2Ϊz��
	double GetMoveSpeed(int index, int dimension);
	//��ȡindex1��index2�ڵ���dimension�������ϵľ��루index1Ϊ��������index2Ϊ�����������ȡ����ֵ����Ϊ����
	double GetDeltaPosition(int index1, int index2, int dimension);
	//�ж������Ƿ���ȭ���Ƿ���true������ȭȫ������false
	bool IsLeftHandClosed();
	//�ж������Ƿ���ȭ���Ƿ���true������ȭȫ������false
	bool IsRightHandClosed();
	//�ж��ҽ��Ƿ���£��Ƿ���true�����򷵻�false
	bool IsRightFootStepped();
	//�ж�����Ƿ���£��Ƿ���true�����򷵻�false
	bool IsLeftFootStepped();
private:
	//ˢ��Kinect�����ڵ����ݣ����洢������˽�г�Ա��
	void UpdateSensorData();

	//�˴������������˽�г�Ա

	int width, height; //���ڵ�ʵ�ʳ���
};

#endif

#endif  // SENSORCONTROLLERCORE_H_INCLUDED
