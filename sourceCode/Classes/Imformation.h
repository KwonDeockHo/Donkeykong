#ifndef __IMFORMATION_H__
#define __IMFORMATION_H__

#include "HelloWorldScene.h"
USING_NS_CC;

class Imformation : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();

	void BackClick(Ref *pSender);
	CREATE_FUNC(Imformation);
};

#endif
