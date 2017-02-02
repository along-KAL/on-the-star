#include "Loading.h"  
#include "HelloWorldScene.h"
USING_NS_CC;
using namespace CocosDenshion;
bool Loading::init()
{
	
	auto sp = Sprite::create("Loadingz.png");
	this->addChild(sp);
	sp->setPosition(ccp(480,800));
	sp->setTag(333);
	count = 0;
	this->loading();

	return true;
}
Scene *Loading::createScene()
{
	Scene *scene = Scene::create();
	Loading *layer = Loading::create();
	scene->addChild(layer);
	return scene;
}
void Loading::loading()
{
	//Ԥ���ر�������
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("BGM.mp3");
//	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
	//Ԥ������Ч
	SimpleAudioEngine::sharedEngine()->preloadEffect("lastM.wav");
	//Ԥ������Ч
	SimpleAudioEngine::sharedEngine()->preloadEffect("chuxingxingM.wav");
	//Ԥ������Ч
	SimpleAudioEngine::sharedEngine()->preloadEffect("anniuM.wav");
	//Ԥ������Ч
	SimpleAudioEngine::sharedEngine()->preloadEffect("tiaoyueM.wav");
	//Ԥ������Ч
	SimpleAudioEngine::sharedEngine()->preloadEffect("over.wav");

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("zz.plist","zz.png");
	CCTextureCache::sharedTextureCache()->addImageAsync("holll.png", CC_CALLBACK_0(Loading::loadingCallback, this));
	CCTextureCache::sharedTextureCache()->addImageAsync("playerTou.png", CC_CALLBACK_0(Loading::loadingCallback, this));
	CCTextureCache::sharedTextureCache()->addImageAsync("dsd.png", CC_CALLBACK_0(Loading::loadingCallback, this));
	CCTextureCache::sharedTextureCache()->addImageAsync("aa.png", CC_CALLBACK_0(Loading::loadingCallback, this));
	CCTextureCache::sharedTextureCache()->addImageAsync("newMoon.png", CC_CALLBACK_0(Loading::loadingCallback, this));
	

	CCTextureCache::sharedTextureCache()->addImageAsync("fanle1.png", CC_CALLBACK_0(Loading::loadingCallback, this));
	CCTextureCache::sharedTextureCache()->addImageAsync("heidong1.png", CC_CALLBACK_0(Loading::loadingCallback, this));
	CCTextureCache::sharedTextureCache()->addImageAsync("huidong1.png", CC_CALLBACK_0(Loading::loadingCallback, this));
	CCTextureCache::sharedTextureCache()->addImageAsync("huidonghuizhuan1.png", CC_CALLBACK_0(Loading::loadingCallback, this));

	CCTextureCache::sharedTextureCache()->addImageAsync("huizhuan1.png", CC_CALLBACK_0(Loading::loadingCallback, this));
	CCTextureCache::sharedTextureCache()->addImageAsync("qinxie1.png", CC_CALLBACK_0(Loading::loadingCallback, this));
	CCTextureCache::sharedTextureCache()->addImageAsync("taicui1.png", CC_CALLBACK_0(Loading::loadingCallback, this));
	CCTextureCache::sharedTextureCache()->addImageAsync("yanse1.png", CC_CALLBACK_0(Loading::loadingCallback, this));
	CCTextureCache::sharedTextureCache()->addImageAsync("zhongjian1.png", CC_CALLBACK_0(Loading::loadingCallback, this));
	CCTextureCache::sharedTextureCache()->addImageAsync("guildE.png", CC_CALLBACK_0(Loading::loadingCallback, this));



	
}
void Loading::loadingCallback()
{
		count++;
		if (count == 15){
			CCScene *newscne = HelloWorld::createScene();
			CCDirector::sharedDirector()->replaceScene(newscne); //�����л�  
			this->removeChildByTag(333);
		}
		
	
}
