#include "MissionClear.h"
USING_NS_CC;

Scene* MissonClear::createScene()
{
    auto scene = Scene::create();
    auto layer = MissonClear::create();
	scene->addChild(layer);
    return scene;
}

bool MissonClear::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
		Size visibleSize = Director::getInstance()->getVisibleSize();

	auto Sound = CocosDenshion::SimpleAudioEngine::sharedEngine();
	Sound->playBackgroundMusic("Clear.Wav",false);
	Sound->setBackgroundMusicVolume(0.8f);

	mario.c.Create("Mario", this, 2);
	mario.c.setPosition(visibleSize.width / 2, 350);	


	listner=EventListenerKeyboard::create();
	listner->onKeyPressed =CC_CALLBACK_2(MissonClear::onKeyPressed,this);
	listner->onKeyReleased =CC_CALLBACK_2(MissonClear::onKeyReleased,this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listner,this);

	_hole.spr = Sprite::create("hole_2.png");
	_hole.spr->setPosition(visibleSize.width / 2 +400, 116);
	this->addChild(_hole.spr, 2);

	auto Back_Ground_1 = Sprite::create("Back_Ground_clear.png");
	Back_Ground_1->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(Back_Ground_1, 0);	

	auto Menu_1 = Sprite::create("NEXT.png");
	Menu_1->setPosition(visibleSize.width / 2 +400, 306);
	this->addChild(Menu_1, 3);	

	Stage::stage+=1;
	this->schedule(schedule_selector(MissonClear::Update));

	return true;
}

void MissonClear::Update(float deltaTime){
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

	Rect rect = _hole.spr->boundingBox();
	rect.setRect(rect.getMinX()+5, rect.getMaxY()-110, rect.getMaxX()-10, rect.getMaxY()-120);
	if(rect.intersectsRect(mario.c.getSpr()->boundingBox())){
		NextReplace();
	}
	

	mario.Gravity_2(deltaTime);	
	mario.c.setPosition(mario.pos.x,mario.pos.y);
	mario.c.Update(deltaTime);	
}
void MissonClear::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) 
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

void MissonClear::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) {
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


void MissonClear::NextReplace()
{
	auto B = Battle::createScene();
	Director::sharedDirector()->replaceScene(B);
}
