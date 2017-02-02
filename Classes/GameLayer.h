#pragma once 
#ifndef _GAME_LAYER_H_
#define _GAME_LAYER_H
#include"cocos2d.h"
#include"BlocksLayer.h"
#include"Player.h"
#include"HelloWorldScene.h"
#include"MyFunc.h"
#include"UILayer.h"
#include"SimpleAudioEngine.h"
#include"NativeUtils.h"
class HelloWorld;
class BlocksLayer;
class Player;
class GameLayer :public cocos2d::Layer{
public:

	virtual bool init();

	//static cocos2d::Scene* createScene();

	void InitBlocksLayer();


	
	CREATE_FUNC(GameLayer);
	 
	

	void overCallback(float dt);


	
	void effectImageCallback(float dt);
	void signImageCallback(float dt);
	void showAchivementImageCallback(float dt);
	void showLeaderboardsImageCallback(float dt);


	void shareImageCallback(float dt);
	//void shareCallback(float dt);
	void pingfenImageCallback(float dt);

	void menuMusicCallback(cocos2d::Ref* pSender);
	void removeUI();
	cocos2d::CCCamera *camera;

	
	LightEffect * getEffect_G();

	void finalGame();
	void UIOut();
	void unsch2();
private:
	void wenImageCallback(float dt);
	BlocksLayer *_blockLayer;

	Player *_player;

//	void updata1(float dt);

	void updata2(float dt);

	void updata3(float dt);
	bool isPause;

	int bg_Sign;
	bool bg_sign1;
	bool bg_sign2;
	bool bg_sign3;
	
	float _ocension;
	float sign_CH;
	
};
#endif
