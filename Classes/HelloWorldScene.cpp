#include "HelloWorldScene.h"
#include "MyFunc.h"

USING_NS_CC;
namespace mf = MyFunc;


Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}



bool HelloWorld::init()
{
	INIT_RANDOM_ENGINE;

    if ( !Layer::init() )
    {
        return false;
    }
	//背景摄影机
	cocos2d::CCCamera * camera = Camera::createOrthographic(VISIBLE_SIZE.width, VISIBLE_SIZE.height, 0, 1);
	camera->setCameraFlag(CameraFlag::USER2);
	this->addChild(camera);
	

	/*if (CCUserDefault::sharedUserDefault()->getIntegerForKey("Score", 0) > 5)
		sign = mf::rn(1, (CCUserDefault::sharedUserDefault()->getIntegerForKey("Score", 0)+1)/2) ;
	else
		sign = mf::rn(1, CCUserDefault::sharedUserDefault()->getIntegerForKey("Score", 0));
	switch (sign){
	case 1: 
		 BG1 = Sprite::create("backG.png"); 
		 BG1->setAnchorPoint(ccp(0, 0));
		 BG1->setPosition(ccp(0, 0));
		 this->addChild(BG1);
		 BG1->setCameraMask(4);
		break;	
	case 2: 
		 BG2 = Sprite::create("backG.png");
		 BG2->setAnchorPoint(ccp(0, 0));
		 BG2->setPosition(ccp(0, 0));
		 this->addChild(BG2);
		 BG2->setCameraMask(4);
		 break;
	case 3: 
		 BG3 = Sprite::create("backG.png");
		 BG3->setAnchorPoint(ccp(0, 0));
		 BG3->setPosition(ccp(0, 0));
		 this->addChild(BG3);
		 BG3->setCameraMask(4);
			break;
	case 4:
		BG4 = Sprite::create("backG.png");
		BG4->setAnchorPoint(ccp(0, 0));
		BG4->setPosition(ccp(0, 0));
		this->addChild(BG4);
		BG4->setCameraMask(4);
		break;

	case 5:
		BG5 = Sprite::create("backG.png");
		BG5->setAnchorPoint(ccp(0, 0));
		BG5->setPosition(ccp(0, 0));
		this->addChild(BG5);
		BG5->setCameraMask(4);
		break;
	default:break;
	}*/
	//1.设置背景颜色
	
/*auto s = Sprite::create("bian.png");
	s->setAnchorPoint(ccp(0,0));
	s->setPosition(0,0);
	this->addChild(s);*/
	//sp->runAction(waves3D);
   // Size visibleSize = Director::getInstance()->getVisibleSize();
   // Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//1.设置背景颜色
	//auto layer = CCLayerColor::create(ccc4(51, 204, 204, 0xff));
	//this->addChild(layer);
	//加入UILAyer
	_gameLayer = GameLayer::create();
	_gameLayer->setPosition(ccp(0, 0));
	this->addChild(_gameLayer);
	/*auto gridNodeTarget = NodeGrid::create();
	addChild(gridNodeTarget);
	Sprite *sp = Sprite::create("player.png");
	sp->setPosition(ccp(300, 700));
	//this->addChild(sp);
	gridNodeTarget->addChild(sp);
	gridNodeTarget->runAction(CCSplitCols::create(5, 50));*/
	
	//BG1->setEffect(_gameLayer->getEffect_G(), "backG3_n.png");

	//BG1->setEffect(_gameLayer->getEffect_G2(), "backG1_n.png");
	//读取粒子效果
	//ParticleSystem* m_emitter1 = ParticleSystemQuad::create("1backGroundPart.plist");
	//m_emitter1->retain();
	//ParticleBatchNode *batch = ParticleBatchNode::createWithTexture(m_emitter1->getTexture());
	//batch->addChild(m_emitter1);
	//addChild(batch, 10);
	//m_emitter1->release();






    return true;
}







