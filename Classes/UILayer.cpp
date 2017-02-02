#include"UILayer.h"
USING_NS_CC;

Scene* UIbt::createScene()
{
	auto scene = Scene::create();
	auto layer = UIbt::create();
	scene->addChild(layer);
	return scene;
}


bool UIbt::init(){
	if (!Layer::init())
	{
		return false;
	}
	//auto layer = CCLayerColor::create(ccc4(0, 213, 204, 0xff));
	//this->addChild(layer);
	Sprite * BG = Sprite::create("backG.png");
	BG->setAnchorPoint(ccp(0, 0));
	BG->setPosition(ccp(0, 0));
	this->addChild(BG);

	auto sp1 = Sprite::create("HelloWorld1.png");
	auto sp2 = Sprite::create("HelloWorld2.png");
	auto sp3 = Sprite::create("HelloWorld3.png");
	sp1->setAnchorPoint(ccp(0, 0));
	sp2->setAnchorPoint(ccp(0, 0));
	sp3->setAnchorPoint(ccp(0, 0));
	sp1->setPosition(ccp(-sp1->getContentSize().width, VISIBLE_SIZE.height*0.4));
	sp2->setPosition(ccp(-sp2->getContentSize().width, VISIBLE_SIZE.height*0.6));
	sp3->setPosition(ccp(-sp3->getContentSize().width, VISIBLE_SIZE.height*0.8));
	sp1->setTag(211);
	sp2->setTag(212);
	sp3->setTag(213);
	this->addChild(sp1);
	this->addChild(sp2);
	this->addChild(sp3);
	addButton();
	
	

	auto call1 = CallFunc::create([this](){
		auto sp1Up = CCMoveBy::create(1, ccp(380, 0));
		auto sp1EaseOut = CCEaseExponentialOut::create(sp1Up);


		auto sp2Down = CCMoveBy::create(1, ccp(470, 0));
		auto sp2EaseOut = CCEaseExponentialOut::create(sp2Down);

		auto sp3Down = CCMoveBy::create(1, ccp(560, 0));
		auto sp3EaseOut = CCEaseExponentialOut::create(sp3Down);

		this->getChildByTag(211)->runAction(sp1EaseOut);
		this->getChildByTag(212)->runAction(sp2EaseOut);
		this->getChildByTag(213)->runAction(sp3EaseOut);

		scoreAction();

	});
	this->runAction(Sequence::create(DelayTime::create(0.6
		), call1, nullptr));

	return true;
}

void UIbt::addButton(){

	//加入开始按钮
	/*Sprite * begin1 = Sprite::create("player.png");
	Sprite * begin2 = Sprite::create("player.png");
	auto beganGame = cocos2d::CCMenuItemSprite::create(begin1, begin2, CC_CALLBACK_0(UIbt::beginCallback, this, NULL));
	float Bdw = begin1->getContentSize().width - begin1->getContentSize().width;
	float Bhw = begin2->getContentSize().height - begin2->getContentSize().height;
	begin2->setPosition(ccp(Bdw / 2 + 20, Bhw / 2 + 20));
	auto beginMenu = Menu::create(beganGame, NULL);
	

	*/


	//评分
	Sprite * rank1 = Sprite::create("NewGameUI.png");
	Sprite * rank2 = Sprite::create("NewGameUI.png");
	auto menuRank = cocos2d::CCMenuItemSprite::create(rank1, rank2, CC_CALLBACK_0(UIbt::rankCallback, this, NULL));
	float Rdw = rank1->getContentSize().width - rank1->getContentSize().width;
	float Rhw = rank2->getContentSize().height - rank2->getContentSize().height;
	rank2->setPosition(ccp(Rdw / 2 + 20, Rhw / 2 + 20));
	auto rankMenu = Menu::create(menuRank, NULL);
	//分享
	Sprite * share1 = Sprite::create("NewGameUI.png");
	Sprite * share2 = Sprite::create("NewGameUI.png");
	auto menuShare = cocos2d::CCMenuItemSprite::create(share1, share2, CC_CALLBACK_0(UIbt::shareCallback, this, NULL));
	float Sdw = share1->getContentSize().width - share1->getContentSize().width;
	float Shw = share2->getContentSize().height - share2->getContentSize().height;
	share2->setPosition(ccp(Sdw / 2 + 20, Shw / 2 + 20));
	auto shareMenu = Menu::create(menuShare, NULL);
	//帮助
	Sprite * help1 = Sprite::create("NewGameUI.png");
	Sprite * help2 = Sprite::create("NewGameUI.png");
	auto menuHelp = cocos2d::CCMenuItemSprite::create(help1, help2, CC_CALLBACK_0(UIbt::helpCallback, this, NULL));
	float Hdw = help1->getContentSize().width - help1->getContentSize().width;
	float Hhw = help2->getContentSize().height - help2->getContentSize().height;
	help2->setPosition(ccp(Hdw / 2 + 20, Hhw / 2 + 20));
	auto helpMenu = Menu::create(menuHelp, NULL);
	//声音
	Sprite * music1 = Sprite::create("NewGameUI.png");
	Sprite * music2 = Sprite::create("NewGameUI.png");
	auto menuMusic = cocos2d::CCMenuItemSprite::create(music1, music2, CC_CALLBACK_0(UIbt::musicCallback, this, NULL));
	float Mdw = music1->getContentSize().width - music1->getContentSize().width;
	float Mhw = music2->getContentSize().height - music2->getContentSize().height;
	music2->setPosition(ccp(Mdw / 2 + 20, Mhw / 2 + 20));
	auto musicMenu = Menu::create(menuMusic, NULL);


	//beginMenu->setPosition(Point(VISIBLE_SIZE.width*0.5, VISIBLE_SIZE.height*0.4));
	rankMenu->setPosition(Point(VISIBLE_SIZE.width*0.9 - menuRank->getContentSize().width, VISIBLE_SIZE.height*0.2));
	shareMenu->setPosition(Point(VISIBLE_SIZE.width*0.7 - menuShare->getContentSize().width, VISIBLE_SIZE.height*0.2));
	helpMenu->setPosition(Point(VISIBLE_SIZE.width*0.1 + menuHelp->getContentSize().width, VISIBLE_SIZE.height*0.2));
	musicMenu->setPosition(Point(VISIBLE_SIZE.width*0.3 + menuMusic->getContentSize().width, VISIBLE_SIZE.height*0.2));



	//rankMenu->runAction(srankEaseElaActionSeque);



	//shareMenu->runAction(shareEaseEla);

	rankMenu->setTag(1);
	shareMenu->setTag(2);
	helpMenu->setTag(3);
	musicMenu->setTag(4);
	//this->addChild(beginMenu);
	this->getChildByTag(212)->addChild(rankMenu);
	this->getChildByTag(212)->addChild(shareMenu);
	this->getChildByTag(212)->addChild(helpMenu);
	this->getChildByTag(212)->addChild(musicMenu);

}
void UIbt::beginCallback(float dt){

	//auto sp1Up = CCMoveBy::create(4, ccp(0, VISIBLE_SIZE.height));
	//auto sp1EaseOut = CCEaseExponentialOut::create(sp1Up);
	//this->getChildByTag(11)->runAction(sp1EaseOut);

	auto sp2Down = CCMoveBy::create(4, ccp(0, -VISIBLE_SIZE.height));
	auto sp2EaseOut = CCEaseExponentialOut::create(sp2Down);
	//this->getChildByTag(212)->runAction(sp2EaseOut);
	//scoreColor  out
	int scoreOut = CCUserDefault::sharedUserDefault()->getIntegerForKey("Score", 0);
	for (int j = 1; j <= scoreOut; j++){
		auto scoreMove = CCMoveBy::create(1.1 + 0.1*j, ccp(-VISIBLE_SIZE.width, 0));
		auto scoreEaseOut = CCEaseExponentialOut::create(scoreMove);
		this->getChildByTag(100+j)->runAction(scoreEaseOut);
	}
	//hw->beginG();
	//推迟

	auto call = CallFunc::create([](){
		//auto scene = GameLayer::createScene();
		//Director::getInstance()->replaceScene(CCTransitionFade::create(1.5, scene));
	});
	this->runAction(Sequence::create(DelayTime::create(1), call, nullptr));

	

}

void UIbt::endGame(){
	

}
void UIbt::rankCallback(float dt){
}
void UIbt::shareCallback(float dt){
}
void UIbt::helpCallback(float dt){
}
void UIbt::musicCallback(float dt){
}


void UIbt::scoreAction(){
	int score = CCUserDefault::sharedUserDefault()->getIntegerForKey("Score", 0);
	float firstPosX = (VISIBLE_SIZE.width - (score - 1) * 60) / 2;
	for (int i = 1; i <= score; i++){
		auto scoreColor = CCSprite::create("NewGameUI.png");
		scoreColor->setPosition(firstPosX + (i - 1) * 60 + VISIBLE_SIZE.width, 800);
		scoreColor->setTag(100+i);
		this->addChild(scoreColor);
		auto scoreMove = CCMoveBy::create(0.5+0.1*i, ccp(-VISIBLE_SIZE.width, 0));
		auto scoreEaseOut = CCEaseExponentialOut::create(scoreMove);
		scoreColor->runAction(scoreEaseOut);
	}
}
