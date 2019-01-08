#ifndef __MISSON_FAIL_H__
#define __MISSON_FAIL_H__

#include "HelloWorldScene.h"
#include "Mario.h"
#include "CAnimation.h"
#include "Base.h"
USING_NS_CC;

class MissonFail : public cocos2d::Layer
{
public:
	Mario mario;
	EventListenerKeyboard *listner;
	Hole hole_C[2];
public:
    static cocos2d::Scene* createScene();
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual bool init();	
	void Update(float deltaTime);


	void RetrytButton();
	void ExitButton();
	CREATE_FUNC(MissonFail);
};

#endif
