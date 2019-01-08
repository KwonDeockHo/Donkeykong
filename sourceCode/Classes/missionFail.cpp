#include "missionFail.h"
USING_NS_CC;

Scene* MissonFail::createScene()
{
    auto scene = Scene::create();
    auto layer = MissonFail::create();
	scene->addChild(layer);
    return scene;
}

bool MissonFail::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
		Size visibleSize = Director::getInstance()->getVisibleSize();

	auto _Sound = CocosDenshion::SimpleAudioEngine::sharedEngine();
	_Sound->stopBackgroundMusic();
	_Sound->playBackgroundMusic("Game over.wav",false);
	_Sound->setBackgroundMusicVolume(0.8f);

	mario.c.Create("Mario", this, 2);
	mario.c.setPosition(visibleSize.width / 2, 350);	


	listner=EventListenerKeyboard::create();
	listner->onKeyPressed =CC_CALLBACK_2(MissonFail::onKeyPressed,this);
	listner->onKeyReleased =CC_CALLBACK_2(MissonFail::onKeyReleased,this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listner,this);

	_hole[0].spr = Sprite::create("hole_2.png");
	_hole[0].spr->setPosition(visibleSize.width / 2 -400, 116);
	this->addChild(_hole[0].spr, 2);

	_hole[1].spr = Sprite::create("hole_2.png");
	_hole[1].spr->setPosition(visibleSize.width / 2 +400, 116);
	this->addChild(_hole[1].spr, 2);

	auto Back_Ground_1 = Sprite::create("Back_Ground_clear.png");
	Back_Ground_1->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(Back_Ground_1, 0);	

	auto Menu = Sprite::create("Menu.png");
	Menu->setPosition(visibleSize.width / 2 +400, 306);
	this->addChild(Menu, 3);	

	auto Menu_1 = Sprite::create("RETRY.png");
	Menu_1->setPosition(visibleSize.width / 2 -400, 306);
	this->addChild(Menu_1, 3);	
	Stage::Score = 0;
	Stage::stage = 1;
	this->schedule(schedule_selector(MissonFail::Update));

	return true;
}

void MissonFail::Update(float deltaTime){
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

	Rect rect = _hole[0].spr->boundingBox();
	rect.setRect(rect.getMinX()+5, rect.getMaxY()-110, rect.getMaxX()-10, rect.getMaxY()-120);
	if(rect.intersectsRect(mario.c.getSpr()->boundingBox())){
		GameReplace();
	}
	
	Rect rect_ = _hole[1].spr->boundingBox();
	rect_.setRect(rect_.getMinX()+5, rect_.getMaxY()-110, rect_.getMaxX()-10, rect_.getMaxY()-120);
	if(rect_.intersectsRect(mario.c.getSpr()->boundingBox())){
		MenuReplace();
	}
	mario.Gravity_2(deltaTime);	
	mario.c.setPosition(mario.pos.x,mario.pos.y);
	mario.c.Update(deltaTime);	
}
void MissonFail::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) 
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

void MissonFail::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) {
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


void MissonFail::GameReplace()
{
	auto B = Base::createScene();
	Director::sharedDirector()->replaceScene(B);
}
void MissonFail::MenuReplace()
{
	auto C = HelloWorld::createScene();
	Director::sharedDirector()->replaceScene(C);
}