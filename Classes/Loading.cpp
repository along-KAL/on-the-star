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
	//Ô¤¼ÓÔØ±³¾°ÒôÀÖ
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("BGM.mp3");
//	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
	//Ô¤¼ÓÔØÒôÐ§
	SimpleAudioEngine::sharedEngine()->preloadEffect("lastM.wav");
	//Ô¤¼ÓÔØÒôÐ§
	SimpleAudioEngine::sharedEngine()->preloadEffect("chuxingxingM.wav");
	//Ô¤¼ÓÔØÒôÐ§
	SimpleAudioEngine::sharedEngine()->preloadEffect("anniuM.wav");
	//Ô¤¼ÓÔØÒôÐ§
	SimpleAudioEngine::sharedEngine()->preloadEffect("tiaoyueM.wav");
	//Ô¤¼ÓÔØÒôÐ§
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
			CCDirector::sharedDirector()->replaceScene(newscne); //³¡¾°ÇÐ»»  
			this->removeChildByTag(333);
		}
		
	
}
