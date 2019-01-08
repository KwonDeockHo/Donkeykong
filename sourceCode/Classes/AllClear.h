#ifndef __MISSON_ALL_CLEAR_H__
#define __MISSON_ALL_CLEAR_H__

#include "CAnimation.h"
#include "BattleScene.h"
USING_NS_CC;

class AllClear : public cocos2d::Layer
{
public:
	Mario _mario;
public:
	float Move_Timer;
	int state;
    static cocos2d::Scene* createScene();
	virtual bool init();	
	void Update(float deltaTime);
	void ReplaceButtonClick(Ref *pSender);
	CREATE_FUNC(AllClear);
};

#endif
