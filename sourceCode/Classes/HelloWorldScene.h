#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "BattleScene.h"
#include "Base.h"
#include "missionFail.h"
#include "Imformation.h"
#include "Stage.h"
#include "AllClear.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{

public:
	CocosDenshion::SimpleAudioEngine *Sound;
    static cocos2d::Scene* createScene();
    virtual bool init();
	void startButtonClick(Ref *pSender);
	void Imformation(Ref *pSendes);
	void Exit(Ref *pSendes);
	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
