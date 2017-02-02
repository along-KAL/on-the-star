#pragma once
#ifndef _UILyaer_H_
#define _UILayer_H_
#include"cocos2d.h"
//#include"GameLayer.h"
#include"HelloWorldScene.h"
class HelloWorld;
class UIbt :public cocos2d::Layer{
public:
	static cocos2d::Scene* createScene();
	bool init();
	CREATE_FUNC(UIbt);

	void endGame();
private:
	
	void addButton();
	void beginCallback(float dt);
	void rankCallback(float dt);
	void shareCallback(float dt);
	void helpCallback(float dt);
	void musicCallback(float dt);
	void scoreAction();
};
#endif
