#ifndef __ITEM_H__
#define __ITEM_H__

#include "cocos2d.h"
#include "CAnimation.h"
USING_NS_CC;

class _Item{
public:
	Sprite *spr;
	CAnimation c;
	Vec2 Pos;
	Vec2 Des;
	Vec2 Power;
	int _state;
};

#endif
