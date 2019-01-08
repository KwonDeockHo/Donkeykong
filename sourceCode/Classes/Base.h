#ifndef __BASE_SCENE_H__
#define __BASE_SCENE_H__

#include "HelloWorldScene.h"
#include "Mario.h"
#include "BattleScene.h"
#include "CAnimation.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

class Hole{
public:
	Sprite *spr;
	Vec2 pos;
	Vec2 des;
};

class Base : public cocos2d::Layer
{
public:
	Mario mario;
	EventListenerKeyboard *listner;
	Hole hole[3];
public:
    static cocos2d::Scene* createScene();
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual bool init();	

	void Update(float deltaTime);
	//void Gravity(float deltaTime);
	void Replace();
	CREATE_FUNC(Base);
};

#endif // __BASE_SCENE_H__
