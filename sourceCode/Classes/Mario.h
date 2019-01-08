#ifndef __MARIO_H__
#define __MARIO_H__

#include "Item.h"
#include "CAnimation.h"
using namespace cocos2d;
class _HP{
	int hp;
	Sprite *spr;
};
class Mario{
public:
	CAnimation c;
	Vec2 pos;
	Vec2 des;
	Vec2 Power;
	int state;
	float Timer;
	bool ynjump;
	bool jump;  // 점프를 한 상태 = true
	int hp[5];
	int hp_c;
	std::list<_Item*> User_Item_L;
	void Gravity_1(float deltaTime);
	void Gravity_2(float deltaTime);
	void Update(float deltaTime);
	//void setPosition(float x, float y);
	//void create(Layer *_parentLayer);
	//Layer *parentLayer;						//부모 레이어
};

#endif
