#ifndef _CANIMATION_H_
#define _CANIMATION_H_

#include "cocos2d.h"
using namespace cocos2d;

class CAnimation
{
private :
	Layer *parentLayer;						//�θ� ���̾�
	std::list<Sprite*> SpriteList;			//��������Ʈ ����Ʈ
	std::list<Sprite*>::iterator itr;		//��������Ʈ ����Ʈ �ݺ���
private :
	bool Play;								//�ִϸ��̼� �÷��� ����
	float AnimationInterval;				//1 ������ �ð�
	float Timer;							//Ÿ�̸�
	int Index;								//���� �������� �ִϸ��̼� ������ ��ȣ
public :
	void Create(char *FolderName, Layer *_parentLayer, int ZOrder = 0);		//�ִϸ��̼� ��������Ʈ ����
	void Update(float deltaTime);			//�ִϸ��̼� ������Ʈ �Լ�
	void setPosition(float x, float y);										//��ġ ����
	void setFrameNumber(int FrameNumber);									//�ִϸ��̼� ������ ��ȣ ���� �Լ�
	void setPlay(bool Value);												//�÷��� ���� ���� �Լ�
	void setAnimationInterval(float Value);	
	Vec2 getPostion();//������ �ð� ���� �Լ�
	float getPostionY();
	float getPostionX();
	BOOLEAN setfilpX_0();
	BOOLEAN setfilpX_1();
	void remove();
	Sprite *getSpr();
	Sprite *getSpr_();


};

#endif