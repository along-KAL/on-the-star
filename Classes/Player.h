#pragma once 
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include"cocos2d.h"
#include"GameLayer.h"
class GameLayer;
#define PLAYER_HIGT 350
//#define ZUI_GAO 400
#define VISIBLE_SIZE Director::getInstance()->getVisibleSize()
#define ZUIDAGAODU 75000
class MyJump :public cocos2d::JumpBy
{
public:
	static MyJump * create(float duration, const cocos2d::Point& position, float height, int jumps);
	void change();
	cocos2d::Point GetDelta(){ return _delta; }
protected:

private:
};
class Player :public EffectSprite{
public:
	
	virtual bool init();
	CREATE_FUNC(Player);
	static Player* sharePlayer();
	void runDownAction();
	bool runJumpAction(bool touchBegin);
	void jumpActionCallBack();
	void runRotateAction();
	void updata2(float dt);
//	void startJump();
	void getGL(GameLayer* GL);
private:
	GameLayer * _GL;
	//float X;
	bool jumpSign;
	MyJump *_jumpAction;
};
#endif