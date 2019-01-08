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
	//음수값을 계속 더해주고 있다 이것은 떨어지고 있다는것
	if(pos.y<=150 && ynjump==false)
	{
		Power.y = 0;
		pos.y = 150;
	}
	//이것은 
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
	//음수값을 계속 더해주고 있다 이것은 떨어지고 있다는것
	if(pos.y<=100 && ynjump==false)
	{
		Power.y = 0;
		pos.y = 100;
	}
	//이것은 
	if(pos.y<=100)
	{
		jump = false;
	}
	ynjump = false;
}