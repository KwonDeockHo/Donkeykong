#ifndef __MISSON_FAIL_H__
#define __MISSON_FAIL_H__

#include "CAnimation.h"
#include "Base.h"
USING_NS_CC;


class _Hole{
public:
	Sprite *spr;
	Vec2 pos;
	Vec2 des;
};

class MissonFail : public cocos2d::Layer
{
public:
	Mario mario;
	_Hole _hole[2];
	EventListenerKeyboard *listner;
public:
    static cocos2d::Scene* createScene();
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual bool init();	
	void Update(float deltaTime);
	
	void GameReplace();
	void MenuReplace();
	CREATE_FUNC(MissonFail);
};

#endif
