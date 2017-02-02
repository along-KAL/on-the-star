#include"BlocksLayer.h"
#include "MyFunc.h"
#include "boxBody/GB2ShapeCache-x.h"
USING_NS_CC;
namespace mf = MyFunc;
using namespace CocosDenshion;
int sign_ZA[9] = { 1, 2, 3, 4 ,5 , 6, 7, 8, 9 };
//int sign_XA[4] = { 5, 6, 7, 8 };
bool BlocksLayer::init(){
	INIT_RANDOM_ENGINE;
	effect = CCUserDefault::sharedUserDefault()->getBoolForKey("effect", true);
	Size size = Director::getInstance()->getVisibleSize();
	width = size.width;
	height = size.height;
	srand((unsigned)time(NULL));
	//创建world-50
	b2Vec2 grivaty;
	grivaty.Set(0.0f, -90);
	world = new b2World(grivaty);
	m_debugDraw = new GLESDebugDraw(PTM_RATIO);
	world->SetDebugDraw(m_debugDraw);
	m_debugDraw->SetFlags(b2Draw::e_shapeBit);
	//允许静止的物体进入休眠
	world->SetAllowSleeping(true);



	_effect = LightEffect::create();
	//_effect->retain();
	_effect->setAmbientLightColor(cocos2d::Color3B(0, 0, 0));
	_effect->setLightCutoffRadius(500);
	_effect->setLightColor(cocos2d::Color3B(0, 0, 0));
	_effect->setLightHalfRadius(0.8f);
	_effect->setBrightness(1.8);

	//EffectSprite* head_ZJ = EffectSprite::create("head.png");
	//this->addChild(head_ZJ,20);

	//EffectSprite* body_ZJ = EffectSprite::create("body.png");
	//this->addChild(body_ZJ, 19);
	CCSprite *hand1_ZJ = CCSprite::createWithSpriteFrameName("hand1.png");
	//EffectSprite* hand1_ZJ = EffectSprite::create("hand1.png");
	this->addChild(hand1_ZJ,18);

	//EffectSprite* hand2_ZJ = EffectSprite::create("hand2.png");
	//this->addChild(hand2_ZJ, 17);
	CCSprite *hand3_ZJ = CCSprite::createWithSpriteFrameName("hand1.png");
//	EffectSprite* hand3_ZJ = EffectSprite::create("hand1.png");
	this->addChild(hand3_ZJ, 18);

	//EffectSprite* hand4_ZJ = EffectSprite::create("hand2.png");
	//this->addChild(hand4_ZJ,17);
//	head_ZJ->setEffect(_effect, "dsd_n.png");
//	body_ZJ->setEffect(_effect, "dsd_n.png");
//	hand1_ZJ->setEffect(_effect, "dsd_n.png");
	//hand2_ZJ->setEffect(_effect, "dsd_n.png");
//	hand3_ZJ->setEffect(_effect, "dsd_n.png");
	//hand4_ZJ->setEffect(_effect, "dsd_n.png");
	this->addChild(Player::sharePlayer(),17);
	//Player::sharePlayer()->setEffect(_effect, "dsd_n.png");
	//auto leg_ZJ = Sprite::create("leg.png");
	//this->addChild(leg_ZJ, 17);
	/* shengTi = NULL;
	{
	b2BodyDef bd;
	bd.type = b2_dynamicBody;
	bd.position.Set(480 / PTM_RATIO, 350 / PTM_RATIO);
	b2PolygonShape shape;
	shape.SetAsBox(1.7f, 1.0f);
	b2FixtureDef fd;
	fd.friction = 0.1;
	fd.density = 0.0001f;
	fd.restitution = 0;
	fd.filter.maskBits = 0x0008;
	fd.shape = &shape;
	shengTi = world->CreateBody(&bd);
	shengTi->SetUserData(body_ZJ);
	shengTi->CreateFixture(&fd);
	shengTi->SetFixedRotation(true);
	//	shengTi->SetMassData(&ms);
	}
	// Define motorized body

	b2BodyDef bd;
	bd.type = b2_dynamicBody;
	bd.position.Set(480 / PTM_RATIO, 400 / PTM_RATIO);
	b2PolygonShape shape;
	shape.SetAsBox(20 / PTM_RATIO, 5 / PTM_RATIO);
	b2FixtureDef fd;
	fd.filter.maskBits = 0x0004;
	fd.shape = &shape;
	fd.friction = 0.1f;
	fd.density = 0.0001f;
	fd.restitution = 0;
	//head
	head = world->CreateBody(&bd);
	head->CreateFixture(&fd);
	b2MotorJointDef mjd;
	head->SetUserData(head_ZJ);
	mjd.Initialize(shengTi, head);
	mjd.maxForce = 300.0f;
	mjd.maxTorque = 300.0f;
	world->CreateJoint(&mjd);
	*/
	//hand1
	//bd.position.Set(250 / PTM_RATIO, 350 / PTM_RATIO);
	{
		//leg

		b2BodyDef bodyDef_P;
		b2FixtureDef fixDef_P;
		b2PolygonShape shape_P;
		fixDef_P.filter.maskBits = 0x0002;
		fixDef_P.friction = 0.1f;
		fixDef_P.density = 0.001f;
		fixDef_P.restitution = 0;
		shape_P.SetAsBox(20 / PTM_RATIO, 5 / PTM_RATIO);
		fixDef_P.shape = &shape_P;
		Player::sharePlayer()->setAnchorPoint(ccp(0.5, 0.15));
		bodyDef_P.userData = Player::sharePlayer();
		bodyDef_P.type = b2_dynamicBody;
		body_P = world->CreateBody(&bodyDef_P);
		body_P->SetTransform(b2Vec2(480 / PTM_RATIO, 300 / PTM_RATIO), 0);
		//fixture
		body_P->SetFixedRotation(true);

		//	fixDef_P.density = 1;
		//	fixDef_P.friction = 1;
		//	fixDef_P.restitution = 0;
		body_P->CreateFixture(&fixDef_P);
		//body_P->SetAwake(false);


		//b2MotorJointDef  rd;
		//	rd.frequencyHz = 10;
		//	rd.dampingRatio = 100;
		//rd.length = 1;


		//rd.bodyA = body_P;
		//rd.bodyB = shengTi;
		//rd.Initialize(body_P, shengTi);
		//rd.maxForce = 100.0f;
		//rd.maxTorque = 100.0f;
		//	rd.localAnchorA.Set(0.5, 1);
		//	rd.localAnchorB.Set(0.5, -2);
		//rd.enableLimit = true;
		//	rd.lowerAngle = 0;
		//	rd.upperAngle = 0;
		//rd.collideConnected = false;
		//world->CreateJoint(&rd);

		//body_P->SetLinearVelocity(b2Vec2(0, 130));
	}
	{
		b2BodyDef bd;
		bd.type = b2_dynamicBody;
		bd.position.Set(480 / PTM_RATIO, 400 / PTM_RATIO);

	b2FixtureDef fd;
	fd.filter.maskBits = 0x0004;
	//fd.shape = &shape;
	fd.friction = 0.1f;
	fd.density = 0.0001f;
	fd.restitution = 0;






		 hand1 = world->CreateBody(&bd);
		b2PolygonShape shape1;
		shape1.SetAsBox(0.1f, 0.3f);
		fd.shape = &shape1;
		fd.filter.maskBits = 0x0004;
		hand1->CreateFixture(&fd);
		hand1->SetUserData(hand1_ZJ);
		hand1->SetTransform(b2Vec2(455 / PTM_RATIO, 350 / PTM_RATIO), 0);
		b2RevoluteJointDef jd;
		jd.bodyA = hand1;
		jd.bodyB = body_P;
		jd.localAnchorA.Set(0, 0.3);
		jd.localAnchorB.Set(-1.7, 3.2);
		jd.enableLimit = true;
		jd.lowerAngle = 0;
		jd.upperAngle = 2.14;
		jd.collideConnected = false;
		world->CreateJoint(&jd);
		//hand2
		//bd.position.Set(250 / PTM_RATIO, 350 / PTM_RATIO);
	/*	 hand2 = world->CreateBody(&bd);
		b2PolygonShape shape2;
		shape2.SetAsBox(0.1f, 0.3f);
		fd.shape = &shape2;
		fd.filter.maskBits = 0x0004;
		hand2->CreateFixture(&fd);
		hand2->SetUserData(hand2_ZJ);
		hand2->SetTransform(b2Vec2(455 / PTM_RATIO, 350 / PTM_RATIO), 0);
		jd.bodyA = hand1;
		jd.bodyB = hand2;
		jd.localAnchorA.Set(0, 0);
		jd.localAnchorB.Set(0, 0.6);
		jd.enableLimit = true;
		jd.lowerAngle = 0;
		jd.upperAngle = 0;
		jd.collideConnected = false;
		world->CreateJoint(&jd);
		*/
		//hand3
		//bd.position.Set(250 / PTM_RATIO, 350 / PTM_RATIO);
		 hand3 = world->CreateBody(&bd);
		b2PolygonShape shape3;
		shape3.SetAsBox(0.1f, 0.3f);
		fd.shape = &shape3;
		fd.filter.maskBits = 0x0004;
		hand3->CreateFixture(&fd);
		hand3->SetUserData(hand3_ZJ);
		hand3->SetTransform(b2Vec2(530 / PTM_RATIO, 350 / PTM_RATIO), 0);
		jd.bodyA = hand3;
		jd.bodyB = body_P;
		jd.localAnchorA.Set(0, 0.3);
		jd.localAnchorB.Set(1.5, 3.2);
		jd.enableLimit = true;
		jd.lowerAngle = -2.14;
		jd.upperAngle = 0;
		jd.collideConnected = false;
		world->CreateJoint(&jd);
		
		//hand4
		//bd.position.Set(250 / PTM_RATIO, 350 / PTM_RATIO);
	/*	 hand4 = world->CreateBody(&bd);
		b2PolygonShape shape4;
		shape4.SetAsBox(0.1f, 0.3f);
		fd.shape = &shape4;
		fd.filter.maskBits = 0x0004;
		hand4->CreateFixture(&fd);
		hand4->SetUserData(hand4_ZJ);
		hand4->SetTransform(b2Vec2(530 / PTM_RATIO, 350 / PTM_RATIO), 0);
		jd.bodyA = hand3;
		jd.bodyB = hand4;
		jd.localAnchorA.Set(0, 0);
		jd.localAnchorB.Set(0, 0.6);
		jd.enableLimit = true;
		jd.lowerAngle = -0;
		jd.upperAngle = 0;
		jd.collideConnected = false;
		world->CreateJoint(&jd);
		*/
	



	

	}


	

	CCTexture2D *texture_BG1 ;
	CCTexture2D *texture_BG2 ;
	EffectSprite *  BGFirst;

	int sign = 0 + (rand()) % 2;

	if (sign == 0 ){
		texture_BG1 = CCTextureCache::sharedTextureCache()->textureForKey("dsd.png");
		texture_BG2 = CCTextureCache::sharedTextureCache()->textureForKey("dsd.png");
		BGFirst = EffectSprite::create("dsd.png");
	}
	else if (sign == 1){
		texture_BG1 = CCTextureCache::sharedTextureCache()->textureForKey("aa.png");
		texture_BG2 = CCTextureCache::sharedTextureCache()->textureForKey("aa.png");
		BGFirst = EffectSprite::create("aa.png");
	}
	

	//实例化精灵  
	CCSprite *BG1 = CCSprite::createWithTexture(texture_BG1);
//	EffectSprite *  BG1 = EffectSprite::create("dsd.png");
	BG1->setAnchorPoint(ccp(0, 0));
	BG1->setPosition(ccp(0, 0));
	BG1->setTag(901);
	this->addChild(BG1);
	//BG1->setEffect(_effect, "dsd_n.png");


	CCSprite *BG2 = CCSprite::createWithTexture(texture_BG2);
	BG2->setAnchorPoint(ccp(0, 0));
	BG2->setPosition(ccp(0, 1930));
	BG2->setTag(902);
	this->addChild(BG2);
	//BG2->setEffect(_effect, "dsd_n.png");
	
	BGFirst->setAnchorPoint(ccp(0, 0));
	BGFirst->setPosition(ccp(0, 0));
	BGFirst->setTag(903);
	this->addChild(BGFirst);
	BGFirst->setEffect(_effect, "dsd_n.png");


	cut = CCUserDefault::sharedUserDefault()->getIntegerForKey("Score", 0);
	/*	float a[10];
		float b[10];
		for (int i = 0; i < cut; i++){
		while (true){
		float x = 100 + (rand()) % ((int)(VISIBLE_SIZE.width - 150));// mf::rn(100, VISIBLE_SIZE.width - 60);
		float y = 100 + (rand()) % ((int)(VISIBLE_SIZE.height*0.5 - 60));// mf::rn(100, VISIBLE_SIZE.height*0.5 - 60);
		if (x>380 && x<580 && y>(VISIBLE_SIZE.height*0.3 - 100) && y<(VISIBLE_SIZE.height*0.3 + 100))
		{//x*y>((480 - 110)*(VISIBLE_SIZE.height*0.2 - 110)) && x*y < ((480 + 110)*(VISIBLE_SIZE.height*0.2 + 110))
		continue;
		}
		else{
		if (i == 0){
		a[0] = x;
		b[0] = y;
		break;
		}
		else{
		bool sign ;
		for (int j = 0; j < i; j++){
		if (x>(a[j] - 100) && x<(a[j] + 100) && y>(b[j] - 100) && y<(b[j] + 100)){
		//x*y > ((a[j] - 100)*(b[j] - 100)) && x*y < ((a[j] + 100)*(b[j] + 100))
		sign = false;
		break;
		}
		else{
		if (j+1 == i){
		a[i] = x;
		b[i] = y;
		sign = true;
		}
		}

		}
		if (sign == true){  break; }
		else{  continue; }

		}
		}


		}
		}

		*/
	int _jointCut[2];
	for (int i = 1; i <= cut; i++)
	{
		/*	auto Sp = Sprite::create(_filesNames[i]);
			this->addChild(Sp);
			Sp->setPosition(ccp(0,0));
			Sp->setScale(mf::rn(7, 15) / 10);
			//Sp->setColor(_colors[i]);
			Sp->setTag(1021+i);
			ccBezierConfig bezer;
			bezer.controlPoint_1 = ccp(100, 300);//bezer.controlPoint_1 = ccp(480, 0.4*VISIBLE_SIZE.height);
			bezer.controlPoint_2 = ccp(200, 600);//bezer.controlPoint_2 = ccp(480, 0.1*VISIBLE_SIZE.height);
			bezer.endPosition = ccp(a[i], b[i]);
			CCActionInterval *bezier = BezierTo::create(1.5, bezer);
			//auto GUIWEI = MoveTo::create(1.5,ccp(visibleSize.width*0.5,visibleSize.height*0.3));
			auto GUIWEIEaseOut = CCEaseExponentialOut::create(bezier);
			Sp->runAction(GUIWEIEaseOut);*/
		int X = 0;
		if (i == 1)X = 436;
		else if (i == 2)X = 523;
		else if (i == 3)X = 349;
		else if (i == 4)X = 610;
		else if (i == 5)X = 262;
		else if (i == 6)X = 697;
		else if (i == 7)X = 175;
		else if (i == 8)X = 784;
		else if (i == 9)X = 88;
		else if (i == 10)X = 871;
		int X2;
		//使星星不重叠
		if (i == 1){ X2 = mf::rn(3, 6); _jointCut[0] = X2; }
		else if (i == 2){
			while (true){ X2 = mf::rn(3, 6);  if (abs(X2 - _jointCut[0]) > 1){ _jointCut[1] = X2; break; } }
		}
		else{ while (true){ X2 = mf::rn(3, 6);   if (abs(X2 - _jointCut[0]) > 1){ _jointCut[0] = _jointCut[1]; _jointCut[1] = X2; break; } } }

		//地板
		b2BodyDef bodyDef1;
		bodyDef1.type = b2_staticBody; //物体的类型，不动的，坚硬的~ 可以把这样的物体当成地面  
		b2PolygonShape borderShape1; // 一个方形的形状  
		b2FixtureDef borderFixture1; // 一个定制器  
		borderFixture1.filter.maskBits = 0x0001;
		//定义地板  
		bodyDef1.position.Set(X / PTM_RATIO, (height + 10) / PTM_RATIO); // 地板在0，0位置  
		borderShape1.SetAsBox(30 / PTM_RATIO, 5 / PTM_RATIO); //设置长度和高度，这里描述的地板就像是X轴，是一条线  
		borderFixture1.shape = &borderShape1;
		borderFixture1.friction = 0.1;
		b2Body* ground = world->CreateBody(&bodyDef1); //在世界中创建一个物体（地面）  

		//	ground->SetMassData(&mass2);
		ground->CreateFixture(&borderFixture1);          //定制地面的形状  


		{
			b2PolygonShape shape;
			shape.SetAsBox(2 / PTM_RATIO, 50 / PTM_RATIO);

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 0.1f;
			fd.friction = 0.2f;
			fd.filter.maskBits = 0x0001;
			b2RevoluteJointDef jd;
			jd.enableLimit = true;

			jd.collideConnected = false;

			//	const float y = 1000/PTM_RATIO;
			b2Body* prevBody = ground;
			for (int i = 0; i < X2; ++i)
			{
				b2BodyDef bd;
				bd.angularDamping = 5;
				bd.type = b2_dynamicBody;
				bd.position.Set(X / PTM_RATIO, (height - i * 100) / PTM_RATIO);
				b2Body* body = world->CreateBody(&bd);

				body->CreateFixture(&fd);

				b2Vec2 anchor(X / PTM_RATIO, (height - i * 100) / PTM_RATIO);
				jd.Initialize(prevBody, body, anchor);
				world->CreateJoint(&jd);
				//CCSprite *sp = CCSprite::createWithSpriteFrameName("xian1.png");
				auto sp = Sprite::create("xian1.png", CCRectMake(0, 0, 8, 110));
				this->addChild(sp);
				body->SetUserData(sp);
				prevBody = body;
				if (!effect){ prevBody->SetActive(false); }
			
			}
			prevBody->ApplyForce(b2Vec2(-5, 0), prevBody->GetWorldCenter(), true);
			xings.push_back(prevBody);
			auto sp = EffectSprite::create("XINGXING10.png");
			sp->setAnchorPoint(ccp(0.5,0.2));
			sp->setPosition(480, 748);
			this->addChild(sp);
			sp->setScale(mf::rn(7, 15) / 10);
			prevBody->SetUserData(sp);
			sp->setEffect(_effect, "XINGXING4_n.png");
			/*	b2PolygonShape shape2;
				shape2.SetAsBox(2 / PTM_RATIO, 50 / PTM_RATIO);
				b2FixtureDef fd2;
				fd2.shape = &shape2;
				fd2.density = 0.1f;
				fd2.friction = 0.0f;
				fd2.filter.maskBits = 0x0001;
				b2WeldJointDef jd2;
				jd2.collideConnected = false;
				b2BodyDef bd2;
				bd2.type = b2_dynamicBody;
				bd2.position.Set(X / PTM_RATIO, (1200 - 26 * 25) / PTM_RATIO);
				body2 = world->CreateBody(&bd2);
				body2->CreateFixture(&fd2);

				b2Vec2 anchor2(X / PTM_RATIO, (1200 - 26 * 25) / PTM_RATIO);
				jd.Initialize(prevBody, body2, anchor2);
				world->CreateJoint(&jd);

				jd2.Initialize(body2, body_P,
				body_P->GetWorldCenter());
				world->CreateJoint(&jd2);*/

			
		}

		/*	//挡板
		b2BodyDef bodyDef3;
		//bodyDef1.type = b2_dynamicBody; //物体的类型，不动的，坚硬的~ 可以把这样的物体当成地面  
		b2PolygonShape borderShape3; // 一个方形的形状  
		b2FixtureDef borderFixture3; // 一个定制器  

		//定义地板  
		bodyDef3.position.Set((X - 15) / PTM_RATIO, VISIBLE_SIZE.height / PTM_RATIO); // 地板在0，0位置  
		borderShape3.SetAsBox(10 / PTM_RATIO, 10 / PTM_RATIO); //设置长度和高度，这里描述的地板就像是X轴，是一条线  
		borderFixture3.shape = &borderShape3;
		b2Body * ground3 = world->CreateBody(&bodyDef3); //在世界中创建一个物体（地面）  
		ground3->CreateFixture(&borderFixture3);          //定制地面的形状  

		//挡板
		b2BodyDef bodyDef4;
		//bodyDef1.type = b2_dynamicBody; //物体的类型，不动的，坚硬的~ 可以把这样的物体当成地面  
		b2PolygonShape borderShape4; // 一个方形的形状  
		b2FixtureDef borderFixture4; // 一个定制器  

		//定义地板  
		bodyDef4.position.Set((X + 15) / PTM_RATIO, VISIBLE_SIZE.height / PTM_RATIO); // 地板在0，0位置  
		borderShape4.SetAsBox(10 / PTM_RATIO, 10 / PTM_RATIO); //设置长度和高度，这里描述的地板就像是X轴，是一条线  
		borderFixture4.shape = &borderShape4;
		b2Body * ground4 = world->CreateBody(&bodyDef4); //在世界中创建一个物体（地面）  
		ground4->CreateFixture(&borderFixture4);*/
	
	}

	//地板
	b2BodyDef bodyDef1;
	bodyDef1.type = b2_staticBody; //物体的类型，不动的，坚硬的~ 可以把这样的物体当成地面  
	b2PolygonShape borderShape1; // 一个方形的形状  
	b2FixtureDef borderFixture1; // 一个定制器  
	borderFixture1.filter.maskBits = 0x0001;
	//定义地板  
	bodyDef1.position.Set(480 / PTM_RATIO, (height + 10) / PTM_RATIO); // 地板在0，0位置  
	borderShape1.SetAsBox(30 / PTM_RATIO, 5 / PTM_RATIO); //设置长度和高度，这里描述的地板就像是X轴，是一条线  
	borderFixture1.shape = &borderShape1;
	borderFixture1.friction = 0.1;
	b2Body* ground = world->CreateBody(&bodyDef1); //在世界中创建一个物体（地面）  

	//	ground->SetMassData(&mass2);
	ground->CreateFixture(&borderFixture1);          //定制地面的形状  


	{
		b2PolygonShape shape;
		shape.SetAsBox(2 / PTM_RATIO, height*(50.0 / 1440) / PTM_RATIO);

		b2FixtureDef fd;
		fd.shape = &shape;
		fd.density = 0.1f;
		fd.friction = 0.2f;
		fd.filter.maskBits = 0x0001;
		b2RevoluteJointDef jd;
		jd.enableLimit = true;

		jd.collideConnected = false;

		//	const float y = 1000/PTM_RATIO;
		b2Body* prevBody = ground;
		for (int i = 0; i < 8; ++i)
		{
			b2BodyDef bd;
			//bd.angularDamping = 10;
			bd.type = b2_dynamicBody;
			bd.position.Set(480 / PTM_RATIO, (height - i * 100) / PTM_RATIO);
			b2Body* body = world->CreateBody(&bd);

			body->CreateFixture(&fd);

			b2Vec2 anchor(480 / PTM_RATIO, (height - i * 100) / PTM_RATIO);
			jd.Initialize(prevBody, body, anchor);
			world->CreateJoint(&jd);
			//CCSprite *sp = CCSprite::createWithSpriteFrameName("xian1.png");
			auto sp = Sprite::create("xian1.png", CCRectMake(0, 0, 8, 110));
			this->addChild(sp);
			body->SetUserData(sp);
			prevBody = body;
			if (!effect){ prevBody->SetActive(false); }

		}
		CCSprite *sp_dengpao = CCSprite::createWithSpriteFrameName("dengpao1.png");
	//	CCTexture2D *texture_sp_dengpao = CCTextureCache::sharedTextureCache()->textureForKey("dengpao1.png");
		//实例化精灵  
		//CCSprite *sp_dengpao = CCSprite::createWithTexture(texture_sp_dengpao);
	///	auto sp_dengpao = EffectSprite::create("dengpao1.png");
		//sp_dengpao->setAnchorPoint(ccp(0.5, 0.457));
		sp_dengpao->setTag(2001);
		//sp_dengpao->setPosition(480, (VISIBLE_SIZE.height  - 16 * 50));
	//	sp_dengpao->setOpacity(0);
		this->addChild(sp_dengpao,7);
		//多边形
		GB2ShapeCache::sharedGB2ShapeCache()->addShapesWithFile("dss1.plist");
		b2BodyDef Def;
		Def.type = b2_dynamicBody;
		//	Def.gravityScale = 0.1;
		Def.angularDamping = 5;
		Def.position.Set(480 / PTM_RATIO, (height - 14 * 58) / PTM_RATIO);
		Def.userData = sp_dengpao;
		b2Body *bodyfsd = world->CreateBody(&Def);
		GB2ShapeCache *sc = GB2ShapeCache::sharedGB2ShapeCache();
		sc->addFixturesToBody(bodyfsd, "dengpao");
		b2WeldJointDef wjd;
		b2Vec2 anchor(480 / PTM_RATIO, (height - 15 * 58) / PTM_RATIO);
		wjd.Initialize(bodyfsd, prevBody, anchor);
		world->CreateJoint(&wjd);
		dengpaoMove = bodyfsd;
		if (!effect){ dengpaoMove->SetActive(false); }
		dengpaoMove->ApplyForce(b2Vec2(100, 0), dengpaoMove->GetWorldCenter(), true);


	//	CCActionInterval * fadeIn = CCFadeIn::create(4);
	//	sp_dengpao->runAction(fadeIn);
		//
		//气球
		CCSprite *qiqiu = CCSprite::createWithSpriteFrameName("qiqiu.png");
		qiqiu->setPosition(200,120);
		qiqiu->setAnchorPoint(ccp(0.5,0));
		this->addChild(qiqiu, 100);
		qiqiu->setTag(551);
		qiqiu->setRotation(-5);
		auto rota = RotateBy::create(5, 10);
		qiqiu->runAction(RepeatForever::create(Sequence::create(rota, rota->reverse(), nullptr)));
		/*	//气球
		{
			//地板
			b2BodyDef bodyDef1_qiqiu;
			bodyDef1_qiqiu.type = b2_staticBody; //物体的类型，不动的，坚硬的~ 可以把这样的物体当成地面  
			b2PolygonShape borderShape1_qiqiu; // 一个方形的形状  
			b2FixtureDef borderFixture1_qiqiu; // 一个定制器  
			borderFixture1_qiqiu.filter.maskBits = 0x0001;
			//定义地板  
			bodyDef1_qiqiu.position.Set(180 / PTM_RATIO, 150 / PTM_RATIO); // 地板在0，0位置  
			borderShape1_qiqiu.SetAsBox(30 / PTM_RATIO, 5 / PTM_RATIO); //设置长度和高度，这里描述的地板就像是X轴，是一条线  
			borderFixture1_qiqiu.shape = &borderShape1_qiqiu;
			borderFixture1_qiqiu.friction = 0.1;
			b2Body* ground_qiqiu = world->CreateBody(&bodyDef1_qiqiu); //在世界中创建一个物体（地面）  

			//	ground->SetMassData(&mass2);
			ground_qiqiu->CreateFixture(&borderFixture1_qiqiu);          //定制地面的形状  


			{
				b2PolygonShape shape_qiqiu;
				shape_qiqiu.SetAsBox(2 / PTM_RATIO, VISIBLE_SIZE.height*(20.0 / 1440) / PTM_RATIO);

				b2FixtureDef fd_qiqiu;
				fd_qiqiu.shape = &shape_qiqiu;
				fd_qiqiu.density = 0.1f;
				fd_qiqiu.friction = 0.2f;
				fd_qiqiu.filter.maskBits = 0x0001;
				b2RevoluteJointDef jd_qiqiu;
				jd_qiqiu.enableLimit = true;

				jd_qiqiu.collideConnected = false;

				//	const float y = 1000/PTM_RATIO;
				b2Body* prevBody_qiqiu = ground_qiqiu;
				for (int i = 0; i < 4; ++i)
				{
					b2BodyDef bd_qiqiu;
					//bd.angularDamping = 10;
					bd_qiqiu.type = b2_dynamicBody;
					bd_qiqiu.position.Set(180 / PTM_RATIO, (150 + i * 50) / PTM_RATIO);
					b2Body* body_qiqiu = world->CreateBody(&bd_qiqiu);

					body_qiqiu->CreateFixture(&fd_qiqiu);

					b2Vec2 anchor(180 / PTM_RATIO, (150 + i * 50) / PTM_RATIO);
					jd_qiqiu.Initialize(prevBody_qiqiu, body_qiqiu, anchor);
					world->CreateJoint(&jd_qiqiu);
					//CCSprite *sp = CCSprite::createWithSpriteFrameName("xian1.png");
					auto sp_qiqiu = Sprite::create("xian1.png", CCRectMake(0, 0, 8, 50));
					this->addChild(sp_qiqiu);
					body_qiqiu->SetUserData(sp_qiqiu);
					prevBody_qiqiu->SetGravityScale(-0.01);
					prevBody_qiqiu = body_qiqiu;


				}

				CCSprite *sp_qiu = CCSprite::createWithSpriteFrameName("dengpao1.png");
				this->addChild(sp_qiu); 
				prevBody_qiqiu->SetUserData(sp_qiu);
				
				prevBody_qiqiu->ApplyForce(b2Vec2(50, 0), prevBody_qiqiu->GetWorldCenter(), true);
		

	}

		}*/
		
		//fireFly
		CCSprite *_fireFly1 = CCSprite::createWithSpriteFrameName("fireFly1.png");
		//auto _fireFly1 = Sprite::create("fireFly1.png");
		_fireFly1->setTag(3001);
		//	_fireFly1->setPosition(105,250);
		this->addChild(_fireFly1);

		CCSprite *_fireFly2 = CCSprite::createWithSpriteFrameName("fireFly1.png");
		//auto _fireFly2 = Sprite::create("fireFly1.png");
		_fireFly2->setTag(3002);
		//		_fireFly2->setPosition(105, 250);
		this->addChild(_fireFly2);

		CCSprite *_fireFly3 = CCSprite::createWithSpriteFrameName("fireFly1.png");
		//auto _fireFly3 = Sprite::create("fireFly1.png");
		_fireFly3->setTag(3003);
		//_fireFly3->setPosition(105, 250);
		this->addChild(_fireFly3);

		b2BodyDef bd_fire;
		//bd.angularDamping = 10;
		b2FixtureDef fireFD;
		b2CircleShape circle;
		fireFD.shape = &circle;
		bd_fire.angularDamping = 10;
		bd_fire.gravityScale = 0;
		circle.m_radius = 0.3;
		fireFD.density = 0.05f;
		fireFD.friction = 0.2f;
		bd_fire.type = b2_dynamicBody;
		bd_fire.position.Set(480 / PTM_RATIO, height*(700.0 / 1440) / PTM_RATIO);

		body_fire1 = world->CreateBody(&bd_fire);
		body_fire1->SetUserData(_fireFly1);
		body_fire1->CreateFixture(&fireFD);

		body_fire2 = world->CreateBody(&bd_fire);
		body_fire2->SetUserData(_fireFly2);
		body_fire2->CreateFixture(&fireFD);

		body_fire3 = world->CreateBody(&bd_fire);
		body_fire3->SetUserData(_fireFly3);
		body_fire3->CreateFixture(&fireFD);
	
		//fireLight
		CCSprite *fireLight1 = CCSprite::createWithSpriteFrameName("fireLight1.png");
		//auto fireLight1 = Sprite::create("fireLight1.png");
		fireLight1->setTag(3004);
		fireLight1->setOpacity(0);
		fireLight1->setPosition(20, 0);
		_fireFly1->addChild(fireLight1);

		CCSprite *fireLight2 = CCSprite::createWithSpriteFrameName("fireLight1.png");
		//auto fireLight2 = Sprite::create("fireLight1.png");
		fireLight2->setTag(3005);
		fireLight2->setOpacity(0);
		fireLight2->setPosition(20, 0);
		_fireFly2->addChild(fireLight2);

		CCSprite *fireLight3 = CCSprite::createWithSpriteFrameName("fireLight1.png");
		//auto fireLight3 = Sprite::create("fireLight1.png");
		fireLight3->setTag(3006);
		fireLight3->setOpacity(0);
		fireLight3->setPosition(20, 0);
		_fireFly3->addChild(fireLight3);

		//fireLight Action

		fireLight1->runAction(CCRepeatForever::create(Sequence::create(CCFadeIn::create(2), CCFadeOut::create(2), nullptr)));

		fireLight2->runAction(CCRepeatForever::create(Sequence::create(CCFadeIn::create(2), CCFadeOut::create(2), nullptr)));

		fireLight3->runAction(CCRepeatForever::create(Sequence::create(CCFadeIn::create(2), CCFadeOut::create(2), nullptr)));


		/*	ccBezierConfig bezer_J1;
			bezer_J1.controlPoint_1 = ccp(150, 150);//100 + (rand()) % 200
			bezer_J1.controlPoint_2 = ccp(0, 200);
			bezer_J1.endPosition = ccp(45 , 80 );
			CCActionInterval *bezier_J1 = BezierTo::create(2, bezer_J1);
			auto fireAseOut1 = CCEaseExponentialOut::create(bezier_J1);

			ccBezierConfig bezer_J2;
			bezer_J2.controlPoint_1 = ccp(70, 200);//100 + (rand()) % 200
			bezer_J2.controlPoint_2 = ccp(250, 200);
			bezer_J2.endPosition = ccp(100, 100);
			CCActionInterval *bezier_J2 = BezierTo::create(2, bezer_J2);
			auto fireAseOut2 = CCEaseExponentialOut::create(bezier_J2);

			ccBezierConfig bezer_J3;
			bezer_J3.controlPoint_1 = ccp(150, 150);//100 + (rand()) % 200
			bezer_J3.controlPoint_2 = ccp(150, 100);
			bezer_J3.endPosition = ccp(150, 150);
			CCActionInterval *bezier_J3 = BezierTo::create(1, bezer_J3);
			auto fireAseOut3 = CCEaseExponentialOut::create(bezier_J3);

			_fireFly1->runAction(fireAseOut1);
			_fireFly2->runAction(fireAseOut2);

			auto call4 = CallFunc::create([this, sp_dengpao](){
			
			this->schedule(schedule_selector(BlocksLayer::Bupdata9));

			});

			_fireFly3->runAction(Sequence::create(fireAseOut3, call4, nullptr));*/
		//
	//	sp_dengpao->setEffect(_effect, "colorDot@2x_n_n.png");
	}
	if (!effect){ body_fire1->SetActive(false); body_fire2->SetActive(false); body_fire3->SetActive(false); }
	else
	{
		
		this->schedule(schedule_selector(BlocksLayer::Bupdata3));
		this->schedule(schedule_selector(BlocksLayer::Bupdata9), 0.5);
		this->schedule(schedule_selector(BlocksLayer::Bupdata10), 10);
		


	}
	
	///灯泡
	///
	///
	/*//挡板
	b2BodyDef bodyDef3;
	//bodyDef1.type = b2_dynamicBody; //物体的类型，不动的，坚硬的~ 可以把这样的物体当成地面  
	b2PolygonShape borderShape3; // 一个方形的形状  
	b2FixtureDef borderFixture3; // 一个定制器  

	//定义地板  
	bodyDef3.position.Set(465 / PTM_RATIO, VISIBLE_SIZE.height / PTM_RATIO); // 地板在0，0位置  
	borderShape3.SetAsBox(10 / PTM_RATIO, 10 / PTM_RATIO); //设置长度和高度，这里描述的地板就像是X轴，是一条线  
	borderFixture3.shape = &borderShape3;
	b2Body * ground3 = world->CreateBody(&bodyDef3); //在世界中创建一个物体（地面）  
	ground3->CreateFixture(&borderFixture3);          //定制地面的形状  

	//挡板
	b2BodyDef bodyDef4;
	//bodyDef1.type = b2_dynamicBody; //物体的类型，不动的，坚硬的~ 可以把这样的物体当成地面  
	b2PolygonShape borderShape4; // 一个方形的形状  
	b2FixtureDef borderFixture4; // 一个定制器  

	//定义地板  
	bodyDef4.position.Set(495 / PTM_RATIO, VISIBLE_SIZE.height / PTM_RATIO); // 地板在0，0位置  
	borderShape4.SetAsBox(10 / PTM_RATIO, 10 / PTM_RATIO); //设置长度和高度，这里描述的地板就像是X轴，是一条线  
	borderFixture4.shape = &borderShape4;
	b2Body * ground4 = world->CreateBody(&bodyDef4); //在世界中创建一个物体（地面）  
	ground4->CreateFixture(&borderFixture4);*/






	//Player::sharePlayer()->setPosition(ccp(0, 0));

	//
	/*	Sprite * gameBYalong = Sprite::create("gameBYalong.png");
		gameBYalong->setTag(405);
		gameBYalong->setAnchorPoint(ccp(0, 0));
		gameBYalong->setPosition(ccp(VISIBLE_SIZE.width, 0.75*VISIBLE_SIZE.height));
		this->addChild(gameBYalong);


		Sprite * name = Sprite::create("name92.png");
		name->setAnchorPoint(ccp(0, 0));
		name->setTag(401);
		name->setPosition(ccp(0, VISIBLE_SIZE.height));
		this->addChild(name);


		//zhuti
		Sprite * zhuti1 = Sprite::create("zhuti1.png");
		zhuti1->setAnchorPoint(ccp(0, 0));
		zhuti1->setTag(501);
		zhuti1->setPosition(ccp(775, 0.45 * VISIBLE_SIZE.height));
		zhuti1->setOpacity(0);
		this->addChild(zhuti1);*/

	/*	Sprite * zhuti2 = Sprite::create("zhuti1.png");
		zhuti2->setAnchorPoint(ccp(0, 0));
		zhuti2->setTag(502);
		zhuti2->setPosition(ccp(220, 0.45 * VISIBLE_SIZE.height));
		zhuti2->setOpacity(0);
		this->addChild(zhuti2);

		Sprite * zhuti3 = Sprite::create("zhuti1.png");
		zhuti3->setAnchorPoint(ccp(0, 0));
		zhuti3->setTag(503);
		zhuti3->setPosition(ccp(405, 0.45 * VISIBLE_SIZE.height));
		zhuti3->setOpacity(0);
		this->addChild(zhuti3);

		Sprite * zhuti4 = Sprite::create("zhuti1.png");
		zhuti4->setAnchorPoint(ccp(0, 0));
		zhuti4->setTag(504);
		zhuti4->setPosition(ccp(590, 0.45 * VISIBLE_SIZE.height));
		zhuti4->setOpacity(0);
		this->addChild(zhuti4);

		Sprite * zhuti5 = Sprite::create("zhuti1.png");
		zhuti5->setAnchorPoint(ccp(0, 0));
		zhuti5->setTag(505);
		zhuti5->setPosition(ccp(775, 0.45 * VISIBLE_SIZE.height));
		zhuti5->setOpacity(0);
		this->addChild(zhuti5);*/



	/*auto zhuti2Action = CCMoveBy::create(0.2, ccp(0, -140));
	auto zhuti2EaseOut = CCEaseExponentialOut::create(zhuti2Action);

	auto zhitu3Action = CCMoveBy::create(0.3, ccp(0, -140));
	auto zhuti3EaseOut = CCEaseExponentialOut::create(zhitu3Action);

	auto zhuti4Action = CCMoveBy::create(0.4, ccp(0, -140));
	auto zhuti4EaseOut = CCEaseExponentialOut::create(zhuti4Action);

	auto zhuti5Action = CCMoveBy::create(0.5, ccp(0, -140));
	auto zhuti5EaseOut = CCEaseExponentialOut::create(zhuti5Action);
	*/

	//
	/*	Sprite * UI_BL1 = Sprite::create("UI_BL1.png");
		UI_BL1->setAnchorPoint(ccp(0, 0));
		UI_BL1->setTag(402);
		UI_BL1->setPosition(ccp(-UI_BL1->getContentSize().width, 0.65 * VISIBLE_SIZE.height));
		this->addChild(UI_BL1);

		Sprite * UI_BL2 = Sprite::create("UI_BL2.png");
		UI_BL2->setAnchorPoint(ccp(0, 0));
		UI_BL2->setTag(403);
		UI_BL2->setPosition(ccp(VISIBLE_SIZE .width, 0.45 * VISIBLE_SIZE.height));
		//this->addChild(UI_BL2);


		auto gameAction = CCMoveTo::create(0.9, ccp(642, 0.75 * VISIBLE_SIZE.height));
		auto gameEaseOut = CCEaseExponentialOut::create(gameAction);
		gameBYalong->runAction(gameEaseOut);


		auto nameAction = CCMoveTo::create(1.2, ccp(0, 0.8 * VISIBLE_SIZE.height));
		auto nameEaseOut = CCEaseExponentialOut::create(nameAction);
		name->runAction(nameEaseOut);

		auto UI_BL1Action = CCMoveBy::create(0.9, ccp(VISIBLE_SIZE.width, 0));
		auto UI_BL1EaseOut = CCEaseExponentialOut::create(UI_BL1Action);
		UI_BL1->runAction(UI_BL1EaseOut);

		auto UI_BL2Action = CCMoveBy::create(0.9, ccp(-VISIBLE_SIZE.width, 0));
		auto UI_BL2EaseOut = CCEaseExponentialOut::create(UI_BL2Action);
		//UI_BL2->runAction(UI_BL2EaseOut);

		auto call1 = CallFunc::create([this](){
		this->getChildByTag(501)->setOpacity(255);
		this->getChildByTag(501)->runAction(CCEaseElasticOut::create(CCMoveBy::create(0.3, ccp(0, -140))));

		});
		UI_BL2->runAction(Sequence::create(UI_BL2EaseOut, call1, nullptr));
		*/
	




	//初始化重力感应
	zhongliganying = 0;
	jishu = 0;
	_colorDotCnt = 1;
	_light1 = 0;
	//fire_sign1 = true;
	//fire_sign2 = true;
	//fire_sign3 = true;
	xian_sign = true;
	holl_hight = 0;
	huanchong_sign = true;
	huanchong_sign2 = false;
	zhuzi_sign = true;
	zhuzi = 1;
	zhongliganyingshiling = true;
	touch_sign = true;
	sign_JG = 0;
	sign_ZLGY = 1;
	Gs0 = true;
	Gs1 = true;
	t1 = 0; 
	t2 = 0;
	xxLight = false;
	isLastBl = false;
	firstXXL = true;
	touch_sign2 = true;
	//大乱数组顺序
	//int j1 = 0;
	//int r11 =  rand() % 4;
	//j1 = sign_ZA[0];
	//sign_ZA[0] = sign_ZA[r11];
	//sign_ZA[r11] = j1;
	for (int i = 0; i < 15; i++){
		int j = 0;
		int r1 = rand() % 9;
		int r2 = rand() % 9;
		if (sign_ZA[r1] == 1){ r2 = rand() % 4; }
		else if (sign_ZA[r2] == 1){ r1 = rand() % 4; }
		
			j = sign_ZA[r1];
			sign_ZA[r1] = sign_ZA[r2];
			sign_ZA[r2] = j;
		
		//j = sign_XA[r1];
		//sign_XA[r1] = sign_XA[r2];
		//sign_XA[r2] = j;

		
	}

	//初始化
	_filesNames.randomFaileNames();
	InitBlocksAttribute();
	
	//监听
	/*	auto dispatcher = Director::getInstance()->getEventDispatcher();
		auto listener2 = EventListenerKeyboard::create();
	listener2->onKeyReleased = [=](EventKeyboard::KeyCode code, Event* e){

		switch (code){
		case EventKeyboard::KeyCode::KEY_K:

		//	shengTi->SetTransform(b2Vec2(shengTi->GetPosition().x - 70 / PTM_RATIO, shengTi->GetPosition().y), 0);
			body_P->SetTransform(b2Vec2(body_P->GetPosition().x - 70 / PTM_RATIO, body_P->GetPosition().y), 0);
			hand1->SetTransform(b2Vec2(hand1->GetPosition().x - 70 / PTM_RATIO, hand1->GetPosition().y), 0);
			hand3->SetTransform(b2Vec2(hand3->GetPosition().x - 70 / PTM_RATIO, hand3->GetPosition().y), 0);
			//shengTi->ApplyLinearImpulse(b2Vec2( -0.01, 0), shengTi->GetWorldCenter(), true);
			break;
		case EventKeyboard::KeyCode::KEY_L:
		//	shengTi->SetTransform(b2Vec2(shengTi->GetPosition().x + 70 / PTM_RATIO, shengTi->GetPosition().y), 0);
			body_P->SetTransform(b2Vec2(body_P->GetPosition().x + 70 / PTM_RATIO, body_P->GetPosition().y), 0);
			hand1->SetTransform(b2Vec2(hand1->GetPosition().x + 70 / PTM_RATIO, hand1->GetPosition().y), 0);
			hand3->SetTransform(b2Vec2(hand3->GetPosition().x + 70 / PTM_RATIO, hand3->GetPosition().y), 0);
			//shengTi->ApplyLinearImpulse(b2Vec2(-0.01, 0), shengTi->GetWorldCenter(), true);
		}
	};

	dispatcher->addEventListenerWithSceneGraphPriority(listener2, this);*/




	//
	//parent_B = SpriteBatchNode::create("bl.png", 100);
	//addChild(parent_B);
	//jiaplayer


	//切换光源
	this->schedule(schedule_selector(BlocksLayer::Bupdata7));
	
//	this->schedule(schedule_selector(BlocksLayer::Bupdata6),2);
	//物理模拟跟新
	scheduleUpdate();
	createOcenion();
	//this->setCameraMask(2);
//	this->schedule(schedule_selector(BlocksLayer::Bupdata_GJ));
	//读取粒子效果
	
	return true;
}


//先初始化两个屏幕Blocks
void BlocksLayer::InitBlocks(){

	
	//先初始化1.3屏幕的block
	l = 0;
	t = 1;

	while (true)
	{
		
		//log("%f................................................",_blocksAttribute[l]._y);
		AddBlock(_blocksAttribute[l]);
		
		l++;
		//log("%f                  %f", _blocksAttribute[l]._y, VISIBLE_SIZE.height * 2);
		if (_blocksAttribute[l]._y > height * 1.2f)break;//VISIBLE_SIZE.height * 2
	}


	}
//加入block
Block*  BlocksLayer::AddBlock(BlockAttributes &blockAttri)
{
	
	//srand((unsigned)time(NULL));
	//INIT_RANDOM_ENGINE;
	//Block *BlockSprite = Block::createFrameName(blockAttri._color);
	auto BlockSprite = Block::create();
	//cocos2d::CCTexture2D* texture = cocos2d::CCTextureCache::sharedTextureCache()->addImage("bl.png");
	//BlockSprite->setTexture(texture);
	BlockSprite->setPosition(blockAttri._x, blockAttri._y);
	//log("l = %d   x = %f   y = %f",l, blockAttri._x,blockAttri._y);
	//(float)(rand()%600)
	BlockSprite->setAttributes(blockAttri);
	/*if (BlockSprite->getPositionY() < VISIBLE_SIZE.height)
	{
		BlockSprite->setOpacity(0);
		auto action = cocos2d::CCFadeIn::create(1);
		BlockSprite->runAction(action);
	}*/
	//parent_B->addChild(BlockSprite);
	Sprite_.push_back(BlockSprite);
	BlockSprite->setCameraMask(2);
//	BlockSprite->setEffect(_effect, "bl1_n.png");
	
	
	this->addChild(BlockSprite,5);
	
	if (blockAttri._allow){
		//
		//blockBody
		//创建body所需
		b2PolygonShape shape;
		fixDef_block.filter.categoryBits = 0x0002;
		//fixture
		shape.SetAsBox(60 / PTM_RATIO, 1 / PTM_RATIO);
		fixDef_block.shape = &shape;
		fixDef_block.density = 1;
		fixDef_block.friction = 1;
		fixDef_block.restitution = 0;
		//静态不用指定Sprite
		bodyDef_block.userData = BlockSprite;
		//初始化位置
		bodyDef_block.position.Set(BlockSprite->getPosition().x / PTM_RATIO, (BlockSprite->getPosition().y + 20) / PTM_RATIO);
		//创建body
		b2Body* body_G = world->CreateBody(&bodyDef_block);


		//body_G->SetUserData((*iter));
		//创建body的fixture
		body_G->CreateFixture(&fixDef_block);
	
	}
		if (blockAttri._isMove){
			int pos;
			int x;
			float t;
			int a = 1 + (rand() % 4);
			if (a == 1){ pos = 100; x = width - 200; t = 3; }
			else if (a == 2){ pos = width / 2; x = width / 2 - 200; t = 2; }
			else { pos = width / 2; x = 200 - width / 2; t = 2; }
			BlockSprite->setPosition(pos, blockAttri._y);
			auto ani = CCMoveBy::create(t, Vec2(x, 0));
			BlockSprite->runAction(CCRepeatForever::create(Sequence::create(ani, ani->reverse(), nullptr)));
		}
		else if (blockAttri._isXie){
			int r = -20 + (rand()) % 40;
			BlockSprite->setRotation(r);
		}
		else if (blockAttri._isRota){
			BlockSprite->setRotation(-30);
			auto ani = CCRotateBy::create(1.5, 60);
			BlockSprite->runAction(CCRepeatForever::create(Sequence::create(ani, ani->reverse(), nullptr)));
		}
		else if (blockAttri._isMoRo){
			int pos;
			int x;
			float t;
			int a = 1 + (rand() % 3);
			if (a == 1){ pos = 100; x = width - 200; t = 3; }
			else if (a == 2){ pos =width / 2; x = width / 2 - 200; t = 2; }
			else { pos = width / 2; x = 200 - width / 2; t = 2; }
			BlockSprite->setPosition(pos, blockAttri._y);
			BlockSprite->setRotation(-30);
			auto ani = CCMoveBy::create(t, Vec2(x, 0));
			auto ani2 = CCRotateBy::create(1.5, 60);
			BlockSprite->runAction(CCRepeatForever::create(Sequence::create(ani, ani->reverse(), nullptr)));
			BlockSprite->runAction(CCRepeatForever::create(Sequence::create(ani2, ani2->reverse(), nullptr)));
		}
	

		//黑洞
		else if (blockAttri._y>(8000 * (sign_ZA[5] - 1) + height / 2) && blockAttri._y<(8000 * (sign_ZA[5]) - height / 2))
		{

			int first_holl = _cameraHeight + 2500;
			if (first_holl > holl_hight + 1550){
				int Rand = (0 + rand() % 2);
				if (Rand == 1)Rand = 0;
				else Rand = width;
				CCTexture2D *texture_holl = CCTextureCache::sharedTextureCache()->textureForKey("holll.png");

				//实例化精灵  
				CCSprite *sp = CCSprite::createWithTexture(texture_holl);
				sp->setCameraMask(2);
				this->addChild(sp,4);
				sp->setPosition(Rand, first_holl);
				holl.push_back(b2Vec2(Rand / PTM_RATIO, first_holl / PTM_RATIO));
				holl_hight = first_holl;
				this->schedule(schedule_selector(BlocksLayer::Bupdata11));
			}
			
			
		}
		//柱子
		else if (zhuzi_sign&&blockAttri._y>(8000 * (sign_ZA[6]-1))){// 
			/*	boom_sign2 = false;
			int first_holl = _cameraHeight + 1400;
			if (first_holl > holl_hight + 400){
			int Rand1 = 100+(rand() % (int)VISIBLE_SIZE.width/2);
			int Rand2 = (VISIBLE_SIZE.width / 2+rand() % (int)VISIBLE_SIZE.width-100);
			auto sp1 = Sprite::create("XINGXING9.png");
			sp1->setTag(3331);
			sp1->setCameraMask(2);
			this->addChild(sp1);
			sp1->setPosition(Rand1, first_holl);
			auto ani1 = CCRepeatForever::create(CCMoveBy::create(10, Vec2(0, -VISIBLE_SIZE.height)));
			sp1->runAction(ani1);
			auto sp2 = Sprite::create("XINGXING9.png");
			sp2->setTag(3332);
			sp2->setCameraMask(2);
			this->addChild(sp2);
			sp2->setPosition(Rand2, first_holl);
			auto ani2 = CCRepeatForever::create(CCMoveBy::create(10, Vec2(0, -VISIBLE_SIZE.height)));
			sp2->runAction(ani2);
			//boomPos.push_back(b2Vec2(Rand / PTM_RATIO, first_holl / PTM_RATIO));
			holl_hight = first_holl;
			this->schedule(schedule_selector(BlocksLayer::Bupdata12));
			}*/

			zhuzi_sign = false;
			CCSprite *sp1 = CCSprite::createWithSpriteFrameName("zhuzi.png");
			//auto sp1 = Sprite::create("zhuzi.png");
			sp1->setTag(444);
			sp1->setScaleY(height/1400);
			//sp->setOpacity(0);
			sp1->setAnchorPoint(ccp(0.5,0)); 
			sp1->setCameraMask(2);
			this->addChild(sp1);
			sp1->setPosition(480, 8000 * (sign_ZA[6] - 1) + height*0.75);
	//		auto sp2 = Sprite::create("zhuzi.png");
		//	sp2->setTag(445);
		
		//	sp2->setAnchorPoint(ccp(0.5, 0));
		//	sp2->setCameraMask(2);
		//	this->addChild(sp2);
		//	sp2->setPosition(480, 8000 * (sign_ZA[6] - 1)+2000);
		
			this->schedule(schedule_selector(BlocksLayer::Bupdata12));
			
			
		}
		//缓冲
		else if (huanchong_sign && (body_P->GetPosition().y*PTM_RATIO)>(8000 * (sign_ZA[7] - 1)) + 500){
			//sign_HC = sign_ZA[6];
			huanchong_sign = false; huanchong_sign2 = true;
			huanchonglistener = EventListenerTouchOneByOne::create();
			huanchonglistener->onTouchBegan = CC_CALLBACK_2(BlocksLayer::touchBegin, this);
			_eventDispatcher->addEventListenerWithSceneGraphPriority(huanchonglistener, this);
			
		
		}
		
	//	else //if (zhongliganyingshiling && (shengTi->GetPosition().y)>(8000 * (sign_ZA[8] - 1) + VISIBLE_SIZE.height))
	//	{
			/*for (auto iter = block_ZA.begin(); iter != block_ZA.end();)
			{
			if ((*iter)->getAttribute()._allow){
			auto sp = Sprite::create("xian.png");
			sp->setCameraMask(2);
			sp->setTag(3331+sign_JG);
			sp->setRotation(90);
			this->addChild(sp);
			(*iter)->setSign_jg(sign_JG);
			sign_JG++;
			sp->setPosition(0,(*iter)->getPositionY() + 900);
			//jiguang.push_back(sp);

			}
			iter = block_ZA.erase((iter));
			}*/
			//zhongliganyingshiling = false;
	//	}
		
		if (blockAttri._y<8000 * (sign_ZA[7])&&blockAttri._y>8000 * (sign_ZA[7] - 1))
		if (blockAttri._color == "bl1.png"){
			//更换精灵图片
			CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("bll1.png");
			BlockSprite->setTexture(texture);
			
		}
		else if (blockAttri._color == "bl2.png"){
			//更换精灵图片
			CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("bll2.png");
			BlockSprite->setTexture(texture);
		}
		else if (blockAttri._color == "bl3.png"){
			//更换精灵图片
			CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("bll3.png");
			BlockSprite->setTexture(texture);
		}
		else if (blockAttri._color == "bl4.png"){
			//更换精灵图片
			CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("bll4.png");
			BlockSprite->setTexture(texture);
		}
		else if (blockAttri._color == "bl5.png"){
			//更换精灵图片
			CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("bll5.png");
			BlockSprite->setTexture(texture);
		}
		else if (blockAttri._color == "bl6.png"){
			//更换精灵图片
			CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("bll6.png");
			BlockSprite->setTexture(texture);
		}
		else if (blockAttri._color == "bl7.png"){
			//更换精灵图片
			CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("bll7.png");
			BlockSprite->setTexture(texture);
		}
		else if (blockAttri._color == "bl8.png"){
			//更换精灵图片
			CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("bll8.png");
			BlockSprite->setTexture(texture);
		}
		else if (blockAttri._color == "bl9.png"){
			//更换精灵图片
			CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("bll9.png");
			BlockSprite->setTexture(texture);
		}
		else {
			//更换精灵图片
			CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("bll10.png");
			BlockSprite->setTexture(texture);
		}
	
	
	return BlockSprite;
}
//初始化block属性
void BlocksLayer::InitBlocksAttribute(){
	INIT_RANDOM_ENGINE;
	srand((unsigned)time(NULL));
	std::string color;
	bool allow;
	//先设高度
	int z[700] = {0};
	int xh[700] = {0};
	int t = 1;
	int k = 0;
	z[0] = 350;//第一个block400;
	xh[0] = mf::rn(90, width - 90); // ((rand()) % ((int)VISIBLE_SIZE.width));
	//算出每个block的高度
	//int cut1 = 1;
	int cut2 = 0;
	bool sign1 = true;
	bool sign2 = true;
	bool sign3 = true;
	bool sign4 = true;
	bool sign5 = true;
	bool sign6 = true;
	bool sign7 = true;
	bool sign8 = true;
	bool sign9 = true;

	for (int p = 1; p <= 9; p++){
		z[t-1] = 550 + (p-1) * 8000;//第一个block400;
		xh[t - 1] = 480;
		cut2 = t-1;
		while (true){
			
			z[t] = z[t - 1] + mf::rn(60, PLAYER_HIGT / 2/*player跳的高度*/);//((rand()) % (PLAYER_HIGT / 2))
			//log("%d", t);
			//log("%f", z[t]);
			xh[t] = mf::rn(90, width - 90);
			/*if (sign1&&z[t] > 8000){
			z[t] = 8000;
			z[++t] = 8000 + 650;
			sign1 = false;
			}
			else if (sign2&&z[t] > 16000){
			z[++t] = 16000 + PLAYER_HIGT;
			sign2 = false;
			}
			else if(sign3&&z[t] > 24000){
			z[t] = 24000;
			z[++t] = 24000 + 650;
			sign3 = false;
			}
			else if(sign4&&z[t] > 32000){
			z[t] = 32000;
			z[++t] = 32000 + 650;
			sign4 = false;
			}
			else if(sign5&&z[t] > 40000){
			z[t] = 40000;
			z[++t] = 40000 + 650;
			sign5 = false;
			}
			else if(sign6&&z[t] > 48000){
			z[t] = 48000;
			z[++t] = 48000 + 650;
			sign6 = false;
			}
			else if(sign7&&z[t] > 56000){
			z[t] = 56000;
			z[++t] = 56000 + 650;
			sign7 = false;
			}
			else if(sign8&&z[t] > 64000){
			z[t] = 64000;
			z[++t] = 64000 + 650;
			sign8 = false;
			}
			else if(sign9&&z[t] > 72000){
			z[t] = 72000;
			z[++t] = 72000 + 650;
			sign9 = false;
			}
			*/
			//超过最高跳出	
			if (z[t] > 8000 * p){ z[t] = 8000 * p;  if (z[t - 1] + 100 > z[t]){ xh[t - 1] = -300; }xh[t] = 480; ++t; break; }
			//柱子
			if (p == sign_ZA[6]){
				if ((xh[t]>350 && xh[t]<600))
				{

				}
				else{
					t++;
				}
			}
			else{
				
					t++;
				
			}
			
		}


		//算出每个block横坐标
		/*while (true){
		++k;
		xh[k] = mf::rn(90, VISIBLE_SIZE.width - 90); //(60 + (rand()) % ((int)(VISIBLE_SIZE.width - 60)));
		if (abs(xh[k] - xh[k - 1]) < 120)
		{

		k--;

		}
		if (k == t - 1)break;

		}*/


		//blocks添加颜色是否可踩
		for (int i = cut2; i < t; i++)
		{
			
			//不能超过t
			/*	if (i >= t)
			{
			break;
			}*/

			
			
			if (i <= cut2){
				if (p != sign_ZA[4]){
					//第一个block
					color = _filesNames[p - 1];
					allow = true;
					_blocksAttribute.push_back(BlockAttributes(xh[i], z[i], color, allow, false, false, false, false));
				}
				else{	//第一个block
					color = _filesNames[9];
					allow = true;
					_blocksAttribute.push_back(BlockAttributes(xh[i], z[i], color, allow, false, false, false, false));
				}
			}
			else{

				//先在player跳的高度区间判断
				int x = i;
				//log("%d",i);
				//log("%d", _blocksAttribute[i-1]._allow);
				for (;;){
				
					//log("%d", z[x] - z[i-1] > 300);
					if (z[x] - z[i - 1] > PLAYER_HIGT - 90)break;
					if (z[x+1] == 0)break;
					//log("%d", x);
					x++;
			
					
				}
				
				//判断几个颜色可以踩
			
				int YS = p-1;
				int YZ = 0;
				float Vsib = height / 2;
				
			/*	 if (p == 9)
				{
					YS = 8;
				}
				else if (p == 8)
				{
					YS = 7;
				}
				else if (p == 7)
				{
					YS = 6;
				}
				else if (p == 6)
				{
					YS = 5;
				}
				else if (p == 5)
				{
					YS = 4;
				}
				else if (p == 4)
				{

					YS = 3;
				}
				else if (p == 3)
				{

					YS = 2;
				}
				else if (p == 2)
				{

					YS = 1;
				}
				else// if (z[x] > visibleSize.height * 0)
				{
					YS = 0;
				}*/
				/////////////////////////////使关界限处能采和不能踩不矛盾
				
				
				 if (z[x] < 56000 + Vsib && z[x] > (56000 - Vsib))
				{
					YZ = 8;
				}
				else if (z[x] < 48000 + Vsib && z[x] > (48000 - Vsib))
				{
					YZ = 7;
				}
				else if (z[x] < 40000 + Vsib && z[x] > (40000 - Vsib))
				{
					YZ = 6;
				}
				else if (z[x] < 32000 + Vsib && z[x] > (32000 - Vsib))
				{
					YZ = 5;
				}
				else if (z[x] < 24000 + Vsib && z[x] > (24000 - Vsib))
				{

					YZ = 4;
				}
				else if (z[x] < 16000 + Vsib && z[x] > (16000 - Vsib))
				{

					YZ = 3;
				}
				else if (z[x] < 8000 + Vsib && z[x] > (8000 - Vsib))
				{

					YZ = 2;
				}
				else// if (z[x] > visibleSize.height * 0)
				{


					YZ = YS;
				}

				//在这区间选出哪个可以踩那个不可以踩
				//log("%d", x - 1 - i);
			
				if (x - i == 0){ ++x; }
				int n = i - 1 + mf::rn(1, x - i/*选出一个可以踩的*/);
			
				//log("%d", mf::rn(1, x - i/*选出一个可以踩的*/));
				//log("%d",n);
				//给i赋值;
				int h = 0, k = 0, j = 0;
				//给选出的赋值

				for (int y = i; y < x ; y++)
				{
					
					bool _isMove = false;
					bool _isXie = false;
					bool _isRota = false;
					bool _isMoRo = false;
					/*if (z[y]<32000)
					if (z[y] < ((sign_ZA[0] + 1) * 8000 - Vsib) && z[y]>(sign_ZA[0] * 8000 + Vsib)){
						if ((1 + (rand()) % 3) == 2){
							_isMove = true;  _isXie = false;  _isRota = false;  _isMoRo = false;
						}
					}
					else if (z[y] < ((sign_ZA[1] + 1) * 8000 - Vsib) && z[y]>(sign_ZA[1] * 8000 + Vsib)){
						_isMove = false;  _isXie = true;  _isRota = false;  _isMoRo = false;
					}
					else if (z[y] < ((sign_ZA[2] + 1) * 8000 - Vsib) && z[y]>(sign_ZA[2] * 8000 + Vsib)){
						if ((1 + (rand()) % 3) == 2){
							_isMove = false;  _isXie = false;  _isRota = true;  _isMoRo = false;
						}
					}
					else if (z[y] < ((sign_ZA[3] + 1) * 8000 - Vsib) && z[y]>(sign_ZA[3] * 8000 + Vsib)){
						if ((1 + (rand()) % 3) == 2){
							_isMove = false;  _isXie = false;  _isRota = false;  _isMoRo = true;
						}
					}*/
					//前四关
					
						if (p == sign_ZA[0]){
							if ((1 + (rand()) % 3) == 2){
								_isMove = true;  _isXie = false;  _isRota = false;  _isMoRo = false;
							}
						}
						else if (p == sign_ZA[1]){
							_isMove = false;  _isXie = true;  _isRota = false;  _isMoRo = false;
						}
						else if (p == sign_ZA[2]){
							if ((1 + (rand()) % 3) == 2){
								_isMove = false;  _isXie = false;  _isRota = true;  _isMoRo = false;
							}
						}
						else if (p == sign_ZA[3])
							if ((1 + (rand()) % 3) == 2){
								_isMove = false;  _isXie = false;  _isRota = false;  _isMoRo = true;
							}
						
					
					//判断反颜色
							if (p != sign_ZA[4]){
						if (y == n)
						{
							//保证没关最后一个能采都是false
							if (y == t - 1){
								//log("%d-------------------%d", y, z[y]);
								_blocksAttribute.push_back(BlockAttributes(xh[y], z[y], _filesNames[mf::rn(0, YS)], true, false, false, false, false));
							}
							else{
								//log("%d-------------------%d", y, z[y]);
								_blocksAttribute.push_back(BlockAttributes(xh[y], z[y], _filesNames[mf::rn(0, YS)], true, _isMove, _isXie, _isRota, _isMoRo));
							}
							


							h = y;
						}
						else{

							allow = mf::rn(2, 14) < 3;

							if (allow)
							{
								//保证没关最后一个能采都是false
								if (y == t - 1){
									//log("%d-------------------%d", y, z[y]);
									_blocksAttribute.push_back(BlockAttributes(xh[y], z[y], _filesNames[mf::rn(0, YS)], true, false, false, false, false));
								}
								else{ 
									//log("%d-------------------%d", y, z[y]);
								_blocksAttribute.push_back(BlockAttributes(xh[y], z[y], _filesNames[mf::rn(0, YS)], true, _isMove, _isXie, _isRota, _isMoRo)); }
								

								k = y;
							}
							else
							{
								//保证没关最后一个能采都是false
								if (y == t - 1){
									//log("%d-------------------%d", y, z[y]);
									_blocksAttribute.push_back(BlockAttributes(xh[y], z[y], _filesNames[mf::rn(0, YS)], true, false, false, false, false));
								}
								else{
								//	log("%d-------------------%d", y, z[y]);
									_blocksAttribute.push_back(BlockAttributes(xh[y], z[y], _filesNames[mf::rn(YZ + 1, 9)], false, _isMove, _isXie, _isRota, _isMoRo)); 
								}
									
								j = y;

							}
						}
				
					}



					else{
						if (y == n)
						{
							//log("%d-------------------%d", y, z[y]);
							_blocksAttribute.push_back(BlockAttributes(xh[y], z[y], _filesNames[mf::rn(YZ + 1, 9)], true, _isMove, _isXie, _isRota, _isMoRo));


							h = y;
						}
						else{

							allow = mf::rn(2, 14) < 3;

							if (allow)
							{
								//log("%d-------------------%d", y, z[y]);
								_blocksAttribute.push_back(BlockAttributes(xh[y], z[y], _filesNames[mf::rn(YZ + 1, 9)], true, _isMove, _isXie, _isRota, _isMoRo));

								k = y;
							}
							else
							{  //保证没关最后一个能采
								if (y == t - 1){
									//log("%d-------------------%d", y, z[y]);
									_blocksAttribute.push_back(BlockAttributes(xh[y], z[y], _filesNames[mf::rn(YZ + 1, 9)], true, false, false, false, false));
								}
								else{
									//log("%d-------------------%d", y, z[y]);
									_blocksAttribute.push_back(BlockAttributes(xh[y], z[y], _filesNames[mf::rn(0, YS)], false, _isMove, _isXie, _isRota, _isMoRo));
									j = y;
								}
									

							}
						}
					}

				}

				//是循环跳过已经赋值的block
				if (h > k&&h>j){ i = h; }
				if (k>h&&k>j){ i = k; }
				if (j > h&&j>k){ i = j; }


			}


		}
	}
	



}
//物理更新
void BlocksLayer::update(float delta){
	
	world->Step(0.015, 8, 1);
	//重力感应不卡
	//if (zhongliganying>0)
	//shengTi->ApplyLinearImpulse(b2Vec2(zhongliganying * 0.01, 0),shengTi->GetWorldCenter(),true);
	
	//else
//	shengTi->SetLinearVelocity(b2Vec2(-shengTi->GetLinearVelocity().x +zhongliganying * 5, shengTi->GetLinearVelocity().y));
	//shengTi->SetTransform(b2Vec2(shengTi->GetPosition().x + sign_ZLGY*zhongliganying * 70 / PTM_RATIO, shengTi->GetPosition().y), 0);
	body_P->SetTransform(b2Vec2(body_P->GetPosition().x + sign_ZLGY*zhongliganying * 70 / PTM_RATIO, body_P->GetPosition().y), 0);
	//head->SetTransform(b2Vec2(head->GetPosition().x + sign_ZLGY*zhongliganying * 50 / PTM_RATIO, head->GetPosition().y), 0);
	hand1->SetTransform(b2Vec2(hand1->GetPosition().x + sign_ZLGY*zhongliganying * 50 / PTM_RATIO, hand1->GetPosition().y), hand1->GetAngle());
	//hand2->SetTransform(b2Vec2(hand2->GetPosition().x + sign_ZLGY*zhongliganying * 50 / PTM_RATIO, hand2->GetPosition().y), hand2->GetAngle());
	hand3->SetTransform(b2Vec2(hand3->GetPosition().x + sign_ZLGY*zhongliganying * 50 / PTM_RATIO, hand3->GetPosition().y), hand3->GetAngle());
	//hand4->SetTransform(b2Vec2(hand4->GetPosition().x + sign_ZLGY*zhongliganying * 50 / PTM_RATIO, hand4->GetPosition().y), hand4->GetAngle());
	Sprite *s;
	for (b2Body *b = world->GetBodyList(); b; b = b->GetNext())
	{
		CCSprite *sprite = (CCSprite *)b->GetUserData();
		if (b->GetType() == b2_dynamicBody)
		{
			
			if (sprite != NULL)
			{
				//获取物体的坐标并转换成cocos2d的坐标
				b2Vec2 bodyPos = b->GetPosition();
				CCPoint pos = ccp(bodyPos.x * PTM_RATIO, bodyPos.y * PTM_RATIO );
				float32 rotation = -1 * CC_RADIANS_TO_DEGREES(b->GetAngle());        //转换角度
				sprite->setPosition(pos);        //设置精灵坐标
				sprite->setRotation(rotation);    //设置精灵角度
			}
			/*if (b->GetUserData())
			{
			s = (Sprite*)b->GetUserData();
			s->setPosition(b->GetPosition().x * PTM_RATIO, b->GetPosition().y*PTM_RATIO);
			s->setRotation(-1* CC_RADIANS_TO_DEGREES(b->GetAngle()));
			}*/
		}
		else
		{
			if (sprite != NULL)
			{
				CCPoint pos = sprite->getPosition();// ccp(bodyPos.x * PTM_RATIO, bodyPos.y * PTM_RATIO);
				//float32 rotation = -1 * CC_RADIANS_TO_DEGREES(b->GetAngle());        //转换角度
				b->SetTransform(b2Vec2(pos.x / PTM_RATIO, pos.y / PTM_RATIO), 0);        //设置精灵坐标
				//sprite->setRotation(rotation);
			}
		}
	}
}
//使Player不溢出 & 背景重复 
void BlocksLayer::Bupdata2(float dt)
{
	//使player左右不溢出
	if (body_P->GetPosition().x + Player::sharePlayer()->getContentSize().width / 2 / PTM_RATIO < 0){
		body_P->SetTransform(b2Vec2((VISIBLE_SIZE.width + Player::sharePlayer()->getContentSize().width / 2) / PTM_RATIO, body_P->GetPosition().y), 0);
		//shengTi->SetTransform(b2Vec2((VISIBLE_SIZE.width + 80) / PTM_RATIO, shengTi->GetPosition().y), 0);
		//head->SetTransform(b2Vec2((VISIBLE_SIZE.width + 100) / PTM_RATIO, head->GetPosition().y), 0);
		hand1->SetTransform(b2Vec2((VISIBLE_SIZE.width + 20) / PTM_RATIO, hand1->GetPosition().y), hand1->GetAngle());
		//hand2->SetTransform(b2Vec2((VISIBLE_SIZE.width + 20) / PTM_RATIO, hand2->GetPosition().y), hand2->GetAngle());
		hand3->SetTransform(b2Vec2((VISIBLE_SIZE.width + 20) / PTM_RATIO, hand3->GetPosition().y), hand3->GetAngle());
		//hand4->SetTransform(b2Vec2((VISIBLE_SIZE.width + 20) / PTM_RATIO, hand4->GetPosition().y), hand4->GetAngle());
	}
		
	if (body_P->GetPosition().x>(VISIBLE_SIZE.width + Player::sharePlayer()->getContentSize().width / 2) / PTM_RATIO){
		body_P->SetTransform(b2Vec2(-(Player::sharePlayer()->getContentSize().width / 2 / PTM_RATIO), body_P->GetPosition().y), 0);
		//shengTi->SetTransform(b2Vec2(-( 80) / PTM_RATIO, shengTi->GetPosition().y), 0);
		//head->SetTransform(b2Vec2(-( 100) / PTM_RATIO, head->GetPosition().y), 0);
		hand1->SetTransform(b2Vec2(-(20) / PTM_RATIO, hand1->GetPosition().y), hand1->GetAngle());
		//hand2->SetTransform(b2Vec2(-(20) / PTM_RATIO, hand2->GetPosition().y), hand2->GetAngle());
		hand3->SetTransform(b2Vec2(-(20) / PTM_RATIO, hand3->GetPosition().y), hand3->GetAngle());
		//hand4->SetTransform(b2Vec2(-(20) / PTM_RATIO, hand4->GetPosition().y), hand4->GetAngle());
	}
		
	
		//设置背景坐标
		if (this->getChildByTag(902)->getPositionY() < (_cameraHeight - 1930))
		{
			this->getChildByTag(902)->setPositionY(this->getChildByTag(901)->getPositionY() + 1930);
		}
		if (this->getChildByTag(901)->getPositionY() < (_cameraHeight - 1930))
		{
			this->getChildByTag(901)->setPositionY(this->getChildByTag(902)->getPositionY() + 1930);
		}

	
	
	
}
//加入和移除block&&lastLz
void BlocksLayer::Bupdata1(float dt)
{
	//log("-------------------%f", _blocksAttribute[l]._y);
	//if (_blocksAttribute[l]._y<72000)
	//log("%f", _blocksAttribute[l]._y);
	if (_cameraHeight +height*1.2> _blocksAttribute[l]._y){
	//	while (true){
		if (!effect){}
		else
		{
			if ((int)_blocksAttribute[l]._y % 8000 == 0){
				ParticleSystem* m_emitter1 = ParticleSystemQuad::create("lastBlock.plist");
				m_emitter1->retain();
				m_emitter1->setAutoRemoveOnFinish(true);
				ParticleBatchNode *batch = ParticleBatchNode::createWithTexture(m_emitter1->getTexture());
				//m_emitter1->setStartColor(Color4F(sp->getColor().r*0.0039, sp->getColor().g*0.0039, sp->getColor().b*0.0039, 139 * 0.0039));
				//m_emitter1->setEndColor(Color4F(sp->getColor().r*0.0039, sp->getColor().g*0.0039, sp->getColor().b*0.0039, 139 * 0.0039));
				batch->addChild(m_emitter1);
				batch->setPosition(480, _blocksAttribute[l]._y);
				batch->setCameraMask(2);
				batch->setTag(5003);
				addChild(batch);
				m_emitter1->release();
				CCSprite *sp = CCSprite::createWithSpriteFrameName("lastBlockSP1.png");
				//	auto sp = Sprite::create("lastBlockSP1.png");
				sp->setPosition(475, _blocksAttribute[l]._y + 50);
				sp->setCameraMask(2);
				sp->setTag(5002);
				addChild(sp);
			}
		}
		
			AddBlock(_blocksAttribute[l]); 
			
			if (_blocksAttribute[l]._y == 72000){ this->unschedule(schedule_selector(BlocksLayer::Bupdata1)); }
			l++;
		//	if (>(2 + t)*VISIBLE_SIZE.height)break;//(2 + t)*VISIBLE_SIZE.height
		//			}
		//t++;
	}
	//移除block
	for (auto iter = Sprite_.begin(); iter != Sprite_.end();)
	{
		


		//检测不在屏幕里的block移除
		if ((*iter)->getPosition().y < _cameraHeight)
		{
			
			this->removeChild((*iter),true);
			iter = Sprite_.erase(iter);
			//移除body
			//Sprite* sprite;
			b2Body *node = world->GetBodyList();
			while (node){
				b2Body *body = node;
				node = node->GetNext();
				//sprite = (Sprite *)body->GetUserData();
				if (body->GetPosition().y <  _cameraHeight / PTM_RATIO){
					world->DestroyBody(body);
					body == NULL;
				}
				
			}
		}
		else{

			break;
		};
	}
	

	/*//移除碰触的blocks
	for (auto iter = _bodyVect.begin(); iter != _bodyVect.end();)
	{

		world->DestroyBody(*iter);
		iter = _bodyVect.erase(_bodyVect.begin());

	}

	*/
/*	for (auto iter = Sprite_.begin(); iter != Sprite_.end(); iter++)
	{
		log("%f", (*iter)->_y);
		log("%d", (*iter)->_allow);
		if ((*iter)->_allow && (*iter)->getPosition().y<Player::sharePlayer()->getPosition().y+300){
			//
			//blockBody
			//创建body所需
			b2PolygonShape shape;
			fixDef_block.filter.categoryBits = 0x0002;
			//fixture
			shape.SetAsBox(60 / PTM_RATIO, 1 / PTM_RATIO);
			fixDef_block.shape = &shape;
			fixDef_block.density = 1;
			fixDef_block.friction = 1;
			fixDef_block.restitution = 0;
//静态不用指定Sprite
			bodyDef_block.userData = (*iter);
			//初始化位置
			bodyDef_block.position.Set((*iter)->getPosition().x / PTM_RATIO, ((*iter)->getPosition().y+20) / PTM_RATIO);
			//创建body
			b2Body* body_G = world->CreateBody(&bodyDef_block);

			
			//body_G->SetUserData((*iter));
			//创建body的fixture
			body_G->CreateFixture(&fixDef_block);
			(*iter)->_allow = false;
		}

	}*/

}
//星星闪烁
void BlocksLayer::Bupdata3(float dt){
//	if (xian_sign&&xianMove->GetPosition().x<490 ){ }
	//if (xianMove->GetPosition().x<490)xian_sign = true;
	if (cut == 0){}
	else{
		if (firstXXL){
			firstXXL = false;
			srand((unsigned)time(NULL));
			int Rand = rand() % cut;
			float x = xings.at(Rand)->GetPosition().x*PTM_RATIO;
			float y = xings.at(Rand)->GetPosition().y*PTM_RATIO + 40;
			Vec3 lightPos(x, y, 100);
			_effect->setLightPos(lightPos);
		}

		if (t1 > 220)xxLight = true;
		if (xxLight){
			xian_sign = false; _effect->setLightColor(cocos2d::Color3B(t1 -= 6, t1, t1));
			if (t1 < 10){
				xxLight = false;
				//随机xx闪烁
				this->scheduleOnce(schedule_selector(BlocksLayer::Bupdata13), 0);
			}

		}
		else
			_effect->setLightColor(cocos2d::Color3B(t1 += 3, t1, t1));
	}
	
	/*this->getChildByTag(2322)->setScale(0.5);
	this->getChildByTag(2322)->setOpacity(255);
	CCActionInterval * scaleto = CCScaleTo::create(2, 1.2);
	auto action2 = cocos2d::CCFadeOut::create(2);
	CCFiniteTimeAction * spawn = CCSpawn::create(scaleto, action2, NULL);
	this->getChildByTag(2322)->runAction(spawn);*/
}
//随机xx闪烁
void BlocksLayer::Bupdata13(float dt){

	srand((unsigned)time(NULL));
	//if (rand() % 9 == 5){
	//	Vec3 lightPos(480, 648, 100);
	//	_effect->setLightPos(lightPos);
	//}
	//else{
		int Rand = rand() % cut;
		float x = xings.at(Rand)->GetPosition().x*PTM_RATIO;
		float y = xings.at(Rand)->GetPosition().y*PTM_RATIO + 40;
		Vec3 lightPos(x, y, 100);
		_effect->setLightPos(lightPos);
	//}
	

}
//开始时灯变暗&并移除joint&fire渐变消失
void BlocksLayer::Bupdata6(float dt){
	
	if (t2 < 10){
		this->unschedule(schedule_selector(BlocksLayer::Bupdata6));
		//this->getChildByTag(2001)->getChildByTag(3001)->removeAllChildren();
		//this->getChildByTag(2001)->getChildByTag(3002)->removeAllChildren();
		//this->getChildByTag(2001)->getChildByTag(3003)->removeAllChildren();
		//this->getChildByTag(2001)->getChildByTag(3002)->runAction(FadeOut::create(1));
		//this->getChildByTag(2001)->getChildByTag(3003)->runAction(FadeOut::create(1));
			auto call5 = CallFunc::create([this](){
			b2Body *node = world->GetBodyList();
			while (node){
				b2Body *body = node;
				node = node->GetNext();
				if (body == body_P || body == hand1 || body == hand3 || body == bottomBorder){}
				else { this->removeChild((Sprite*)body->GetUserData()); world->DestroyBody(body); body == NULL; }
			}
			xings.clear();
			this->unschedule(schedule_selector(BlocksLayer::Bupdata10));
			this->unschedule(schedule_selector(BlocksLayer::Bupdata9));
		//	_light1 = 1; 
			beginGame();
		});
		
			this->getChildByTag(3001)->runAction(Sequence::create(FadeOut::create(1), call5, nullptr));
		
	}
	else{
		_effect->setAmbientLightColor(cocos2d::Color3B(t2 -= 5, t2, t2));
	}
		

}
//切换光源&&更新yun和星星位置
void BlocksLayer::Bupdata7(float dt){
	if (t2 > 200){
		this->unschedule(schedule_selector(BlocksLayer::Bupdata7));
		{


			CCTexture2D *texture_sp = CCTextureCache::sharedTextureCache()->textureForKey("playerTou.png");

			//实例化精灵  
			CCSprite *sp = CCSprite::createWithTexture(texture_sp);
			//CCSprite *sp = CCSprite::createWithSpriteFrameName("playerTou.png");
			//Sprite * sp = Sprite::create("playerTou.png");
			auto beganGame = cocos2d::CCMenuItemSprite::create(sp, sp, CC_CALLBACK_0(BlocksLayer::beginCallback, this, NULL));
			auto beganMenu = CCMenu::create(beganGame, NULL);
			//beganMenu->setAnchorPoint(ccp(0, 0));
			beganMenu->setPosition(ccp(this->getChildByTag(2001)->getContentSize().width / 2, sp->getContentSize().height / 2));
			beganMenu->setTag(1111);
			//Player::sharePlayer()->setAnchorPoint(ccp(0.5,0));

			this->getChildByTag(2001)->addChild(beganMenu);

		}

	}
	else
		_effect->setAmbientLightColor(cocos2d::Color3B(t2 += 5, t2, t2));
	//光源
//	if (_light1)
//	{	
	//	if (t1 > 244){}
	//	else
	//	{
	//		_effect->setLightColor(cocos2d::Color3B(t1 += 4, t1, t1));
	//	}
	//	_lightPos.set(this->getChildByTag(701)->getPositionX()+480, this->getChildByTag(701)->getPositionY()+100, 400);
	//	_effect->setLightPos(_lightPos);
	//	yun->setPositionY(_cameraHeight + (VISIBLE_SIZE.height - 230));
//	}
	//else {
		
	//	_lightPos.set(this->getChildByTag(2001)->getPositionX(), this->getChildByTag(2001)->getPositionY(), 400);
	//	_effect->setLightPos(_lightPos);

	//}
}
//判断player filter
void BlocksLayer::Bupdata8(float dt){
	b2Vec2 v = body_P->GetLinearVelocity();
	if (v.y > 0.0f){
		b2Filter filter1 = body_P->GetFixtureList()->GetFilterData();
		filter1.maskBits = 0x0001;
		body_P->GetFixtureList()->SetFilterData(filter1);
		//b2Filter filter2 = head->GetFixtureList()->GetFilterData();
		//filter2.maskBits = 0x0002;
		//head->GetFixtureList()->SetFilterData(filter2);
	}
	else if (v.y < 0.0f){
		b2Filter filter = body_P->GetFixtureList()->GetFilterData();
		filter.maskBits = 0x0002;
		body_P->GetFixtureList()->SetFilterData(filter);
	//	b2Filter filter2 = head->GetFixtureList()->GetFilterData();
		//filter2.maskBits = 0x0001;
		//head->GetFixtureList()->SetFilterData(filter2);
	}
	
	
}
//结束block粒子动画&移除星星云
void BlocksLayer::Bupdata4(float dt){
	//移除星星云
	if (_colorDotCnt > 1){
		this->getChildByTag(200 + _colorDotCnt - 1)->runAction(CCEaseExponentialOut::create(CCMoveBy::create(1.5, ccp(0, VISIBLE_SIZE .height*70/144))));
		_colorDotCnt--;

	}
/*	else if (_colorDotCnt == 1){
		yun->runAction(CCEaseExponentialOut::create(CCMoveBy::create(2, ccp(0, 2200))));
		_colorDotCnt--;
	}
*/	
/*	//粒子效果移除Block
	auto iter = Sprite_.begin();

	if ((*iter)->getPositionY() < _cameraHeight + VISIBLE_SIZE.height){

		(*iter)->setOpacity(0);

		//读取粒子效果
		ParticleSystem* m_emitter1 = ParticleSystemQuad::create("block_lz.plist");
		ParticleBatchNode *batch = ParticleBatchNode::createWithTexture(m_emitter1->getTexture());
		if ((*iter)->Filename == "bl1.png"){
			m_emitter1->setStartColor(Color4F(0.6513, 0.6825, 0.6981, 0.5421));
			m_emitter1->setEndColor(Color4F(0.6513, 0.6825, 0.6981, 0.5421));
		}

		else if ((*iter)->Filename == "bl2.png"){
			m_emitter1->setStartColor(Color4F(0.9945, 0.3978, 0.1989, 0.5421));
			m_emitter1->setEndColor(Color4F(0.9945, 0.3978, 0.1989, 0.5421));
		}
		else if ((*iter)->Filename == "bl3.png"){
			m_emitter1->setStartColor(Color4F(0.9945, 0.5967, 0.5967, 0.5421));
			m_emitter1->setEndColor(Color4F(0.9945, 0.5967, 0.5967, 0.5421));
		}
		else if ((*iter)->Filename == "bl4.png"){
			m_emitter1->setStartColor(Color4F(0.3744, 0.3822, 0.4992, 0.5421));
			m_emitter1->setEndColor(Color4F(0.3744, 0.3822, 0.4992, 0.5421));
		}
		else if ((*iter)->Filename == "bl5.png"){
			m_emitter1->setStartColor(Color4F(0.9438, 0.2872, 0.3315, 0.5421));
			m_emitter1->setEndColor(Color4F(0.9438, 0.2872, 0.3315, 0.5421));
		}
		else if ((*iter)->Filename == "bl6.png"){
			m_emitter1->setStartColor(Color4F(0.5655, 0.2223, 0.5967, 0.5421));
			m_emitter1->setEndColor(Color4F(0.5655, 0.2223, 0.5967, 0.5421));
		}
		else if ((*iter)->Filename == "bl7.png"){
			m_emitter1->setStartColor(Color4F(0.0, 0.7956, 0.3978, 0.5421));
			m_emitter1->setEndColor(Color4F(0.0, 0.7956, 0.3978, 0.5421));
		}
		else if ((*iter)->Filename == "bl8.png"){
			m_emitter1->setStartColor(Color4F(0.9945, 0.9945, 0.7956, 0.5421));
			m_emitter1->setEndColor(Color4F(0.9945, 0.9945, 0.7956, 0.5421));
		}
		else if ((*iter)->Filename == "bl9.png"){
			m_emitter1->setStartColor(Color4F(0.1989, 0.7956, 0.7956, 0.5421));
			m_emitter1->setEndColor(Color4F(0.1989, 0.7956, 0.7956, 0.5421));
		}
		else if ((*iter)->Filename == "bl10.png"){
			m_emitter1->setStartColor(Color4F(0.9945, 0.7956, 0.1989, 0.5421));
			m_emitter1->setEndColor(Color4F(0.9945, 0.7956, 0.1989, 0.5421));
		}
		else if ((*iter)->Filename == "bl11.png"){
			m_emitter1->setStartColor(Color4F(0.7371, 0.4524, 0.2028, 0.5421));
			m_emitter1->setEndColor(Color4F(0.7371, 0.4524, 0.2028, 0.5421));
		}

		//m_emitter1->setEndColor(Color4F(0, 0, 0, 139));
		m_emitter1->retain();
		batch->addChild(m_emitter1);
		batch->setPosition((*iter)->getPosition());
		batch->setCameraMask(2);
		this->addChild(batch, 10);
		m_emitter1->release();
		this->removeChild((*iter));
		iter = Sprite_.erase(Sprite_.begin());c
		
	}

	*/




}
//检测有几个颜色&并增加0.1
void BlocksLayer::Bupdata5(float dt)
{
	if (_cameraHeight + height / 2 > 72000)
	{
		if (isLastBl){
			this->removeChildByTag(5002);
			this->removeChildByTag(5003);
			isLastBl = false; AddColorDot(this->_filesNames[9]); jishu++;
			//world->SetContactListener(false);
			CCSprite *sp = CCSprite::createWithSpriteFrameName("home.png");
			//Sprite * sp = Sprite::create("home.png");
			auto continueGame = cocos2d::CCMenuItemSprite::create(sp, sp, CC_CALLBACK_0(BlocksLayer::finalCallback, this, NULL));
			auto continueMenu = CCMenu::create(continueGame, NULL);
			continueMenu->setPosition(ccp(1210, PLAYER_HIGT));
			this->addChild(continueMenu);
			continueMenu->runAction(CCEaseElasticOut::create(CCMoveBy::create(1.3, ccp(-480, 0))));
			GameLayer * G = (GameLayer*)this->getParent();
			G->unsch2();
			auto call_loadMoon = CallFunc::create([this](){
				CCSprite *sp = CCSprite::createWithSpriteFrameName("loadMoon.png");
				sp->setPosition(480,-400);
				this->addChild(sp,200);
				sp->runAction(MoveBy::create(15,ccp(0,height+1000)));

			});
			G->camera->runAction(Sequence::create(CCEaseExponentialOut::create(CCMoveBy::create(5, ccp(0, 72000 - (_cameraHeight - 240)))), call_loadMoon, nullptr));
			finalGame();
	}
	}
	else if (_cameraHeight + height / 2 >64000)
	{
		if (isLastBl){
			this->removeChildByTag(5002);
			this->removeChildByTag(5003);
			isLastBl = false; AddColorDot(this->_filesNames[8]); jishu++;
			//world->SetContactListener(false);
			
			this->removeChildByTag(558);
			wen = CCSprite::createWithSpriteFrameName(setSpriteFile());
			//wen = Sprite::create(setSpriteFile());
			auto wenGame = cocos2d::CCMenuItemSprite::create(wen, wen, CC_CALLBACK_0(BlocksLayer::wenCallback, this, NULL));
			auto wenMenu = CCMenu::create(wenGame, NULL);
			wenMenu->setPosition(ccp(1210, PLAYER_HIGT + 290));
			wenMenu->setTag(558);
			this->addChild(wenMenu);
			wenMenu->runAction(CCEaseElasticOut::create(CCMoveBy::create(1, ccp(-480, 0))));
			this->getChildByTag(559)->runAction(CCEaseElasticOut::create(CCMoveBy::create(1.3, ccp(-480, 0))));
				GameLayer * G = (GameLayer*)this->getParent();
				G->camera->runAction(CCEaseExponentialOut::create(CCMoveBy::create(5, ccp(0, 64000 - (_cameraHeight + 240)))));
			
		}
	}
	else if (_cameraHeight + height / 2 >56000)
	{
		if (isLastBl){
			this->removeChildByTag(5002);
			this->removeChildByTag(5003);
			isLastBl = false; AddColorDot(this->_filesNames[7]); jishu++;
			//world->SetContactListener(false);
			
			this->removeChildByTag(558);
			wen = CCSprite::createWithSpriteFrameName(setSpriteFile());
			//wen = Sprite::create(setSpriteFile());
			auto wenGame = cocos2d::CCMenuItemSprite::create(wen, wen, CC_CALLBACK_0(BlocksLayer::wenCallback, this, NULL));
			auto wenMenu = CCMenu::create(wenGame, NULL);
			wenMenu->setPosition(ccp(1210, PLAYER_HIGT + 290));
			wenMenu->setTag(558);
			this->addChild(wenMenu);
			wenMenu->runAction(CCEaseElasticOut::create(CCMoveBy::create(1, ccp(-480, 0))));
			this->getChildByTag(559)->runAction(CCEaseElasticOut::create(CCMoveBy::create(1.3, ccp(-480, 0))));
				GameLayer * G = (GameLayer*)this->getParent();
				G->camera->runAction(CCEaseExponentialOut::create(CCMoveBy::create(5, ccp(0, 56000 - (_cameraHeight + 240)))));
					}
	}
	else if (_cameraHeight + height / 2 >48000)
	{
		if (isLastBl){
			this->removeChildByTag(5002);
			this->removeChildByTag(5003);
			isLastBl = false; AddColorDot(this->_filesNames[6]); jishu++;
			//world->SetContactListener(false);
			
			this->removeChildByTag(558);
			wen = CCSprite::createWithSpriteFrameName(setSpriteFile());
			//wen = Sprite::create(setSpriteFile());
			auto wenGame = cocos2d::CCMenuItemSprite::create(wen, wen, CC_CALLBACK_0(BlocksLayer::wenCallback, this, NULL));
			auto wenMenu = CCMenu::create(wenGame, NULL);
			wenMenu->setPosition(ccp(1210, PLAYER_HIGT + 290));
			wenMenu->setTag(558);
			this->addChild(wenMenu);
			wenMenu->runAction(CCEaseElasticOut::create(CCMoveBy::create(1, ccp(-480, 0))));
			this->getChildByTag(559)->runAction(CCEaseElasticOut::create(CCMoveBy::create(1.3, ccp(-480, 0))));
			GameLayer * G = (GameLayer*)this->getParent();
			G->camera->runAction(CCEaseExponentialOut::create(CCMoveBy::create(5, ccp(0, 48000 - (_cameraHeight + 240)))));
					}
	}
	else if (_cameraHeight + height / 2 >40000)
	{
		if (isLastBl){
			this->removeChildByTag(5002);
			this->removeChildByTag(5003);
			isLastBl = false; AddColorDot(this->_filesNames[5]); jishu++;
			//world->SetContactListener(false);
		
			this->removeChildByTag(558);
			wen = CCSprite::createWithSpriteFrameName(setSpriteFile());
			//wen = Sprite::create(setSpriteFile());
			auto wenGame = cocos2d::CCMenuItemSprite::create(wen, wen, CC_CALLBACK_0(BlocksLayer::wenCallback, this, NULL));
			auto wenMenu = CCMenu::create(wenGame, NULL);
			wenMenu->setPosition(ccp(1210, PLAYER_HIGT + 290));
			wenMenu->setTag(558);
			this->addChild(wenMenu);
			wenMenu->runAction(CCEaseElasticOut::create(CCMoveBy::create(1, ccp(-480, 0))));
			this->getChildByTag(559)->runAction(CCEaseElasticOut::create(CCMoveBy::create(1.3, ccp(-480, 0))));
				GameLayer * G = (GameLayer*)this->getParent();
				G->camera->runAction(CCEaseExponentialOut::create(CCMoveBy::create(5, ccp(0, 40000 - (_cameraHeight + 240)))));
				
		}
	}
	else if (_cameraHeight + height / 2 > 32000)
	{
		if (isLastBl){
			this->removeChildByTag(5002);
			this->removeChildByTag(5003);
			isLastBl = false; AddColorDot(this->_filesNames[4]); jishu++;
			this->removeChildByTag(558);
			wen = CCSprite::createWithSpriteFrameName(setSpriteFile());
			//wen = Sprite::create(setSpriteFile());
			auto wenGame = cocos2d::CCMenuItemSprite::create(wen, wen, CC_CALLBACK_0(BlocksLayer::wenCallback, this, NULL));
			auto wenMenu = CCMenu::create(wenGame, NULL);
			wenMenu->setPosition(ccp(1210, PLAYER_HIGT + 290));
			wenMenu->setTag(558);
			this->addChild(wenMenu);
			wenMenu->runAction(CCEaseElasticOut::create(CCMoveBy::create(1, ccp(-480, 0))));
			this->getChildByTag(559)->runAction(CCEaseElasticOut::create(CCMoveBy::create(1.3, ccp(-480, 0))));
				GameLayer * G = (GameLayer*)this->getParent();
				G->camera->runAction(CCEaseExponentialOut::create(CCMoveBy::create(5, ccp(0, 32000 - (_cameraHeight + 240)))));
			
		}
	}
	else if (_cameraHeight + height / 2 > 24000)
	{
		if (isLastBl){
			this->removeChildByTag(5002);
			this->removeChildByTag(5003);
			isLastBl = false; AddColorDot(this->_filesNames[3]); jishu++;
			this->removeChildByTag(558);
			wen = CCSprite::createWithSpriteFrameName(setSpriteFile());
			//wen = Sprite::create(setSpriteFile());
			auto wenGame = cocos2d::CCMenuItemSprite::create(wen, wen, CC_CALLBACK_0(BlocksLayer::wenCallback, this, NULL));
			auto wenMenu = CCMenu::create(wenGame, NULL);
			wenMenu->setPosition(ccp(1210, PLAYER_HIGT + 290));
			wenMenu->setTag(558);
			this->addChild(wenMenu);
			wenMenu->runAction(CCEaseElasticOut::create(CCMoveBy::create(1, ccp(-480, 0))));
			this->getChildByTag(559)->runAction(CCEaseElasticOut::create(CCMoveBy::create(1.3, ccp(-480, 0))));
				GameLayer * G = (GameLayer*)this->getParent();
				G->camera->runAction(CCEaseExponentialOut::create(CCMoveBy::create(5, ccp(0, 24000 - (_cameraHeight + 240)))));
			
		}
	}
	else if (_cameraHeight + height / 2 >16000)
	{
		if (isLastBl){
			this->removeChildByTag(5002);
			this->removeChildByTag(5003);
			isLastBl = false; AddColorDot(this->_filesNames[2]); jishu++;
			//world->SetContactListener(false);
			this->removeChildByTag(558);
			wen = CCSprite::createWithSpriteFrameName(setSpriteFile());
			//wen = Sprite::create(setSpriteFile());
			auto wenGame = cocos2d::CCMenuItemSprite::create(wen, wen, CC_CALLBACK_0(BlocksLayer::wenCallback, this, NULL));
			auto wenMenu = CCMenu::create(wenGame, NULL);
			wenMenu->setPosition(ccp(1210, PLAYER_HIGT + 290));
			wenMenu->setTag(558);
			this->addChild(wenMenu);
			wenMenu->runAction(CCEaseElasticOut::create(CCMoveBy::create(1, ccp(-480, 0))));
			this->getChildByTag(559)->runAction(CCEaseElasticOut::create(CCMoveBy::create(1.3, ccp(-480, 0))));
				GameLayer * G = (GameLayer*)this->getParent();
				G->camera->runAction(CCEaseExponentialOut::create(CCMoveBy::create(5, ccp(0, 16000 - (_cameraHeight + 240)))));
			}
		
	}
	else if (_cameraHeight + height / 2 > 8000)
	{
		
		if (isLastBl){
			isLastBl = false; AddColorDot(this->_filesNames[1]); jishu++;
			//world->SetContactListener(false);
			this->removeChildByTag(5001);
			this->removeChildByTag(801);
			this->removeChildByTag(1071);
			this->removeChildByTag(1072);
			CCSprite *sp = CCSprite::createWithSpriteFrameName("jixu.png");
			//	Sprite * sp = Sprite::create("jixu.png");
				auto continueGame = cocos2d::CCMenuItemSprite::create(sp, sp, CC_CALLBACK_0(BlocksLayer::continueCallback, this, NULL));
				auto continueMenu = CCMenu::create(continueGame, NULL);
				continueMenu->setPosition(ccp(1210, PLAYER_HIGT + 120));
				continueMenu->setTag(559);
				this->addChild(continueMenu);
				continueMenu->runAction(CCEaseElasticOut::create(CCMoveBy::create(1.3, ccp(-480, 0))));
				wen = CCSprite::createWithSpriteFrameName(setSpriteFile());
				//wen = Sprite::create(setSpriteFile());
				auto wenGame = cocos2d::CCMenuItemSprite::create(wen, wen, CC_CALLBACK_0(BlocksLayer::wenCallback, this, NULL));
				auto wenMenu = CCMenu::create(wenGame, NULL);
				wenMenu->setPosition(ccp(1210, PLAYER_HIGT + 290));
				wenMenu->setTag(558);
				this->addChild(wenMenu);
				wenMenu->runAction(CCEaseElasticOut::create(CCMoveBy::create(1, ccp(-480, 0))));
				GameLayer * G = (GameLayer*)this->getParent();
				G->camera->runAction(CCEaseExponentialOut::create(CCMoveBy::create(5, ccp(0, 8000 - (_cameraHeight + 240)))));
				
				
		}
	}
	else
	{
		if (Gs0 == true){ Gs0 = false; AddColorDot(this->_filesNames[0]); jishu++; }
	}


}
//fireMove
void BlocksLayer::Bupdata9(float dt)
{
	INIT_RANDOM_ENGINE;
	int sign = int(1 + (rand()) % 3);
	if (sign == 1){ body_fire1->ApplyForce(b2Vec2(-2 + (rand()) % 2, -2 + (rand()) % 2), body_fire1->GetWorldCenter(), false); }
	else if (sign == 2){ body_fire2->ApplyForce(b2Vec2(-2 + (rand()) % 2, -2 + (rand()) % 2), body_fire2->GetWorldCenter(), false); }
	else{ body_fire3->ApplyForce(b2Vec2(-2 + (rand()) % 2, -2 + (rand()) % 2), body_fire3->GetWorldCenter(), false); }
	/*if (fire_sign1){
		
		fire_sign1 = false;
		auto call1 = CallFunc::create([this](){
		
			fire_sign1 = true;
		});
		//CCActionInterval * repeatForever = CCRepeatForever::create(fireAction());
		this->getChildByTag(2001)->getChildByTag(3001)->runAction(Sequence::create(fireAction(), call1, nullptr));
	}

	if (fire_sign2){

		fire_sign2 = false;
		auto call1 = CallFunc::create([this](){

			fire_sign2 = true;
		});
		//CCActionInterval * repeatForever = CCRepeatForever::create(fireAction());
		this->getChildByTag(2001)->getChildByTag(3002)->runAction(Sequence::create(fireAction(), call1, nullptr));
	}
	if (fire_sign3){

		fire_sign3 = false;
		auto call1 = CallFunc::create([this](){

			fire_sign3 = true;
		});
		//CCActionInterval * repeatForever = CCRepeatForever::create(fireAction());
		this->getChildByTag(2001)->getChildByTag(3003)->runAction(Sequence::create(fireAction(), call1, nullptr));
	}
	*/
	
	
	
}
//摇动xx灯泡
void BlocksLayer::Bupdata10(float dt)
{
	//body_P->SetLinearVelocity(b2Vec2(0, 100));
	int a = 0;
	for (auto iter = xings.begin(); iter != xings.end(); iter++)
	{
		
		(*iter)->ApplyForce(b2Vec2(10, 0), (*iter)->GetWorldCenter(), true);

	}
	dengpaoMove->ApplyForce(b2Vec2(100, 0), dengpaoMove->GetWorldCenter(), true);
	
}
//黑洞
void BlocksLayer::Bupdata11(float dt){
	//float radius = 400;480 350
	//b2Vec2 plantsPos = b2Vec2(400 / PTM_RATIO, 500 / PTM_RATIO);
	if (((Player::sharePlayer()->getPositionY()) > 8000 * (sign_ZA[5]))){ this->unschedule(schedule_selector(BlocksLayer::Bupdata11)); }
	b2Vec2 distance = b2Vec2(0, 0);
	b2Vec2 playerPos = body_P->GetWorldCenter();
	//if (holl.begin()->y*PTM_RATIO < _cameraHeight){
	//	holl.erase(holl.begin());
	//}
	for (auto iter = holl.begin(); iter != holl.end(); iter++){
		distance = (*iter) - playerPos;
		float finalDis = distance.Length();
		if (finalDis*PTM_RATIO<900){
			float sum = (abs(distance.x) + abs(distance.y));
			distance = b2Vec2(distance.x*((1 / sum) * 2 / finalDis) / 10, distance.y*((1 / sum) * 2 / finalDis) / 10);
			body_P->ApplyForce(distance, body_P->GetWorldCenter(), true);

		}
	}
	
}
//柱子
void BlocksLayer::Bupdata12(float dt){
	//float radius = 400;480 350
	//b2Vec2 plantsPos = b2Vec2(400 / PTM_RATIO, 500 / PTM_RATIO);
	/*b2Vec2 distance = b2Vec2(0, 0);
	b2Vec2 playerPos = shengTi->GetWorldCenter();
	Sprite * sp;
	if (boom_Sign)
	{
		sp = (Sprite*)this->getChildByTag(3331);
		boom_Sign = false;
	}
	else
	{
		sp = (Sprite*)this->getChildByTag(3332);
		boom_Sign = true;
	}
	distance = playerPos - b2Vec2(sp->getPositionX() / PTM_RATIO, sp->getPositionY() / PTM_RATIO);
		float finalDis = distance.Length();
		if (finalDis*PTM_RATIO<200){
			float sum = (abs(distance.x) + abs(distance.y));
			distance = b2Vec2(distance.x*((1 / sum) * 2 / finalDis) / 15, distance.y*((1 / sum) * 2 / finalDis) / 15);
			shengTi->ApplyLinearImpulse(distance, shengTi->GetWorldCenter(), true);
			//sp->setOpacity(0);
			sp->setPosition((rand() % (int)VISIBLE_SIZE.width), _cameraHeight + VISIBLE_SIZE.height);
		}
		*/
	
//	if (zhuzi > 2){}
	//else{
	//	if (this->getChildByTag(444)->getPositionY() + 1400 < _cameraHeight){ this->getChildByTag(444)->setPositionY(8000 * (sign_ZA[6] - 1) + (++zhuzi) * 1400); }
	//	if (this->getChildByTag(445)->getPositionY() + 1400 < _cameraHeight){ this->getChildByTag(445)->setPositionY(8000 * (sign_ZA[6] - 1) + (++zhuzi) * 1400); }
	//}
	if (this->getChildByTag(444)->getPositionY()<_cameraHeight){ this->getChildByTag(444)->setCameraMask(3); this->getChildByTag(444)->setPositionY(0); }
	if (_cameraHeight + (height)>8000 * sign_ZA[6]){ this->getChildByTag(444)->setCameraMask(2); this->getChildByTag(444)->setPositionY(8000 * sign_ZA[6] - (height)); }

	
	if (body_P->GetPosition().y*PTM_RATIO> this->getChildByTag(444)->getPositionY() && body_P->GetPosition().y*PTM_RATIO<8000 * (sign_ZA[6]))
	if (body_P->GetPosition().x*PTM_RATIO<480 && body_P->GetPosition().x*PTM_RATIO>400){ body_P->SetTransform(b2Vec2(400/PTM_RATIO,body_P->GetPosition().y-0.3),0); }
	else if (body_P->GetPosition().x*PTM_RATIO>480 && body_P->GetPosition().x*PTM_RATIO<560){ body_P->SetTransform(b2Vec2(560 / PTM_RATIO, body_P->GetPosition().y - 0.3), 0); }
	
	if (((_cameraHeight) > 8000 * (sign_ZA[6]))){ this->unschedule(schedule_selector(BlocksLayer::Bupdata12)); this->removeChildByTag(444); }
}


void BlocksLayer::draw(Renderer *renderer, const Mat4& transform, uint32_t flags){
	///world->DrawDebugData();
	GL::enableVertexAttribs(cocos2d::GL::VERTEX_ATTRIB_FLAG_POSITION);

	world->DrawDebugData();

	CHECK_GL_ERROR_DEBUG();
}



void BlocksLayer::BeginContact(b2Contact* contact)
{
	bool sign = false;
	//BlocksLayer::PreSolve(contact, oldManifold);
	b2Body* bodyA = contact->GetFixtureA()->GetBody();
	b2Body* bodyB = contact->GetFixtureB()->GetBody();
	b2Vec2 positionB;
	//shengTi->ApplyLinearImpulse(b2Vec2(0, 50), shengTi->GetWorldCenter(), true);
	//if (bodyA == head || bodyB == head){}
	//else{
	b2Body* block;
	//b2Body* player;
	if (bodyA == body_P)
	{
		positionB = bodyB->GetPosition();
		block = bodyB;
	//	player = bodyA;
	}
	else
	{
		positionB = bodyA->GetPosition();
		block = bodyA;
	//	player = bodyB;
	}
	//每到最后一个重力感应无效
	//isLastBl = false; 
	
		Block* block_S = (Block*)(block->GetUserData());
		b2Vec2 position = body_P->GetPosition();
		float Rt = block_S->getRotation();
		float x = 65 * tan(CC_DEGREES_TO_RADIANS(Rt));
		if (position.y + 1.5 / PTM_RATIO< positionB.y + 3 / PTM_RATIO)
		{
			sign = true;
		}


		if (!sign){
			if ((int)(positionB.y*PTM_RATIO) % 8000 == 0){
				if ((int)(positionB.y*PTM_RATIO) == 8000 * (sign_ZA[7])){
					touch_sign2 = false;
				}
				//重力感应
				Device::setAccelerometerEnabled(false);

			//	zhongliganying = 0;
				//开始播放背景音效，false表示不循环
				SimpleAudioEngine::sharedEngine()->playEffect("lastM.wav", false);
			
				this->unschedule(schedule_selector(BlocksLayer::Bupdata8));
				//设置filter解决body删除问题
				b2Filter filter = block->GetFixtureList()->GetFilterData();
				filter.maskBits = 0x0002;
				block->GetFixtureList()->SetFilterData(filter);

				unscheduleUpdate();
				isLastBl = true;
				//if ((int)(positionB.y*PTM_RATIO) == 8000){ finalGame(); }

				sign_ZLGY = 1;
				//取消反重力感应
				if ((positionB.y*PTM_RATIO / 8000) == (sign_ZA[8] - 1)){ sign_ZLGY = -1; }
				//取消缓冲
				if ((positionB.y*PTM_RATIO / 8000) == (sign_ZA[7])){ huanchong_sign2 = false; }
				
			}
			else{
				//Gs1 = true;
			if (huanchong_sign2){
				//缓冲
				if (body_P->GetLinearVelocity().y<-28){}
				else{
					body_P->SetLinearVelocity(b2Vec2(0, 60));
					//shengTi->SetLinearVelocity(b2Vec2(0, 60));
					//hand1->SetLinearVelocity(b2Vec2(0, 50));
					//hand3->SetLinearVelocity(b2Vec2(0, 50));
					SimpleAudioEngine::sharedEngine()->playEffect("tiaoyueM.wav", false);
				//	hand2->SetLinearVelocity(b2Vec2(0, 55));
				//	hand4->SetLinearVelocity(b2Vec2(0, 55));
					//保证touchOnce
					touch_sign = true;
				}

			}
			else{
				body_P->SetLinearVelocity(b2Vec2(x, 60));
				//shengTi->SetLinearVelocity(b2Vec2(x, 60));
				//hand1->SetLinearVelocity(b2Vec2(x, 50));
				//hand3->SetLinearVelocity(b2Vec2(x, 50));
				SimpleAudioEngine::sharedEngine()->playEffect("tiaoyueM.wav", false);
			//	hand2->SetLinearVelocity(b2Vec2(x, 55));
				//hand4->SetLinearVelocity(b2Vec2(x, 55));
			}

			

				//设置filter解决body删除问题
				b2Filter filter = block->GetFixtureList()->GetFilterData();
				filter.maskBits = 0x0002;
				block->GetFixtureList()->SetFilterData(filter);
				//lizi
				Block* sp = (Block *)block->GetUserData();
			
				if (!effect){ sp->setPosition(-100, -100); }
				else
				{
					ParticleSystem* m_emitter1 = ParticleSystemQuad::create("block_lz1.plist");
					m_emitter1->retain();
					m_emitter1->setAutoRemoveOnFinish(true);
					ParticleBatchNode *batch = ParticleBatchNode::createWithTexture(m_emitter1->getTexture());
					m_emitter1->setStartColor(Color4F(sp->c));
					m_emitter1->setEndColor(Color4F(sp->c));
					batch->addChild(m_emitter1);
					batch->setPosition(sp->getPosition());
					batch->setRotation(sp->getRotation());
					batch->setCameraMask(2);
					addChild(batch, 10);
					m_emitter1->release();
					sp->setPosition(-100, -100);
				}
					
				

			

			//}
		}
	}
	
}


void BlocksLayer::EndContact(b2Contact* contact)
{
	
	
}


void BlocksLayer::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	
	
}


void BlocksLayer::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
	
}

//重力感应回掉
void BlocksLayer::didAccelerate(CCAcceleration* pAccelerationValue, Event* event)
{
	zhongliganying = pAccelerationValue->x;
}

bool BlocksLayer::touchBegin(CCTouch * touch, CCEvent *event){
	if (touch_sign2)
	if (touch_sign){
		touch_sign = false;
		SimpleAudioEngine::sharedEngine()->playEffect("chuxingxingM.wav", false);
		body_P->ApplyForce(b2Vec2(0, 1.1), body_P->GetWorldCenter(), true);
	}
	
	return true;
}


//增加颜色标识&结束时储存设置分数-在GameLayer调用
int BlocksLayer::getJIshu(){
	return jishu;
}
void BlocksLayer::AddColorDot(std::string fileName)
{
	INIT_RANDOM_ENGINE;
	SimpleAudioEngine::sharedEngine()->playEffect("chuxingxingM.wav", false);
	Sprite *colorDotSprite;
	//CCSprite *xian = CCSprite::createWithSpriteFrameName("xian.png");
	CCSprite * xian = CCSprite::create("xian.png", CCRectMake(0, 0, 3, 700));
	
	if (fileName == "bl1.png"){
		colorDotSprite = CCSprite::createWithSpriteFrameName("XINGXING1.png");
		//colorDotSprite = EffectSprite::create("XINGXING1.png");
	}

	else if (fileName == "bl2.png"){
		colorDotSprite = CCSprite::createWithSpriteFrameName("XINGXING2.png");
	}
	else if (fileName == "bl3.png"){
		colorDotSprite = CCSprite::createWithSpriteFrameName("XINGXING3.png");
	}
	else if (fileName == "bl4.png"){
		colorDotSprite = CCSprite::createWithSpriteFrameName("XINGXING4.png");
	}
	else if (fileName == "bl5.png"){
		colorDotSprite = CCSprite::createWithSpriteFrameName("XINGXING5.png");
	}
	else if (fileName == "bl6.png"){
		colorDotSprite = CCSprite::createWithSpriteFrameName("XINGXING6.png");
	}
	else if (fileName == "bl7.png"){
		colorDotSprite = CCSprite::createWithSpriteFrameName("XINGXING7.png");
	}
	else if (fileName == "bl8.png"){
		colorDotSprite = CCSprite::createWithSpriteFrameName("XINGXING8.png");
	}
	else if (fileName == "bl9.png"){
		colorDotSprite = CCSprite::createWithSpriteFrameName("XINGXING9.png");
	}
	else if (fileName == "bl10.png"){
		colorDotSprite = CCSprite::createWithSpriteFrameName("XINGXING10.png");
	}
	else if (fileName == "bl11.png"){
		colorDotSprite = CCSprite::createWithSpriteFrameName("XINGXING11.png");
	}

	//colorDotSprite->setEffect(_effect, "XINGXING4_n.png");
	xian->setAnchorPoint(ccp(0, 0));
	xian->addChild(colorDotSprite);
	colorDotSprite->setPosition(ccp(0,0));
	xian->setTag(200 + _colorDotCnt);
	this->addChild(xian,3);
	//this->getChildByTag(701)->addChild(xian);
	//xian->setCameraMask(2);
	//auto size = colorDotSprite->getContentSize();
	//colorDotSprite->setColor(color);
	Point pt, movePt;
	float moveY = mf::rn(height*0.19, height*0.41);
	xianHeight[_colorDotCnt] = moveY;
	//log("%d", _colorDotCnt);
	if (_colorDotCnt == 1){
		pt = ccp(width / 2 - 50, height);
	}
	else{
		if (_colorDotCnt % 2 == 0){
			if (_colorDotCnt == 2){
				while (true){
					moveY = mf::rn(height*0.19, height*0.41);
					if (abs(moveY - (height - this->getChildByTag(200 + _colorDotCnt - 1)->getPositionY())) < 100){}
					else{ break; }
				}

				pt = ccp(this->getChildByTag(200 + _colorDotCnt - 1)->getPositionX() + 80, height);

			}
			else
			{
				while (true){
					moveY = mf::rn(height*0.19, height*0.41);

					if (abs(moveY - (height - this->getChildByTag(200 + _colorDotCnt - 2)->getPositionY())) < 100){}
					else{ break; }
				}
				pt = ccp(this->getChildByTag(200 + _colorDotCnt - 2)->getPositionX() + 80, height);
			}

		}
		else{
			while (true){
				moveY = mf::rn(height*0.19, height*0.41);
				if (abs(moveY - (height - this->getChildByTag(200 + _colorDotCnt - 2)->getPositionY())) < 100){}
				else{ break; }
			}
			pt = ccp(this->getChildByTag(200 + _colorDotCnt - 2)->getPositionX() - 80, height);
		}
	}
	/*if (_colorDotCnt < 5) {
	pt = ccp(VISIBLE_SIZE.width + size.width, VISIBLE_SIZE.height - 250);
	if (_colorDotCnt == 0) {
	movePt = ccp(VISIBLE_SIZE.width / 2, pt.y);
	}
	else {
	for (int i = 0; i < _colorDotCnt; i++) {
	auto preDotSprite = this->getChildByTag(200 + i);
	auto preMove = CCMoveBy::create(0.8, ccp(-(size.width / 2), 0));
	auto easeElasticOut = CCEaseElasticOut::create(preMove);
	preDotSprite->runAction(easeElasticOut);
	if (i == _colorDotCnt - 1) {
	movePt = ccp((preDotSprite->getPosition().x + size.width / 2), pt.y);
	}
	}
	}
	}
	else {
	pt = ccp(VISIBLE_SIZE.width + size.width, VISIBLE_SIZE.height - 250 - 20 - size.height);
	if (_colorDotCnt == 5) {
	movePt = ccp(VISIBLE_SIZE.width / 2, pt.y);
	}
	else {
	for (int i = 5; i < _colorDotCnt; i++) {
	auto preDotSprite = this->getChildByTag(200 + i);
	auto preMove = CCMoveBy::create(0.8, ccp(-(size.width / 2), 0));
	auto easeElasticOut = CCEaseElasticOut::create(preMove);
	preDotSprite->runAction(easeElasticOut);
	if (i == _colorDotCnt - 1) {
	movePt = ccp((preDotSprite->getPosition().x + size.width / 2), pt.y);
	}
	}
	}
	}*/
	colorDotSprite->setScale(mf::rn(9,12)/10);
	//this->addChild(xian);

	xian->setPosition(pt);
	auto moveAction = CCMoveBy::create(2, ccp(0, -moveY));
	auto easeElasticOut = CCEaseElasticOut::create(moveAction);
	xian->runAction(easeElasticOut);
	_colorDotCnt++;
}

//在GameLayer中调用
void BlocksLayer::createOcenion(){
	if (!effect){}
	else
	{
		CCSprite* spLand = CCSprite::createWithSpriteFrameName("landLight.png");
		//auto spLand = Sprite::create("landLight.png");
		spLand->setPosition(480, 85);
		spLand->setCameraMask(2);
		spLand->setTag(1072);
		addChild(spLand);
		ParticleSystem* m_emitterLand = ParticleSystemQuad::create("landlz.plist");
		m_emitterLand->retain();
		m_emitterLand->setAutoRemoveOnFinish(true);
		ParticleBatchNode *batchLand = ParticleBatchNode::createWithTexture(m_emitterLand->getTexture());
		batchLand->addChild(m_emitterLand);
		batchLand->setPosition(480, 40);
		batchLand->setCameraMask(2);
		batchLand->setTag(5001);
		addChild(batchLand);
		m_emitterLand->release();

		CCSpriteBatchNode* spritebatch = CCSpriteBatchNode::create("grass.png");
		CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
		cache->addSpriteFramesWithFile("grass.plist");
		auto m_pSprite1 = CCSprite::createWithSpriteFrameName("0.png");
		m_pSprite1->setPosition(900, 170);
		spritebatch->addChild(m_pSprite1);
		spritebatch->setTag(1071);
		addChild(spritebatch);
		Vector<SpriteFrame*> frames;
		for (int i = 1; i < 34; i++)
		{
			if (i == 1 || i == 12){}
			else{
				char str[100] = { 0 };
				sprintf(str, "%d.png", i);
				frames.pushBack(cache->getSpriteFrameByName(str));
			}

		}
		auto animation1 = Animation::createWithSpriteFrames(frames, 0.1f);
		Animate* ani = Animate::create(animation1);
		m_pSprite1->runAction(RepeatForever::create(Sequence::create(ani, ani->reverse(), nullptr)));
	}

	CCSprite* sp = CCSprite::createWithSpriteFrameName("erth.png");
	sp->setAnchorPoint(ccp(0,0));
	sp->setPosition(ccp(0, 0 ));
	sp->setTag(801);
	this->addChild(sp,101);

	
	

	
	//地板
	CCSprite *bottomBordersp = CCSprite::createWithSpriteFrameName("void1.png");
	//auto bottomBordersp = Sprite::create("void1.png");
	bottomBordersp->setPosition(480,45);
	this->addChild(bottomBordersp);
	b2BodyDef bodyDef1;
	bodyDef1.type = b2_staticBody; //物体的类型，不动的，坚硬的~ 可以把这样的物体当成地面  
	b2PolygonShape borderShape1; // 一个方形的形状  
	b2FixtureDef borderFixture1; // 一个定制器  
	borderFixture1.filter.categoryBits = 0x0002;
	//bodyDef1.userData = sp;
	//定义地板  
//	bodyDef1.position.Set(480 / PTM_RATIO, 660 / PTM_RATIO); // 地板在0，0位置  
	borderShape1.SetAsBox(100 / PTM_RATIO, 10 / PTM_RATIO); //设置长度和高度，这里描述的地板就像是X轴，是一条线  
	borderFixture1.shape = &borderShape1;
	bodyDef1.userData = bottomBordersp;
	 bottomBorder = world->CreateBody(&bodyDef1); //在世界中创建一个物体（地面）  
	bottomBorder->CreateFixture(&borderFixture1);          //定制地面的形状  
	
}
string BlocksLayer::setSpriteFile()
{
	string fileSprite="";
	int cut = _colorDotCnt - 1;
	if (sign_ZA[0] == cut){ fileSprite = "huidong.png"; }
	else if (sign_ZA[1] == cut){ fileSprite = "qinxie.png"; }
	else if (sign_ZA[2] == cut){ fileSprite = "huizhuan.png"; }
	else if (sign_ZA[3] == cut){ fileSprite = "huizhuanhuidong.png"; }
	else if (sign_ZA[4] == cut){ fileSprite = "yanse.png"; }
	else if (sign_ZA[5] == cut){ fileSprite = "heidong.png"; }
	else if (sign_ZA[6] == cut){ fileSprite = "zhongjian.png"; }
	else if (sign_ZA[7] == cut){ fileSprite = "taicui.png"; }
	else if (sign_ZA[8] == cut){ fileSprite = "fanle.png"; }
	return fileSprite;

}

void BlocksLayer::removeNodeAndVector(){
	//移除body
	b2Body *node = world->GetBodyList();
	while (node){
		b2Body *body = node;
		node = node->GetNext();
		//sprite = (Sprite *)body->GetUserData();
		if (body->GetType()==b2_staticBody)
			world->DestroyBody(body);
		
	}
	//parent_B->removeAllChildren();
	Sprite_.clear();
	_blocksAttribute.clear();

}
//从GameLayer获得camera高度判断移除block
void BlocksLayer::setCameraHeight(float h){
	_cameraHeight = h;
}


void BlocksLayer::beginCallback(float dt){

	SimpleAudioEngine::sharedEngine()->playEffect("anniuM.wav", false);
	//气球
	auto call_qiqiu = CallFunc::create([this](){
		this->removeChildByTag(551);

	});
	
	this->getChildByTag(551)->runAction(Sequence::create(CCEaseExponentialIn::create(MoveBy::create(3, ccp(300, height*1.5))), call_qiqiu, nullptr));
	GameLayer * G = (GameLayer*)this->getParent();
	G->UIOut();
	dengpaoMove->ApplyForce(b2Vec2(200, 0), dengpaoMove->GetWorldCenter(), true);
//	huanchonglistener->setEnabled(false);
	//灯变暗
	this->schedule(schedule_selector(BlocksLayer::Bupdata6));
	/*for (int i = 0; i < cut; i++){
		ccBezierConfig bezer;
		bezer.controlPoint_1 = ccp(900, 150);
		bezer.controlPoint_2 = ccp(960, 100);
		bezer.endPosition = ccp(VISIBLE_SIZE.width+150, -230);
		CCActionInterval *bezier = BezierTo::create(2.5, bezer);
		//auto GUIWEI = MoveTo::create(1.5,ccp(visibleSize.width*0.5,visibleSize.height*0.3));
		auto GUIWEIEaseOut = CCEaseExponentialOut::create(bezier);
		this->getChildByTag(1021 + i)->runAction(GUIWEIEaseOut);
	}*/
	this->getChildByTag(2001)->removeChildByTag(1111);
	//this->getChildByTag(401)->runAction(CCEaseExponentialOut::create(CCMoveTo::create(0.9, ccp(0, VISIBLE_SIZE.height))));

	//this->getChildByTag(405)->runAction(CCEaseExponentialOut::create(CCMoveTo::create(0.9, ccp(VISIBLE_SIZE.width, 0.75*VISIBLE_SIZE.height))));

	//this->getChildByTag(501)->runAction(CCEaseExponentialOut::create(CCMoveBy::create(0.9, ccp(VISIBLE_SIZE.width, 0))));
	

}
//结束，在GameLayer调用
void BlocksLayer::bl_action(){
	
	this->unscheduleUpdate();
	this->unschedule(schedule_selector(BlocksLayer::Bupdata1));
	this->unschedule(schedule_selector(BlocksLayer::Bupdata2));
	this->unschedule(schedule_selector(BlocksLayer::Bupdata3));
	this->unschedule(schedule_selector(BlocksLayer::Bupdata5));
	this->unschedule(schedule_selector(BlocksLayer::Bupdata8));
	this->schedule(schedule_selector(BlocksLayer::Bupdata4), 0.1);
	yun->runAction(CCEaseExponentialOut::create(CCMoveBy::create(3, ccp(0, 500))));
}
//传递_effect
LightEffect * BlocksLayer::getEffect(){

	return _effect;
}
CCActionInterval* BlocksLayer::fireAction(){
	INIT_RANDOM_ENGINE;
	ccBezierConfig bezer_J;

	bezer_J.controlPoint_1 = ccp(50 + (rand()) % 200, 50 + (rand()) % 200);//100 + (rand()) % 200
	bezer_J.controlPoint_2 = ccp(50 + (rand()) % 200, 50 + (rand()) % 200);
	bezer_J.endPosition = ccp(40 + (rand()) % 60, 50 + (rand()) % 65);
	CCActionInterval *bezier_J = BezierTo::create(3 + (rand()) % 6, bezer_J);
	//auto GUIWEI = MoveTo::create(1.5,ccp(visibleSize.width*0.5,visibleSize.height*0.3));
	//auto fireAseOut = CCEaseExponentialOut::create(bezier_J);
	return bezier_J;
}
void BlocksLayer::beginGame(){
	this->removeChildByTag(903);
	this->unschedule(schedule_selector(BlocksLayer::Bupdata3));
	//this->schedule(schedule_selector(BlocksLayer::Bupdata13));
	GameLayer * G = (GameLayer*)this->getParent();
	G->removeUI();
	InitBlocks();
	//云
	//CCTexture2D *texture_yun = CCTextureCache::sharedTextureCache()->textureForKey("newMoon.png");

	//实例化精灵  
	//yun = CCSprite::createWithTexture(texture_yun);
	
	//yun = CCSprite::createWithSpriteFrameName("newMoon.png");
	CCTexture2D *texture_yun = CCTextureCache::sharedTextureCache()->textureForKey("newMoon.png");

	//实例化精灵  
	yun = CCSprite::createWithTexture(texture_yun);
	// yun = Sprite::create("newMoon.png");
	//yun->setAnchorPoint(ccp(0, 0));
	yun->setPosition(ccp(480, height+500));
	yun->setTag(701);
	this->addChild(yun, 99);
	//yun->setCameraMask(2);
	auto yunAction = CCMoveBy::create(1.0, ccp(0, -230));
	auto yunEaseOut = CCEaseExponentialOut::create(yunAction);
	//yun->runAction(yunEaseOut);

	
	auto call1 = CallFunc::create([this](){

		//启动碰撞检测
		world->SetContinuousPhysics(true);
		world->SetContactListener(this);
	
		//出星星
		this->schedule(schedule_selector(BlocksLayer::Bupdata5),0.1);
		//更新云位置
		this->schedule(schedule_selector(BlocksLayer::Bupdata8));
		//shengTi->ApplyLinearImpulse(b2Vec2(0, 50),shengTi->GetWorldCenter(),true);
		body_P->SetLinearVelocity(b2Vec2(0, 65));
		world->DestroyBody(bottomBorder);
		//移除UI
		//this->removeChildByTag(401);
		//this->removeChildByTag(402);
		//this->removeChildByTag(403);
		//this->removeChildByTag(501);
	
		//重力感应
		Device::setAccelerometerEnabled(true);

		//创建事件监听对象
		auto listener = EventListenerAcceleration::create(CC_CALLBACK_2(BlocksLayer::didAccelerate, this));
		//在事件监听器中注册
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
		this->schedule(schedule_selector(BlocksLayer::Bupdata1));
		this->schedule(schedule_selector(BlocksLayer::Bupdata2));



		body_P->SetAwake(true);
		//body_P->SetLinearVelocity(b2Vec2(0, 1250 / PTM_RATIO));

	});
	yun->runAction(Sequence::create(yunEaseOut, call1, nullptr));
}
void BlocksLayer::continueCallback(float dt){ 
	SimpleAudioEngine::sharedEngine()->playEffect("anniuM.wav", false);
	//world->SetContactListener(this);
	Device::setAccelerometerEnabled(true);
	this->schedule(schedule_selector(BlocksLayer::Bupdata8));
	scheduleUpdate();
	body_P->SetLinearVelocity(b2Vec2(0, 65));
	//shengTi->SetLinearVelocity(b2Vec2(0, 60));
//	hand1->SetLinearVelocity(b2Vec2(0, 50));
//	hand3->SetLinearVelocity(b2Vec2(0, 50));
	//hand2->SetLinearVelocity(b2Vec2(0, 55));
	//hand4->SetLinearVelocity(b2Vec2(0, 55));
	this->getChildByTag(559)->runAction(CCEaseElasticOut::create(CCMoveBy::create(1.3, ccp(480, 0))));
	this->getChildByTag(558)->runAction(CCEaseElasticOut::create(CCMoveBy::create(1, ccp(480, 0))));
}
void BlocksLayer::wenCallback(float dt){
	SimpleAudioEngine::sharedEngine()->playEffect("anniuM.wav", false);
	string fileSprite;
//	this->getChildByTag(559)->runAction(CCEaseElasticOut::create(CCMoveBy::create(1.3, ccp(480, 0))));
//	this->getChildByTag(558)->runAction(CCEaseElasticOut::create(CCMoveBy::create(1, ccp(480, 0))));
	int cut = _colorDotCnt - 1;
	if (sign_ZA[0] == cut){ fileSprite = "huidong1.png"; }
	else if (sign_ZA[1] == cut){ fileSprite = "qinxie1.png"; }
	else if (sign_ZA[2] == cut){ fileSprite = "huizhuan1.png"; }
	else if (sign_ZA[3] == cut){ fileSprite = "huidonghuizhuan1.png"; }
	else if (sign_ZA[4] == cut){ fileSprite = "yanse1.png"; }
	else if (sign_ZA[5] == cut){ fileSprite = "heidong1.png"; }
	else if (sign_ZA[6] == cut){ fileSprite = "zhongjian1.png"; }
	else if (sign_ZA[7] == cut){ fileSprite = "taicui1.png"; }
	else if (sign_ZA[8] == cut){ fileSprite = "fanle1.png"; }
	CCTexture2D *texture_wenImage = CCTextureCache::sharedTextureCache()->textureForKey(fileSprite);

	//实例化精灵  
	CCSprite *wenImage = CCSprite::createWithTexture(texture_wenImage);
//	Sprite * wenImage = Sprite::create(fileSprite);
	auto wenImageGame = cocos2d::CCMenuItemSprite::create(wenImage, wenImage, CC_CALLBACK_0(BlocksLayer::wenImageCallback, this, NULL));
	auto wenImageMenu = CCMenu::create(wenImageGame, NULL);
	wenImageMenu->setPosition(ccp(480, 700));
	wenImageMenu->setTag(557);
	wenImageMenu->setOpacity(0);
	this->addChild(wenImageMenu,10);
	wenImageMenu->runAction(CCFadeIn::create(0.3));
	//auto s = CCMoveBy::create(0.05, ccp(-40, 0));
	//this->getChildByTag(559)->runAction(Sequence::create(s, s->reverse(), nullptr));
}

void BlocksLayer::wenImageCallback(float dt){
//	this->getChildByTag(559)->runAction(CCEaseElasticOut::create(CCMoveBy::create(1.3, ccp(-480, 0))));
//	this->getChildByTag(558)->runAction(CCEaseElasticOut::create(CCMoveBy::create(1, ccp(-480, 0))));
	auto call5 = CallFunc::create([this](){
		this->removeChildByTag(557);

	});
	this->getChildByTag(557)->runAction(Sequence::create(CCFadeOut::create(0.3), call5, nullptr)); 
}










void BlocksLayer::finalGame(){
	
	this->schedule(schedule_selector(BlocksLayer::Bupdata4), 0.1);
	
	auto callFinal = CallFunc::create([this](){
		CCSprite *sp = CCSprite::createWithSpriteFrameName("lastWords.png");
		sp->setPosition(480,height*0.5);
		sp->setOpacity(0);
		this->addChild(sp,100);
		sp->runAction(FadeIn::create(1));
	});
	yun->runAction(CCEaseExponentialOut::create(CCScaleBy::create(5, 0.5)));
	yun->runAction(Sequence::create(CCEaseExponentialOut::create(CCMoveBy::create(3, ccp(0, -450))), callFinal, nullptr));
	
	
	//log("%f", Player::sharePlayer()->getPositionY() - (_cameraHeight + 240));
	
}

void BlocksLayer::finalCallback(float dt){
	SimpleAudioEngine::sharedEngine()->playEffect("anniuM.wav", false);
	GameLayer * G = (GameLayer*)this->getParent();
	G->finalGame();
}