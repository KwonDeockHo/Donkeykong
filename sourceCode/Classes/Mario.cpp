#include "Mario.h"
USING_NS_CC;

void Mario::Update(float deltaTime){
	Size visibleSize = Director::getInstance()->getVisibleSize();
}
//void Mario::setPosition(float x, float y){
//	this->c.setPosition(x, y);
//}
void Mario::Gravity_1(float deltaTime)
{
	Power+=Vec2(0, -600*deltaTime);
	pos+= Power*deltaTime;
	//�������� ��� �����ְ� �ִ� �̰��� �������� �ִٴ°�
	if(pos.y<=150 && ynjump==false)
	{
		Power.y = 0;
		pos.y = 150;
	}
	//�̰��� 
	if(pos.y<=150)
	{
		jump = false;
	}
	ynjump = false;
}
void Mario::Gravity_2(float deltaTime)
{
	Power+=Vec2(0, -600*deltaTime);
	pos+= Power*deltaTime;
	//�������� ��� �����ְ� �ִ� �̰��� �������� �ִٴ°�
	if(pos.y<=100 && ynjump==false)
	{
		Power.y = 0;
		pos.y = 100;
	}
	//�̰��� 
	if(pos.y<=100)
	{
		jump = false;
	}
	ynjump = false;
}