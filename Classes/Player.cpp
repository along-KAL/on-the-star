#include"Player.h"
USING_NS_CC;
static Player * _singlePlayer;

bool Player::init(){
	//SpriteBatchNode* parent = SpriteBatchNode::create("player.png", 50);
	this->initWithSpriteFrameName("zhujue.png");
	//this->setColor(Color3B(26, 25, 80));
	//yanzhu
	//auto yanzhu = Sprite::create("yanzhu.png");
	//this->addChild(yanzhu);
	// yanzhu->setPosition(Point(58, 118));

	//
	//auto yan = Sprite::create("yanjing1.png");
	//this->addChild(yan);
	//yan->setPosition(Point(58, 118));
	 jumpSign = true;
	
	return true;

}
Player* Player::sharePlayer(){
	if (_singlePlayer == NULL)
	{
		//jiHao = true;
		_singlePlayer = new Player();
		_singlePlayer->init();
		//_singlePlayer->autorelease();
	}
	return _singlePlayer;
}

void Player::runDownAction()
{
	

	Player::sharePlayer()->getPhysicsBody()->setCategoryBitmask(1);
		auto point = this->getParent()->convertToWorldSpace(this->getPosition());
		//auto height = point.y + 70;
		auto moveAction = CCMoveBy::create(0.9, ccp(0, -VISIBLE_SIZE.height));
		auto movesei = CCEaseSineIn::create(moveAction);
		movesei->setTag(0);
		this->runAction(movesei);
	
	
}

bool Player::runJumpAction(bool touchBegin) {
	//使runDownAction只运行一次
	//if (jumpSign == true){
	//	this->getActionByTag(0)->stop();
	//	jumpSign = false;
	//}
	//
	_jumpAction = MyJump::create(0.8, ccp(0, PLAYER_HIGT+20), 100, 1);
	//auto jumpAction = CCMoveBy::create(1, ccp(0,PLAYER_HIGT));
	//auto movesei = CCEaseExponentialOut::create(_jumpAction);
	auto jumpSeq = CCSequence::create(
		_jumpAction,
		CCCallFunc::create(this, callfunc_selector(Player::jumpActionCallBack)),
		NULL);
	jumpSeq->setTag(1);
	this->runAction(jumpSeq);

	return true;
}

void Player::jumpActionCallBack()
{
	
	runDownAction();
}

MyJump * MyJump::create(float duration, const cocos2d::Point& position, float height, int jumps)
{
	MyJump *jumpBy = new MyJump();
	jumpBy->initWithDuration(duration, position, height, jumps);
	jumpBy->autorelease();

	return jumpBy;
}

void Player::runRotateAction(){
	auto Rotate = CCRotateBy::create(1, 30);
	auto Ease1 = CCEaseExponentialOut::create(Rotate);
	//auto RotateSeque = CCSequence::create(Ease1,CCCallFuncN::create(this, callfuncN_selector(Player::callbackRotate)), NULL);

	//auto RotateForever = CCRepeatForever::create(Rotate);
	//RotateForever->setTag(11);
	this->runAction(Ease1);

}

void Player::getGL(GameLayer* GL){
	_GL=GL;

}

//void Player::updata2(float dt)
//{
//	
//	float Y = -(X*X)+256;
//	this->setPosition(this->getPosition().x,this->getPosition().y+Y);
//	if (Y >= 256)
//	{
//		this->unschedule(schedule_selector(Player::updata2));
//	}
//	X=X+0.0001;
//	log("%f",Y);
//}
//void Player::startJump(){
//	X = -30;
//	//log("%f", -(X*X));
//	this->schedule(schedule_selector(Player::updata2),0.1);
//
//}
