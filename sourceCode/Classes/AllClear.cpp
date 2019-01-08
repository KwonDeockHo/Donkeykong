#include "AllClear.h"
USING_NS_CC;

Scene* AllClear::createScene()
{
    auto scene = Scene::create();
    auto layer = AllClear::create();
	scene->addChild(layer);
    return scene;
}

bool AllClear::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	Size visibleSize = Director::getInstance()->getVisibleSize();
	
	_mario.c.Create("clear", this, 3);
	_mario.c.setPosition(visibleSize.width / 2, 100);	

	auto donkey = Sprite::create("donkey.png");
	donkey->setPosition(visibleSize.width / 2 + 200, 50);
	this->addChild(donkey, 3);	

	MenuItemImage *ExitButton = MenuItemImage::create("c_Exit_up.png","c_Exit_do.png",CC_CALLBACK_1(AllClear::ReplaceButtonClick, this));
	ExitButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 20);

	Menu *menu_E = Menu::create(ExitButton, NULL);
	menu_E->setPosition(0, 0);
	this->addChild(menu_E, 2);
		
	auto Sound = CocosDenshion::SimpleAudioEngine::sharedEngine();
	Sound->playBackgroundMusic("Success.mp3",true);
	Sound->setBackgroundMusicVolume(0.8f);

	auto Back_Ground_1 = Sprite::create("AllClear.png");
	Back_Ground_1->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(Back_Ground_1, 0);	

	auto Back_Ground = Sprite::create("Success.png");
	Back_Ground->setPosition(visibleSize.width / 2, visibleSize.height / 2+150);
	this->addChild(Back_Ground, 0);	


	Move_Timer = 0.0;

	this->schedule(schedule_selector(AllClear::Update));

	state = 0;
	return true;
}

void AllClear::Update(float deltaTime){
	Size visibleSize = Director::getInstance()->getVisibleSize();
	_mario.Timer+=deltaTime;
	Move_Timer+=deltaTime;
	_mario.pos.x = _mario.c.getPostionX();
	_mario.pos.y = _mario.c.getPostionY();
	if(state ==0)
		_mario.c.setfilpX_1();
	else if(state == 1)
		_mario.c.setfilpX_0();


	if(_mario.c.getPostionX() >= visibleSize.width - 500){
		state = 1;
	}
	else if(_mario.c.getPostionX() <= 300){
		state = 0;
	}

	if(Move_Timer>=0.1){
		if(state ==0)
			_mario.c.setPosition(_mario.pos.x+=5, _mario.pos.y);
		else if(state == 1)
			_mario.c.setPosition(_mario.pos.x-=5, _mario.pos.y);
	
		Move_Timer = 0.0;
	}
	_mario.c.setPlay(true);

	_mario.Gravity_2(deltaTime);	
	_mario.c.setPosition(_mario.pos.x,_mario.pos.y);
	_mario.c.Update(deltaTime);	
}

void AllClear::ReplaceButtonClick(Ref *pSender)
{
	auto B = HelloWorld::createScene();
	Director::sharedDirector()->replaceScene(B);
}
