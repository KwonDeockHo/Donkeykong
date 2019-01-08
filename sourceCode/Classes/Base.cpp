#include "Base.h"
USING_NS_CC;

Scene* Base::createScene()
{
    auto scene = Scene::create();
    auto layer = Base::create();
	scene->addChild(layer);
    return scene;
}

bool Base::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	listner=EventListenerKeyboard::create();
	listner->onKeyPressed =CC_CALLBACK_2(Base::onKeyPressed,this);
	listner->onKeyReleased =CC_CALLBACK_2(Base::onKeyReleased,this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listner,this);
	
	auto _Sound = CocosDenshion::SimpleAudioEngine::sharedEngine();
	_Sound->preloadBackgroundMusic("Super Mario Main Theme.mp3");
	_Sound->playBackgroundMusic("Super Mario Main Theme.mp3",true);
	_Sound->setBackgroundMusicVolume(0.8f);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	mario.c.Create("Mario", this, 2);
	mario.c.setPosition(50, 350);	
	mario.state = 0;
	mario.Timer = 0.0;
	mario.jump = false;
	mario.ynjump =false;

	auto Back_Ground = Sprite::create("Base_Back_Ground.png");
	Back_Ground->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(Back_Ground, 0);	

	hole[0].spr = Sprite::create("hole_1.png");
	hole[0].spr->setPosition(visibleSize.width / 2 + 150, 140);
	this->addChild(hole[0].spr, 2);

	hole[1].spr = Sprite::create("hole_2.png");
	hole[1].spr->setPosition(visibleSize.width / 2 +200, 166);
	this->addChild(hole[1].spr, 2);

	hole[2].spr = Sprite::create("hole_3.png");
	hole[2].spr->setPosition(visibleSize.width / 2 +350, 190);
	this->addChild(hole[2].spr, 2);

	auto Bounce = Sprite::create("Bounce.png");
	Bounce->setPosition(rand() % (int)visibleSize.width, rand() % ((int)visibleSize.height/2) + 300);
	this->addChild(Bounce, 0);	

	auto Bounce_1 = Sprite::create("Bounce.png");
	Bounce_1->setPosition(rand() % (int)visibleSize.width, rand() % ((int)visibleSize.height/2) + 300);
	this->addChild(Bounce_1, 0);	

	auto Bounce_2 = Sprite::create("Bounce.png");
	Bounce_2->setPosition(rand() % (int)visibleSize.width, rand() % ((int)visibleSize.height/2) + 300);
	this->addChild(Bounce_2, 0);	

	for(int i=0; i<3; i++){

	}
	this->schedule(schedule_selector(Base::Update));
	
	return true;
}
void Base::Update(float deltaTime){
	mario.Timer+=deltaTime;
	mario.pos.x = mario.c.getPostionX();
	mario.pos.y = mario.c.getPostionY();
	
	if(mario.state ==1)
	{
		mario.pos.x +=2;
		mario.c.setPlay(true);
		mario.c.setPosition(mario.pos.x,mario.pos.y);
	
	}
	if(mario.state ==2)
	{
		mario.pos.x -=2;
		mario.c.setPlay(true);
		mario.c.setPosition(mario.pos.x ,mario.pos.y);
	}
	if(mario.state == 3)
	{
		if(mario.jump == false)
		{
			if(mario.ynjump == false)
			{
			mario.ynjump = true;
			mario.jump = true;
			mario.Power += Vec2(0, 600);
				
			auto Sound_J = CocosDenshion::SimpleAudioEngine::sharedEngine();
				Sound_J->playEffect("Jump.wav",false);
				Sound_J->setBackgroundMusicVolume(0.8f);
			}
		}
	
	}

	Rect rect = hole[0].spr->boundingBox();
	rect.setRect(rect.getMinX()-4, rect.getMinY()+5, 10.0, (rect.getMaxY() - rect.getMinY())-10);
	if(rect.intersectsRect(mario.c.getSpr()->boundingBox()))
		Replace();
	
	Rect rect_ = hole[1].spr->boundingBox();
	rect_.setRect(rect_.getMinX()+5, rect_.getMaxY()-110, rect_.getMaxX()-10, rect_.getMaxY()-120);
	if(rect_.intersectsRect(mario.c.getSpr()->boundingBox()))
		Replace();

	Rect rect__ = hole[1].spr->boundingBox();
	rect__.setRect(rect__.getMinX()+5, rect__.getMaxY()-110, rect__.getMaxX()-10, rect__.getMaxY()-120);
	if(rect__.intersectsRect(mario.c.getSpr()->boundingBox()))
		Replace();

	mario.Gravity_1(deltaTime);	
	mario.c.setPosition(mario.pos.x,mario.pos.y);
	mario.c.Update(deltaTime);	
}
void Base::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) 
{

   CCLOG("onKeyPressed : %d",keyCode);
	switch (keyCode) {
   case EventKeyboard::KeyCode::KEY_L:{
		mario.state = 1;
		mario.c.setfilpX_0();
		break;
	}
   case EventKeyboard::KeyCode::KEY_J:{
		mario.state = 2;
		mario.c.setfilpX_1();
		break;
	}
   case EventKeyboard::KeyCode::KEY_A:{
	   mario.state = 3;
	   break;
		}
	}
}

void Base::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) {
	switch (keyCode) {
		case EventKeyboard::KeyCode::KEY_L	:{
			mario.state = 0;
			mario.c.setPlay(false);
			break;
		}
		 case EventKeyboard::KeyCode::KEY_J:{
			mario.state = 0;
			mario.c.setPlay(false);
		break;
		}
		case EventKeyboard::KeyCode::KEY_A:{
			mario.state = 0;
		break;
		}
	}
}

void Base::Replace()
{
	auto C = Battle::createScene();
	Director::sharedDirector()->replaceScene(C);
}