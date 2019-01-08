#ifndef __BATTLE_SCENE_H__
#define __BATTLE_SCENE_H__

#include "Mario.h"
#include "time.h"
#include "conio.h"
#include "missionFail.h"
#include "MissionClear.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

class Jump{
public:
	Sprite *spr;
	Vec2 Pos;
	Vec2 Des;
	int power;
};

class Kong{
public:
	//Sprite *Enermy;
	CAnimation c;
	float Timer;
	std::list<_Item*> Enermy_Item_L;
	Vec2 Des;
	Vec2 Pos;
	int position;
	int count;
	int state;
	int HP;
	Vec2 Power;
};

class Battle : public cocos2d::Layer
{
public:
	Mario mario;
	Jump *jump[4];
	Kong kong;
	Jump niddle;
	_Item *new_Item;
	_Item *User_Item;
	float Timer;
	float speed;
	float Score_Timer;
	boolean x;
	int life_;
	LabelTTF *score_;
	LabelTTF *stage_;
	EventListenerKeyboard *listner;
	void Update(float deltaTime);
	static cocos2d::Scene* createScene();
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual bool init();
	void FAIL();
	void Clear();
	void AllClear();
	float y;
	Sprite *Enermy_HP_Front;
	Sprite *User_HP[5];
	CREATE_FUNC(Battle);
};

#endif 
