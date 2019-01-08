#ifndef __MISSON_CLEAR_H__
#define __MISSON_CLEAR_H__

#include "CAnimation.h"
#include "BattleScene.h"
USING_NS_CC;


class Hole_{
public:
	Sprite *spr;
	Vec2 pos;
	Vec2 des;
};

class MissonClear : public cocos2d::Layer
{
public:
	Mario mario;
	Hole_ _hole;
	EventListenerKeyboard *listner;
public:
    static cocos2d::Scene* createScene();
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual bool init();	
	void Update(float deltaTime);
	void NextReplace();
	CREATE_FUNC(MissonClear);
};

#endif
