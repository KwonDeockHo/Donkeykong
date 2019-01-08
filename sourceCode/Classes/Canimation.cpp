#include "CAnimation.h"

void CAnimation::Create(char *FolderName, Layer *_parentLayer, int ZOrder)
{
	parentLayer = _parentLayer;
	int i = 0;
	//폴더 내의 폴더 명과 같은 이름을 가진 이미지를 불러오기
	while(true)
	{
		//이미지 0번부터 시작
		char tmp[256] = {NULL, };
		sprintf(tmp, "%s\\%s_%d.png", FolderName, FolderName, i);
		Sprite *newSprite = Sprite::create(tmp);
		//이미지가 불려지지 않아 NULL 상태면 더 이상 이미지가 없는 것으로 판단
		//불러오기를 끝냄
		if(newSprite==NULL) break;
		newSprite->setPosition(0, 0);
		newSprite->setVisible(false);
		parentLayer->addChild(newSprite, ZOrder);
		SpriteList.push_back(newSprite);
		i++;
	}
	//초기값 지정
	Play = false;
	Timer = 0.0f;
	Index = 0;
	AnimationInterval = 0.1f;
}

void CAnimation::Update(float deltaTime)
{
	if(Play==true)
	{
		Timer+=deltaTime;
		if(Timer>=AnimationInterval)
		{
			if(Index>=SpriteList.size()-1) Index = 0;
			else Index++;
			Timer = 0.0f;
		}
	}
	int i = 0;
	itr = SpriteList.begin();
	while(itr!=SpriteList.end())
	{
		if(i==Index) (*itr)->setVisible(true);
		else (*itr)->setVisible(false);
		i++;
		itr++;
	}
}

void CAnimation::setPosition(float x, float y)
{
	itr = SpriteList.begin();
	while(itr!=SpriteList.end())
	{
		(*itr)->setPosition(x, y);
		itr++;
	}
}
Vec2 CAnimation::getPostion()
{
	itr = SpriteList.begin();
	return (*itr)->getPosition();
}

float CAnimation::getPostionX()
{
	itr = SpriteList.begin();
	return (*itr)->getPositionX();
}

float CAnimation::getPostionY()
{
	itr = SpriteList.begin();
	return (*itr)->getPositionY();
}
void CAnimation::setFrameNumber(int FrameNumber)
{
	Index = FrameNumber;
}

void CAnimation::setPlay(bool Value)
{
	Play = Value;
}

void CAnimation::setAnimationInterval(float Value)
{
	AnimationInterval = Value;
}
Sprite* CAnimation::getSpr(){
	itr = SpriteList.begin();
	return *itr;
}



BOOLEAN CAnimation::setfilpX_0(){
	itr = SpriteList.begin();
	while(itr!=SpriteList.end())
	{
		(*itr)->setFlipX(0);
		itr++;
	}
	return true;
}
BOOLEAN CAnimation::setfilpX_1(){
	itr = SpriteList.begin();
	while(itr!=SpriteList.end())
	{
		(*itr)->setFlipX(1);
		itr++;
	}
	return false;
}
void CAnimation::remove(){
	itr = SpriteList.begin();
	while(itr!=SpriteList.end())
	{
		SpriteList.erase(itr);
		itr++;
	}
}