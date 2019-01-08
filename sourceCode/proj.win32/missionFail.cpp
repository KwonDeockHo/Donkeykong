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
	listner=EventListenerKeyboard::create();
	listner->onKeyPressed =CC_CALLBACK_2(MissonFail::onKeyPressed,this);
	listner->onKeyReleased =CC_CALLBACK_2(MissonFail::onKeyReleased,this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listner,this);
	Size visibleSize = Director::getInstance()->getVisibleSize();

	mario.c.Create("Mario", this, 2);
	mario.c.setPosition(visibleSize.width / 2, 350);	
	mario.state = 0;
	mario.Timer = 0.0;
	mario.jump = false;
	mario.ynjump =false;

	
	auto EXIT = Sprite::create("EXIT.png");
	EXIT->setPosition(visibleSize.width / 2 + 400, 350);
	this->addChild(EXIT, 3);

	auto RETRY = Sprite::create("RETRY.png");
	RETRY->setPosition(visibleSize.width / 2 -400, 350);
	this->addChild(RETRY, 3);


	hole_C[0].spr = Sprite::create("hole_2.png");
	hole_C[0].spr->setPosition(visibleSize.width / 2 +400, 120);
	this->addChild(hole_C[0].spr, 2);

	hole_C[1].spr = Sprite::create("hole_2.png");
	hole_C[1].spr->setPosition(visibleSize.width / 2 -400, 120);
	this->addChild(hole_C[1].spr, 2);

	auto Back_Ground = Sprite::create("Back_Ground_clear.png");
	Back_Ground->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(Back_Ground, 1);

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
			}
		}
	
	}

	Rect rect = hole_C[0].spr->boundingBox();
	rect.setRect(rect.getMinX()+5, rect.getMaxY()-110, rect.getMaxX()-10, rect.getMaxY()-120);
	if(rect.intersectsRect(mario.c.getSpr()->boundingBox())){
		ExitButton();
	}
	
	Rect rect1 = hole_C[1].spr->boundingBox();
	rect1.setRect(rect1.getMinX()+5, rect1.getMaxY()-110, rect1.getMaxX()-10, rect1.getMaxY()-120);
	if(rect1.intersectsRect(mario.c.getSpr()->boundingBox())){
		RetrytButton();
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

void MissonFail::RetrytButton()
{
	auto B = Base::createScene();
	Director::sharedDirector()->replaceScene(B);
}
void MissonFail::ExitButton()
{
	auto C = HelloWorld::createScene();
	Director::sharedDirector()->replaceScene(C);}