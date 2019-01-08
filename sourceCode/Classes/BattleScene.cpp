#include "BattleScene.h"
USING_NS_CC;
#define MAX_LIFE 5

Scene* Battle::createScene()
{
	auto scene = Scene::create();
	auto layer = Battle::create();
	scene->addChild(layer);
	return scene;
}

bool Battle::init()
{
	if ( !Layer::init() )
	{
		return false;
	}

	srand(unsigned(time(NULL)));
	char tm[30], tmp[30];

	listner=EventListenerKeyboard::create();
	listner->onKeyPressed =CC_CALLBACK_2(Battle::onKeyPressed,this);
	listner->onKeyReleased =CC_CALLBACK_2(Battle::onKeyReleased,this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listner,this);

	auto _Sound = CocosDenshion::SimpleAudioEngine::sharedEngine();
	_Sound->stopBackgroundMusic();
	_Sound->playBackgroundMusic("Title Theme.mp3",true);
	_Sound->setBackgroundMusicVolume(0.8f);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	mario.c.Create("Mario", this, 2);
	mario.c.setPosition(50, 350);	
	mario.state = 0;
	mario.Timer = 0.0;
	mario.jump = false;
	mario.ynjump =false;
	mario.hp_c = 2;

	for(int i=0; i<4; i++){
		jump[i] = new Jump;
		jump[i]->spr = Sprite::create("Bounce_up.png");
		jump[i]->spr->setPosition(visibleSize.width /2 - 420 + i*110, visibleSize.height/2 -265);
		this->addChild(jump[i]->spr, 1);
		jump[i]->power = (rand()%5) * 20 + 200;
	}

	auto Stack = Sprite::create("Stack.png");
	Stack->setPosition(visibleSize.width - 150, visibleSize.height -230);
	this->addChild(Stack, 4);	

	niddle.spr = Sprite::create("niddle.png");
	niddle.spr->setPosition(visibleSize.width /2+250, 65);
	this->addChild(niddle.spr, 1);

	if(Stage::stage == 1){
		auto Back_Ground_1 = Sprite::create("Back_Ground1.png");
		Back_Ground_1->setPosition(visibleSize.width / 2, visibleSize.height / 2);
		this->addChild(Back_Ground_1, 0);	
	}
	else if(Stage::stage == 2){
		auto Back_Ground_1 = Sprite::create("Back_Ground2.png");
		Back_Ground_1->setPosition(visibleSize.width / 2, visibleSize.height / 2);
		this->addChild(Back_Ground_1, 0);
	}
	else if(Stage::stage == 3){
		auto Back_Ground_1 = Sprite::create("Back_Ground3.png");
		Back_Ground_1->setPosition(visibleSize.width / 2, visibleSize.height / 2);
		this->addChild(Back_Ground_1, 0);
	}
	kong.c.Create("nomarkong", this, 5);
	kong.c.setPosition(visibleSize.width - 230, visibleSize.height -150);

	kong.Timer = 0.0;
	kong.position = 1;
	kong.count = 0;
	kong.state = 0;
	kong.HP = 100;

	for(int i=0; i<MAX_LIFE; i++){
		if(0<=i && i<3)
			mario.hp[i] = 1;
		else
			mario.hp[i] = 0;
	}

	for(int i=0; i<=mario.hp_c; i++){
		if(mario.hp[i] == 1){
			User_HP[i] = Sprite::create("UItem_1.png");
			User_HP[i]->setPosition(visibleSize.width-300 + i*50, visibleSize.height-630);
			this->addChild(User_HP[i], 3);
		}
	}

	Enermy_HP_Front = Sprite::create("hpbar.png");
	Enermy_HP_Front->setPosition(visibleSize.width-930, visibleSize.height-30);
	Enermy_HP_Front->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
	this->addChild(Enermy_HP_Front,2);

	auto *Enermy_HP_bg = Sprite::create("hpbar_bg.png");
	Enermy_HP_bg->setPosition(visibleSize.width-933, visibleSize.height-30);
	Enermy_HP_bg->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
	this->addChild(Enermy_HP_bg,1);

	sprintf(tm, "SCORE : %d", Stage::Score);
	score_ = LabelTTF::create(tm, "HY°ß°íµñ", 20);
	score_->setColor(ccc3(88, 184, 207));
	score_->setString(tm);
	score_->setPosition(visibleSize.width-883, visibleSize.height-100);
	this->addChild(score_);

	sprintf(tm, "STAGE : %d", Stage::stage);
	stage_= LabelTTF::create(tm, "HY°ß°íµñ", 20);
	stage_->setColor(ccc3(0, 0, 0));
	stage_->setString(tm);
	stage_->setPosition(visibleSize.width-883, visibleSize.height-70);
	this->addChild(stage_);

	Score_Timer = 0.0;
	Timer = 0.0;
	this->schedule(schedule_selector(Battle::Update));
	kong.c.setPlay(false);
	niddle.power = 1;
	return true;
}
void Battle::Update(float deltaTime){
	char tm[30];
	mario.Timer+=deltaTime;
	kong.Timer+=deltaTime;
	Timer+=deltaTime;
	Score_Timer+=deltaTime;
	std::list<_Item*>::iterator itr=kong.Enermy_Item_L.begin();
	std::list<_Item*>::iterator itr3=mario.User_Item_L.begin();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	mario.pos.x = mario.c.getPostionX();
	mario.pos.y = mario.c.getPostionY();
	kong.Pos.x = kong.c.getPostionX();
	kong.Pos.y = kong.c.getPostionY();
	kong.Power+=Vec2(0, -50);

	if(Stage::stage == 1){
		speed = 1.2;
	}
	else if(Stage::stage == 2){
		speed = 1.0;
	}
	else if(Stage::stage == 3){
		speed = 0.6;
	}	


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
	mario.Gravity_2(deltaTime);	
	mario.c.setPosition(mario.pos.x,mario.pos.y);
	kong.c.setPosition(kong.Pos.x, kong.Pos.y);

	Rect rect = niddle.spr->boundingBox();
	rect.setRect(rect.getMinX(), rect.getMinY(), rect.getMaxX(), rect.getMaxY());
	if(rect.intersectsRect(mario.c.getSpr()->boundingBox()))
	{
		if(niddle.power==1 && mario.hp_c >= 0){
			this->removeChild(User_HP[mario.hp_c]);
			if(mario.hp_c == 0){
				FAIL();
			}
			mario.hp[mario.hp_c] = 0;					
			mario.hp_c--;
			niddle.power = 0;
		}
	}

	for(int i=0; i<4; i++){
		jump[i]->Pos = Vec2(jump[i]->spr->getPosition());
		if(jump[i]->Pos.distance(mario.c.getPostion()) <=80)
		{
			//jump[i]->spr = Sprite::create("Bounce_down.png");
			if(mario.jump == false)
			{
				if(mario.ynjump == false)
				{
					mario.ynjump = true;
					mario.jump = true;
					mario.Power += Vec2(0, 400+(jump[i]->power));
								
					auto Sound_J = CocosDenshion::SimpleAudioEngine::sharedEngine();
				Sound_J->playEffect("Jump.wav",false);
				Sound_J->setBackgroundMusicVolume(0.8f);
				}
			}
		}
	}
	if(Timer>=5.0f){
		niddle.power = 1;
		Timer = 0.0;
	}

	if(Stage::stage==3 && kong.HP <= 0 ){
		AllClear();
	}
	else if(kong.HP <= 0 && Stage::stage!=3){
		Clear();
	}


	if(kong.Timer>=speed)
	{
		Stage::Score+=10;
		sprintf(tm, "STAGE : %d", Stage::Score);
		score_->setString(tm);
		new_Item = new _Item;

					auto Sound_K = CocosDenshion::SimpleAudioEngine::sharedEngine();
			Sound_K->playEffect("kong_attack.wav",false);
			Sound_K->setBackgroundMusicVolume(0.8f);

		if(Stage::stage == 1)
		{
			new_Item->_state = rand() % 4;
			switch(new_Item->_state)
			{
			case 0:{
				new_Item->spr = Sprite::create("Item_1.png");
				break;
				   }
			case 1:{
				new_Item->spr = Sprite::create("Item_2.png");
				break;
				   }
			case 2:{
				new_Item->spr = Sprite::create("UItem_1.png");
				break;
				   }
			case 3:{
				new_Item->spr = Sprite::create("UItem_2.png");
				break;
				   }
			}
		}
		else if(Stage::stage == 2){
			new_Item->_state = rand() % 5;
			switch(new_Item->_state)
			{
			case 0:{
				new_Item->spr = Sprite::create("Item_1.png");
				break;
				   }
			case 1:{
				new_Item->spr = Sprite::create("Item_2.png");
				break;
				   }
			case 2:{
				new_Item->spr = Sprite::create("Item_3.png");
				break;
				   }
			case 3:{
				new_Item->spr = Sprite::create("UItem_1.png");
				break;
				   }
			case 4:{
				new_Item->spr = Sprite::create("UItem_2.png");
				break;
				   }
			}
		}
		else{
			new_Item->_state = rand() % 6;
			switch(new_Item->_state)
			{
			case 0:{
				new_Item->spr = Sprite::create("Item_1.png");
				break;
				   }
			case 1:{
				new_Item->spr = Sprite::create("Item_2.png");
				break;
				   }
			case 2:{
				new_Item->spr = Sprite::create("Item_3.png");
				break;
				   }
			case 3:{
				new_Item->spr = Sprite::create("Item_4.png");
				break;
				   }
			case 4:{
				new_Item->spr = Sprite::create("UItem_1.png");
				break;
				   }
			case 5:{
				new_Item->spr = Sprite::create("UItem_2.png");
				break;
				   }
			}
		}

		new_Item->Pos = Vec2(kong.Pos);
		new_Item->spr->setPosition(0,0);
		new_Item->Des = Vec2(-random(0.5f,1.5f),0);
		this->addChild(new_Item->spr, 1);

		kong.Enermy_Item_L.push_back(new_Item);
		kong.c.setPlay(true);
		kong.Des.y = 0 - kong.Pos.y;
		kong.Des.normalize();
		kong.Timer = 0.0f;
	}

	while(itr3!=mario.User_Item_L.end()){
		(*itr3)->Pos+=(*itr3)->Des * 250 * deltaTime;
		for(int i=0; i<4; i++)
			(*itr3)->spr->setRotation(90.0*i);
		(*itr3)->spr->setPosition((*itr3)->Pos);
		if((*itr3)->Pos.distance(kong.c.getPostion()) <=100){
			this->removeChild((*itr3)->spr);
			delete (*itr3);
			mario.User_Item_L.erase(itr3++);
			if(kong.HP > 0){
				kong.HP-=1;
			}
			continue;
		}
		itr3++;
	}
	//kong.c.setPlay(true);
	//kong.c.setFrameNumber(0);

	float Enermy_HP_Bar= (float(kong.HP/100.f));
	Enermy_HP_Front->setScaleX(Enermy_HP_Bar);

	while(itr!=kong.Enermy_Item_L.end()){


		kong.c.setPlay(true);
		if((*itr)->_state != 0)
			(*itr)->Des.y -= deltaTime/2;
		(*itr)->Pos+=(*itr)->Des * 250 * deltaTime;
		(*itr)->spr->setPosition((*itr)->Pos);
		if((*itr)->Pos.distance(mario.c.getPostion()) <=50)
		{
			if(Stage::stage == 1)
			{
				if((*itr)->_state==1){
					life_ =1;
					Stage::Score-=100;
					sprintf(tm, "STAGE : %d", Stage::Score);
					score_->setString(tm);
				}
				else if((*itr)->_state==2)
				{
					life_ =2;
				}
				else if((*itr)->_state == 3){
					Stage::Score+=50;
					sprintf(tm, "STAGE : %d", Stage::Score);
					score_->setString(tm);
				}
				else
					life_=1;
			}
			else if(Stage::stage == 2)
			{
				if((*itr)->_state==1){
					life_ =1;
					Stage::Score-=100;
					sprintf(tm, "STAGE : %d", Stage::Score);
					score_->setString(tm);
				}	
				else if((*itr)->_state==3)
				{
					life_ =2;
				}
				else if((*itr)->_state == 4){
					Stage::Score+=50;
					sprintf(tm, "STAGE : %d", Stage::Score);
					score_->setString(tm);
				}
				else
					life_=1;
			}
			else if(Stage::stage == 3)
			{
				if((*itr)->_state==1){
					life_ =1;
					Stage::Score-=100;
					sprintf(tm, "STAGE : %d", Stage::Score);
					score_->setString(tm);
				}	
				else if((*itr)->_state==4)
				{
					life_=2;
				}
				else if((*itr)->_state == 5){
					Stage::Score+=50;
					sprintf(tm, "STAGE : %d", Stage::Score);
					score_->setString(tm);
				}
				else
					life_=1;
			}
			if(life_==1)
			{
				if(mario.hp_c >= 0){
					this->removeChild(User_HP[mario.hp_c]);
					mario.hp[mario.hp_c] = 0;
					if(mario.hp_c == 0){
						FAIL();
					}
					mario.hp_c--;
				}
				life_=3;
			}
			if(life_==2)
			{
				if(mario.hp_c < MAX_LIFE-1)
				{
					mario.hp_c++;
					User_HP[mario.hp_c] = Sprite::create("UItem_1.png");
					User_HP[mario.hp_c]->setPosition(visibleSize.width-300 + mario.hp_c*50, visibleSize.height-630);
					this->addChild(User_HP[mario.hp_c]);
					mario.hp[mario.hp_c] = 1;
					life_=3;
				}
			}
			this->removeChild((*itr)->spr);
			delete (*itr);
			kong.Enermy_Item_L.erase(itr++);
			continue;
		}
		itr++;
	}
	if(kong.state == 0 && kong.HP <= 0)
		kong.state = 1;

	if(Stage::stage==1)
		kong.c.Update(speed / 132);
	else if(Stage::stage==2)
		kong.c.Update(speed / 94);
	else if(Stage::stage==3)
		kong.c.Update(speed / 37);
	mario.c.Update(deltaTime);	
}
void Battle::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) 
{
	CCLOG("onKeyPressed : %d",keyCode);
	Size visibleSize = Director::getInstance()->getVisibleSize();

	switch (keyCode) {
	case EventKeyboard::KeyCode::KEY_L:{
		mario.state = 1;
		x = mario.c.setfilpX_0();
		break;
									   }
	case EventKeyboard::KeyCode::KEY_J:{
		mario.state = 2;
		x = mario.c.setfilpX_1();
		break;
									   }
	case EventKeyboard::KeyCode::KEY_A:{
		auto Sound_E = CocosDenshion::SimpleAudioEngine::sharedEngine();
		Sound_E->playEffect("attack.wav",false);
		Sound_E->setBackgroundMusicVolume(0.8f);
	
		y=mario.pos.y;
		User_Item = new _Item;
		User_Item->_state = 1;
		User_Item->spr = Sprite::create("fire.png");
		User_Item->Pos = Vec2(mario.c.getPostionX(), mario.c.getPostionY());
		User_Item->spr->setPosition(0,0);
		this->addChild(User_Item->spr, 3);
		User_Item->Des.x = visibleSize.width;
		User_Item->Des.normalize();
		mario.User_Item_L.push_back(User_Item);

		break;
									   }
	case EventKeyboard::KeyCode::KEY_S:{
		mario.state=3;
		break;
									   }
	}
}

void Battle::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) {
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
		User_Item->_state = 0;
		break;
									   }
	case EventKeyboard::KeyCode::KEY_S:{
		mario.state = 0;
		break;
									   }
	}
}

void Battle::FAIL()
{
	auto B = MissonFail::createScene();
	Director::sharedDirector()->replaceScene(B);
}

void Battle::Clear()
{
	auto C = MissonClear::createScene();
	Director::sharedDirector()->replaceScene(C);
}

void Battle::AllClear()
{
	auto D = AllClear::createScene();
	Director::sharedDirector()->replaceScene(D);
}