#include "HelloWorldScene.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
	scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	Size visibleSize = Director::getInstance()->getVisibleSize();

	Sound = CocosDenshion::SimpleAudioEngine::sharedEngine();
	Sound->playBackgroundMusic("Opening.mp3",true);
	Sound->setBackgroundMusicVolume(0.8f);

	MenuItemImage *startButton = MenuItemImage::create("Button_up_s.png","Button_down_s.png",CC_CALLBACK_1(HelloWorld::startButtonClick, this));
	startButton->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	MenuItemImage *ImforButton = MenuItemImage::create("Button_up_I.png","Button_down_I.png",CC_CALLBACK_1(HelloWorld::Imformation, this));
	ImforButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 40);

	MenuItemImage *ExitButton = MenuItemImage::create("Button_up_e.png","Button_down_e.png",CC_CALLBACK_1(HelloWorld::Exit, this));
	ExitButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 80);

	Menu *menu = Menu::create(startButton, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu, 2);
		
	Menu *menu_I = Menu::create(ImforButton, NULL);
	menu_I->setPosition(0, 0);
	this->addChild(menu_I, 2);

	Menu *menu_E = Menu::create(ExitButton, NULL);
	menu_E->setPosition(0, 0);
	this->addChild(menu_E, 2);

	auto Back_Ground = Sprite::create("Back_Ground.png");
	Back_Ground->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(Back_Ground, 1);

	return true;
}

void HelloWorld::startButtonClick(Ref *pSender)
{
	Sound->end();
	auto C = Base::createScene();
	Director::sharedDirector()->replaceScene(C);
	
}
void HelloWorld::Imformation(Ref *pSendes)
{

	auto B = Imformation::createScene();
	Director::sharedDirector()->replaceScene(B);
}
void HelloWorld::Exit(Ref *pSendes)
{
	exit(0);
}