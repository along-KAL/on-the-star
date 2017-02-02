#include"GameLayer.h"
USING_NS_CC;
namespace mf = MyFunc;
using namespace CocosDenshion;
/*Scene* GameLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = GameLayer::create();
	scene->addChild(layer);
	return scene;
}*/


bool GameLayer::init(){
	
	if (!Layer::init())
	{
		return false;
	}
	

	

	//点灯泡，踩，出星星，按钮，黑洞吸
	/*	//1.设置背景颜色
	Sprite * BG1 = Sprite::create("backG.png");
	BG1->setAnchorPoint(ccp(0, 0));
	BG1->setPosition(ccp(0, 0));
	BG1->setTag(2001);
	this->addChild(BG1);

	Sprite * BG2 = Sprite::create("backG.png");
	BG2->setAnchorPoint(ccp(0, 0));
	BG2->setPosition(ccp(0, VISIBLE_SIZE.height));
	BG2->setTag(2002);
this->addChild(BG2);

	Sprite * BG3 = Sprite::create("backG.png");
	BG3->setAnchorPoint(ccp(0, 0));
	BG3->setPosition(ccp(0, 2*VISIBLE_SIZE.height));
	BG3->setTag(2003);
	this->addChild(BG3);
*/

	
	isPause = CCUserDefault::sharedUserDefault()->getBoolForKey("isPause", false);
	if (!isPause){ SimpleAudioEngine::sharedEngine()->playBackgroundMusic("BGM.mp3", true); }
	//摄影机
	 camera = Camera::createOrthographic(VISIBLE_SIZE.width, VISIBLE_SIZE.height, 0, 1);
	camera->setCameraFlag(CameraFlag::USER1);
	this->addChild(camera);
	//初始化BlocksLayer
	InitBlocksLayer();

	int sign = int(1 + (rand()) % 4);
	if (sign == 3){
		CCSprite *pingfenTishi = CCSprite::createWithSpriteFrameName("pingfenTishiE.png");
		pingfenTishi->setPosition(850, 300);
		pingfenTishi->setScale(0);
		pingfenTishi->setAnchorPoint(ccp(1, 0.5));
		this->addChild(pingfenTishi);

		auto calleffect = CallFunc::create([this, pingfenTishi](){
			this->removeChild(pingfenTishi);
		});
		pingfenTishi->runAction(RepeatForever::create(Sequence::create(CCEaseExponentialOut::create(ScaleTo::create(0.5, 1)), FadeOut::create(7), calleffect, nullptr)));
	}

	if (!CCUserDefault::sharedUserDefault()->getBoolForKey("effect", true)){
		CCSprite *addTishi = CCSprite::createWithSpriteFrameName("addEffect.png");
		addTishi->setPosition(850, 800);
		addTishi->setScale(0);
		addTishi->setAnchorPoint(ccp(1,0.5));
		this->addChild(addTishi);

		auto calleffect = CallFunc::create([this, addTishi](){
			this->removeChild(addTishi);
		});
		addTishi->runAction(RepeatForever::create(Sequence::create(CCEaseExponentialOut::create(ScaleTo::create(0.5, 1)), FadeOut::create(5), calleffect, nullptr)));
	}
	else
	{
		CCSprite *effectTishi = CCSprite::createWithSpriteFrameName("effectTishi2.png");
		effectTishi->setPosition(850, 800);
		effectTishi->setScale(0);
		effectTishi->setAnchorPoint(ccp(1, 0.5));
		this->addChild(effectTishi);
		auto calleffect = CallFunc::create([this, effectTishi](){
			this->removeChild(effectTishi);
		});
		effectTishi->runAction(RepeatForever::create(Sequence::create(CCEaseExponentialOut::create(ScaleTo::create(0.5, 1)),FadeOut::create(5), calleffect, nullptr)));
	}
	CCSprite *effectImage = CCSprite::createWithSpriteFrameName("effect.png");
	//Sprite * signImage = Sprite::create("wen.png");
	auto effectImageGame = cocos2d::CCMenuItemSprite::create(effectImage, effectImage, CC_CALLBACK_0(GameLayer::effectImageCallback, this, NULL));
	auto effectImageMenu = CCMenu::create(effectImageGame, NULL);
	effectImageMenu->setPosition(ccp(1000, 800));
	this->addChild(effectImageMenu);
	effectImageMenu->setTag(0);

	CCSprite *signImage = CCSprite::createWithSpriteFrameName("wen.png");
	//Sprite * signImage = Sprite::create("wen.png");
			auto signImageGame = cocos2d::CCMenuItemSprite::create(signImage, signImage, CC_CALLBACK_0(GameLayer::signImageCallback, this, NULL));
			auto signImageMenu = CCMenu::create(signImageGame, NULL);
			signImageMenu->setPosition(ccp(1000, 700));
			this->addChild(signImageMenu);
			signImageMenu->setTag(1);

			CCSprite *showAchivementImage = CCSprite::createWithSpriteFrameName("chengjiu.png");
		//Sprite * showAchivementImage = Sprite::create("chengjiu.png");
		auto showAchiveImageGame = cocos2d::CCMenuItemSprite::create(showAchivementImage, showAchivementImage, CC_CALLBACK_0(GameLayer::showAchivementImageCallback, this, NULL));
		auto showAchiveImageMenu = CCMenu::create(showAchiveImageGame, NULL);
		showAchiveImageMenu->setPosition(ccp(1000, 600));
		this->addChild(showAchiveImageMenu);
		showAchiveImageMenu->setTag(2);

		CCSprite *showLeaderboardsImage = CCSprite::createWithSpriteFrameName("paihangbang.png");
		//Sprite * showLeaderboardsImage = Sprite::create("paihangbang.png");
		auto showLeaderboardsImageGame = cocos2d::CCMenuItemSprite::create(showLeaderboardsImage, showLeaderboardsImage, CC_CALLBACK_0(GameLayer::showLeaderboardsImageCallback, this, NULL));
			auto showLeaderboardsImageMenu = CCMenu::create(showLeaderboardsImageGame, NULL);
			showLeaderboardsImageMenu->setPosition(ccp(1000, 500));
			this->addChild(showLeaderboardsImageMenu);
			showLeaderboardsImageMenu->setTag(3);
			
			//
			CCSprite *shareImage = CCSprite::createWithSpriteFrameName("fenxiang.png");
			//Sprite * shareImage = Sprite::create("fenxiang.png");
			auto shareImageGame = cocos2d::CCMenuItemSprite::create(shareImage, shareImage, CC_CALLBACK_0(GameLayer::shareImageCallback, this, NULL));
			auto shareImageMenu = CCMenu::create(shareImageGame, NULL);
			shareImageMenu->setPosition(ccp(1000, 400));
			this->addChild(shareImageMenu);
			shareImageMenu->setTag(4);

			CCSprite *pingfenImage = CCSprite::createWithSpriteFrameName("pingfen.png");
			//Sprite * pingfenImage = Sprite::create("pingfen.png");
			auto pingfenImageGame = cocos2d::CCMenuItemSprite::create(pingfenImage, pingfenImage, CC_CALLBACK_0(GameLayer::pingfenImageCallback, this, NULL));
			auto pingfenImageMenu = CCMenu::create(pingfenImageGame, NULL);
			pingfenImageMenu->setPosition(ccp(1000, 300));
			this->addChild(pingfenImageMenu);
			pingfenImageMenu->setTag(5);
			MenuItemImage *_turnOn, *_turnOff;
			_turnOn = MenuItemImage::create(
				"musicOpen.png",
				"musicOpen.png");
			_turnOff = MenuItemImage::create(
				"musicClose.png",
				"musicClose.png");
			MenuItemToggle *toggleItem;
			if (!isPause){
				// 添加 声音  的开关按钮
				toggleItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(GameLayer::menuMusicCallback, this), _turnOn, _turnOff, NULL);
			}
		else
			{// 添加 声音  的开关按钮
			toggleItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(GameLayer::menuMusicCallback, this), _turnOff,_turnOn, NULL);
		}
			auto menu = CCMenu::create(toggleItem, NULL);
			menu->setPosition(Point(1000, 200));
			menu->setTag(6);
			addChild(menu);
			/*Sprite * musicImage = Sprite::create("musicOpen.png");
			auto musicImageGame = cocos2d::CCMenuItemSprite::create(musicImage, musicImage, CC_CALLBACK_0(GameLayer::showLeaderboardsImageCallback, this, NULL));
			auto musicImageMenu = CCMenu::create(musicImageGame, NULL);
			musicImageMenu->setPosition(ccp(1000, 200));
			this->addChild(musicImageMenu);
			musicImageMenu->setTag(6);
			*/
			effectImageMenu->runAction(CCEaseExponentialOut::create(CCMoveBy::create(0.1, ccp(-120, 0))));
			signImageMenu->runAction(CCEaseExponentialOut::create(CCMoveBy::create(0.3, ccp(-120, 0))));
			showAchiveImageMenu->runAction(CCEaseExponentialOut::create(CCMoveBy::create(0.5, ccp(-120, 0))));
			showLeaderboardsImageMenu->runAction(CCEaseExponentialOut::create(CCMoveBy::create(0.7, ccp(-120, 0))));
			shareImageMenu->runAction(CCEaseExponentialOut::create(CCMoveBy::create(0.9, ccp(-120, 0))));
			pingfenImageMenu->runAction(CCEaseExponentialOut::create(CCMoveBy::create(1.1, ccp(-120, 0))));
			menu->runAction(CCEaseExponentialOut::create(CCMoveBy::create(1.3, ccp(-120, 0))));


			int score = CCUserDefault::sharedUserDefault()->getIntegerForKey("nearScore", 0);
			if (score == 0){
				CCTexture2D *texture_score0 = CCTextureCache::sharedTextureCache()->textureForKey("playerTou.png");

				//实例化精灵  
				CCSprite *score0 = CCSprite::createWithTexture(texture_score0);
				score0->setPosition(70, VISIBLE_SIZE.height*0.5);
				score0->setTag(631);
				this->addChild(score0);
			}
			else if (score == 1){
					CCSprite *score1 = CCSprite::createWithSpriteFrameName("score1.png");
					score1->setPosition(70, VISIBLE_SIZE.height*0.5);
					score1->setTag(631);
					this->addChild(score1);
				}
				else if (score == 2){
					CCSprite *score2 = CCSprite::createWithSpriteFrameName("score2.png");
					score2->setPosition(70, VISIBLE_SIZE.height*0.5);
					score2->setTag(631);
					this->addChild(score2);
				}
				else if (score == 3){
					CCSprite *score3 = CCSprite::createWithSpriteFrameName("score3.png");
					score3->setPosition(70, VISIBLE_SIZE.height*0.5);
					score3->setTag(631);
					this->addChild(score3);
				}
				else if (score == 4){
					CCSprite *score4 = CCSprite::createWithSpriteFrameName("score4.png");
					score4->setPosition(70, VISIBLE_SIZE.height*0.5);
					score4->setTag(631);
					this->addChild(score4);
				}
				else if (score == 5){
					CCSprite *score5 = CCSprite::createWithSpriteFrameName("score5.png");
					score5->setPosition(70, VISIBLE_SIZE.height*0.5);
					score5->setTag(631);
					this->addChild(score5);
				}
				else if (score == 6){
					CCSprite *score6 = CCSprite::createWithSpriteFrameName("score6.png");
					score6->setPosition(70, VISIBLE_SIZE.height*0.5);
					score6->setTag(631);
					this->addChild(score6);
				}
				else if (score == 7){
					CCSprite *score7 = CCSprite::createWithSpriteFrameName("score7.png");
					score7->setPosition(70, VISIBLE_SIZE.height*0.5);
					score7->setTag(631);
					this->addChild(score7);
				}
				else if (score == 8){
					CCSprite *score8 = CCSprite::createWithSpriteFrameName("score8.png");
					score8->setPosition(70, VISIBLE_SIZE.height*0.5);
					score8->setTag(631);
					this->addChild(score8);
				}
				else if (score == 9){
					CCSprite *score9 = CCSprite::createWithSpriteFrameName("score9.png");
					score9->setPosition(70, VISIBLE_SIZE.height*0.5);
					score9->setTag(631);
					this->addChild(score9);
				}
				else{
					CCSprite *score10 = CCSprite::createWithSpriteFrameName("score10.png");
					score10->setPosition(70, VISIBLE_SIZE.height*0.5);
					score10->setTag(631);
					this->addChild(score10);
				}

			

	//摄像机更新
	this->schedule(schedule_selector(GameLayer::updata3));
	//
//	this->schedule(schedule_selector(GameLayer::updata1));
	//检测死亡
	this->schedule(schedule_selector(GameLayer::updata2));

	//设置相机掩码	 
	this->setCameraMask(2);

	//设置初值
	bg_Sign = 1;

	bg_sign1 = true;
	bg_sign2 = true;
	bg_sign3 = true;

	return true;
}

/*void GameLayer::updata1(float dt){
	//更新背景
	if (camera->getPositionY() > VISIBLE_SIZE.height*bg_Sign){
		if (bg_sign1 == true){
			this->getChildByTag(2001)->setPosition(ccp(0, (bg_Sign + 2)*VISIBLE_SIZE.height));
			bg_sign1 = false;
			bg_sign2 = true;
		}
		else if (bg_sign2 == true){
			this->getChildByTag(2002)->setPosition(ccp(0, (bg_Sign + 2)*VISIBLE_SIZE.height));
			bg_sign2 = false;
			bg_sign1 = false;
		}
		else{
			this->getChildByTag(2003)->setPosition(ccp(0, (bg_Sign + 2)*VISIBLE_SIZE.height));
			bg_sign1 = true;
		}
		bg_Sign++;
	}
}

*/



void GameLayer::InitBlocksLayer(){
	//初始化Blocks
	_blockLayer = BlocksLayer::create();
	_blockLayer->setPosition(ccp(0,0));
	this->addChild(_blockLayer);

}


//摄像机更新
void GameLayer::updata3(float dt)
{
	//log("%f       %f", Player::sharePlayer()->getPositionY(), camera->getPositionY() + VISIBLE_SIZE.height*0.5);
	
	if (Player::sharePlayer()->getPositionY() > camera->getPositionY() + VISIBLE_SIZE.height*0.5)
	{
		camera->setPositionY(Player::sharePlayer()->getPositionY() - VISIBLE_SIZE.height*0.5);
		
	}
	//传递camera高度
	_blockLayer->setCameraHeight(camera->getPositionY());
	
}

//检测死亡
void GameLayer::updata2(float dt)
{
	
	//检测死亡
	if (Player::sharePlayer()->getPosition().y <camera->getPosition().y)
	{	//停止所有无关schedule
		SimpleAudioEngine::sharedEngine()->playEffect("over.wav", false);
		this->unschedule(schedule_selector(GameLayer::updata2));
		this->unschedule(schedule_selector(GameLayer::updata3));
	//	this->unschedule(schedule_selector(GameLayer::updata1));
		this->scheduleOnce(schedule_selector(GameLayer::overCallback), 1);
		//this->scheduleOnce(schedule_selector(GameLayer::overCallback), 2.2);
		//this->scheduleOnce(schedule_selector(GameLayer::GUIWEIcallback), 0.8);
		
	//开启摄像机跟踪
		//this->schedule(schedule_selector(GameLayer::updata4));
	//	_ocension = Player::sharePlayer()->getPositionY()-VISIBLE_SIZE.height;
	//	sign_CH = camera->getPositionY();
	//	_blockLayer->createOcenion();
	}
}
//player下落


void GameLayer::unsch2(){
	this->unschedule(schedule_selector(GameLayer::updata2));
}

void GameLayer::finalGame(){
	this->unschedule(schedule_selector(GameLayer::updata2));
	this->unschedule(schedule_selector(GameLayer::updata3));
	this->scheduleOnce(schedule_selector(GameLayer::overCallback), 1);

}

void GameLayer::UIOut(){
	this->getChildByTag(0)->runAction(CCEaseExponentialOut::create(CCMoveBy::create(0.1, ccp(150, 0))));
	this->getChildByTag(1)->runAction(CCEaseExponentialOut::create(CCMoveBy::create(0.3, ccp(150, 0))));
	this->getChildByTag(2)->runAction(CCEaseExponentialOut::create(CCMoveBy::create(0.7, ccp(150, 0))));
	this->getChildByTag(3)->runAction(CCEaseExponentialOut::create(CCMoveBy::create(1.1, ccp(150, 0))));
	this->getChildByTag(4)->runAction(CCEaseExponentialOut::create(CCMoveBy::create(1.5, ccp(150, 0))));
	this->getChildByTag(5)->runAction(CCEaseExponentialOut::create(CCMoveBy::create(1.9, ccp(150, 0))));
	this->getChildByTag(6)->runAction(CCEaseExponentialOut::create(CCMoveBy::create(2.3, ccp(150, 0))));
	this->getChildByTag(631)->runAction(CCEaseExponentialOut::create(CCMoveBy::create(2.7, ccp(-400, 0))));
}



void GameLayer::overCallback(float dt){
	
	_blockLayer->bl_action();
	auto call1 = CallFunc::create([this](){
		
		if (CCUserDefault::sharedUserDefault()->getIntegerForKey("Score", 0) < _blockLayer->getJIshu())
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("Score", _blockLayer->getJIshu());
			CCUserDefault::sharedUserDefault()->flush();
		}
		
			CCUserDefault::sharedUserDefault()->setIntegerForKey("nearScore", _blockLayer->getJIshu());
			CCUserDefault::sharedUserDefault()->flush();
		
		this->removeAllChildren();
		//auto call = CallFunc::create([](){
		auto scene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(scene);
	});
	this->runAction(Sequence::create(DelayTime::create(2
		), call1, nullptr));
	
	

	

	

	
}




LightEffect * GameLayer::getEffect_G(){

	return _blockLayer->getEffect();
}






void GameLayer::effectImageCallback(float dt){
	SimpleAudioEngine::sharedEngine()->playEffect("anniuM.wav", false);
	if (!CCUserDefault::sharedUserDefault()->getBoolForKey("effect", true) ){
		CCUserDefault::sharedUserDefault()->setBoolForKey("effect", true);
		CCUserDefault::sharedUserDefault()->flush();
	}
	else{
		CCUserDefault::sharedUserDefault()->setBoolForKey("effect", false);
		CCUserDefault::sharedUserDefault()->flush();
	}
	this->unschedule(schedule_selector(GameLayer::updata2));
	this->unschedule(schedule_selector(GameLayer::updata3));

	this->removeAllChildren();
	auto scene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(scene);
}

void GameLayer::signImageCallback(float dt){
	//if(!NativeUtils::isSignedIn()){
	SimpleAudioEngine::sharedEngine()->playEffect("anniuM.wav", false);
	auto s = CCMoveBy::create(0.05, ccp(-40, 0));
	this->getChildByTag(1)->runAction(Sequence::create(s, s->reverse(), nullptr));


	CCTexture2D *texture_guildImage = CCTextureCache::sharedTextureCache()->textureForKey("guildE.png");

	//实例化精灵  
	CCSprite *guildImage = CCSprite::createWithTexture(texture_guildImage);
	//	Sprite * wenImage = Sprite::create(fileSprite);
	auto guildImageGame = cocos2d::CCMenuItemSprite::create(guildImage, guildImage, CC_CALLBACK_0(GameLayer::wenImageCallback, this, NULL));
	auto guildImageMenu = CCMenu::create(guildImageGame, NULL);
	guildImageMenu->setPosition(ccp(480, 700));
	guildImageMenu->setTag(10);
	guildImageMenu->setOpacity(0);
	this->addChild(guildImageMenu, 10);
	guildImageMenu->runAction(CCFadeIn::create(0.3));
	//auto s = CCMoveBy::create(0.05, ccp(-40, 0));
	//	}
}
void GameLayer::wenImageCallback(float dt){
	
	auto call5 = CallFunc::create([this](){
		this->removeChildByTag(10);

	});
	this->getChildByTag(10)->runAction(Sequence::create(CCFadeOut::create(0.3), call5, nullptr));
}


void GameLayer::showAchivementImageCallback(float dt){


if (CCUserDefault::sharedUserDefault()->getIntegerForKey("Score", 0) == 6)
	{
		NativeUtils::unlockAchievement("CgkIuJfk65gMEAIQAQ");
	}
	else if (CCUserDefault::sharedUserDefault()->getIntegerForKey("Score", 0) == 7)
	{
		NativeUtils::unlockAchievement("CgkIuJfk65gMEAIQAw");
	}
	else if (CCUserDefault::sharedUserDefault()->getIntegerForKey("Score", 0) == 8)
	{
		NativeUtils::unlockAchievement("CgkIuJfk65gMEAIQAg");
	}
	else if (CCUserDefault::sharedUserDefault()->getIntegerForKey("Score", 0) == 9)
	{
		NativeUtils::unlockAchievement("CgkIuJfk65gMEAIQBA");
	}
	else if (CCUserDefault::sharedUserDefault()->getIntegerForKey("Score", 0) == 10)
	{
		NativeUtils::unlockAchievement("CgkIuJfk65gMEAIQBQ");
	}
	SimpleAudioEngine::sharedEngine()->playEffect("anniuM.wav", false);
	auto s = CCMoveBy::create(0.05, ccp(-40, 0));
	this->getChildByTag(2)->runAction(Sequence::create(s, s->reverse(), nullptr));
			NativeUtils::showAchievements();
	
}


void GameLayer::showLeaderboardsImageCallback(float dt){


	NativeUtils::submitScore("CgkIuJfk65gMEAIQBg", CCUserDefault::sharedUserDefault()->getIntegerForKey("Score", 0));
	SimpleAudioEngine::sharedEngine()->playEffect("anniuM.wav", false);
	auto s = CCMoveBy::create(0.05, ccp(-40, 0));
	this->getChildByTag(3)->runAction(Sequence::create(s, s->reverse(), nullptr));
		NativeUtils::showLeaderboard("CgkIuJfk65gMEAIQBg");

}




void GameLayer::shareImageCallback(float dt){
	SimpleAudioEngine::sharedEngine()->playEffect("anniuM.wav", false);
	auto s = CCMoveBy::create(0.05, ccp(-40, 0));
	this->getChildByTag(4)->runAction(Sequence::create(s, s->reverse(), nullptr));
//	CCSize size = CCDirector::sharedDirector()->getWinSize();
/*	CCRenderTexture * texture = CCRenderTexture::create(1440, 960);
	texture->setPosition(ccp(VISIBLE_SIZE.width / 2, VISIBLE_SIZE.height / 2));
	texture->begin();
	CCDirector::sharedDirector()->getRunningScene()->visit();
	texture->end();
	texture->saveToFile("screenShot.png", kCCImageFormatPNG);
	this->scheduleOnce(schedule_selector(GameLayer::shareCallback), 0.5);*/
	NativeUtils::share();
	//	}
}
//void GameLayer::shareCallback(float dt){ }

void GameLayer::pingfenImageCallback(float dt){
	SimpleAudioEngine::sharedEngine()->playEffect("anniuM.wav", false);
	auto s = CCMoveBy::create(0.05, ccp(-40, 0));
	this->getChildByTag(5)->runAction(Sequence::create(s, s->reverse(), nullptr));
	//if(NativeUtils::isSignedIn()){
	NativeUtils::pingFen();
	//		}
}


void GameLayer::menuMusicCallback(cocos2d::Ref* pSender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("anniuM.wav", false);
	if (isPause == false)
	{
		
		auto s = CCMoveBy::create(0.05, ccp(-40, 0));
		this->getChildByTag(6)->runAction(Sequence::create(s, s->reverse(), nullptr));
		SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
		SimpleAudioEngine::sharedEngine()->pauseAllEffects();
		isPause = true;
		CCUserDefault::sharedUserDefault()->setBoolForKey("isPause", isPause);
	}
	else
	{
		CCUserDefault::sharedUserDefault()->setBoolForKey("isPause", isPause);
		auto s = CCMoveBy::create(0.05, ccp(-40, 0));
		this->getChildByTag(6)->runAction(Sequence::create(s, s->reverse(), nullptr));
		if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()){
			SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
		}	
		else
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("BGM.mp3", true);
		SimpleAudioEngine::sharedEngine()->resumeAllEffects();
		isPause = false;
		CCUserDefault::sharedUserDefault()->setBoolForKey("isPause", isPause);
	}
}



void GameLayer::removeUI(){
	this->removeChildByTag(1);
	this->removeChildByTag(2);
	this->removeChildByTag(3);
	this->removeChildByTag(4);
	this->removeChildByTag(5);
	this->removeChildByTag(6);
	this->removeChildByTag(631);
}
