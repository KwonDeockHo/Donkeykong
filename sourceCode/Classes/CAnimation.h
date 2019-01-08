#ifndef _CANIMATION_H_
#define _CANIMATION_H_

#include "cocos2d.h"
using namespace cocos2d;

class CAnimation
{
private :
	Layer *parentLayer;						//부모 레이어
	std::list<Sprite*> SpriteList;			//스프라이트 리스트
	std::list<Sprite*>::iterator itr;		//스프라이트 리스트 반복자
private :
	bool Play;								//애니메이션 플레이 여부
	float AnimationInterval;				//1 프레임 시간
	float Timer;							//타이머
	int Index;								//현재 보여지는 애니메이션 프레임 번호
public :
	void Create(char *FolderName, Layer *_parentLayer, int ZOrder = 0);		//애니메이션 스프라이트 생성
	void Update(float deltaTime);			//애니메이션 업데이트 함수
	void setPosition(float x, float y);										//위치 조절
	void setFrameNumber(int FrameNumber);									//애니메이션 프레임 번호 지정 함수
	void setPlay(bool Value);												//플레이 여부 지정 함수
	void setAnimationInterval(float Value);	
	Vec2 getPostion();//프레임 시간 지정 함수
	float getPostionY();
	float getPostionX();
	BOOLEAN setfilpX_0();
	BOOLEAN setfilpX_1();
	void remove();
	Sprite *getSpr();
	Sprite *getSpr_();


};

#endif