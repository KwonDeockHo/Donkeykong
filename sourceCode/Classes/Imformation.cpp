#include "Imformation.h"
USING_NS_CC;

Scene* Imformation::createScene()
{
    auto scene = Scene::create();
    auto layer = Imformation::create();
	scene->addChild(layer);
    return scene;
}

bool Imformation::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	Size visibleSize = Director::getInstance()->getVisibleSize();

	MenuItemImage *backButton = MenuItemImage::create("Back_up.png","Back_down.png",CC_CALLBACK_1(Imformation::BackClick, this));
	backButton->setPosition(visibleSize.width / 2 + 400, 100);

	Menu *menu = Menu::create(backButton, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu, 2);

	auto Back_Ground = Sprite::create("Imformation.png");
	Back_Ground->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(Back_Ground, 1);

	return true;
}

void Imformation::BackClick(Ref *pSender)
{
	auto C = HelloWorld::createScene();
	Director::sharedDirector()->replaceScene(C);
	
}