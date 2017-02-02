#pragma once
#ifndef _BLOCKSLAYER_H_
#define _BLOCKSLAYER_H_
#include"cocos2d.h"
#include"Block.hpp"
#include"Color.hpp"
#include"Player.h"
#include "Box2D/Box2D.h"
#include"GLES-Render.h"
class GameLayer;
class BlocksLayer :public cocos2d::Layer,public b2ContactListener{
public:
	CREATE_FUNC(BlocksLayer);
	//static BlocksLayer* create(b2World* b);
	virtual bool init();
	//void runDown(int d);
	//两个物体开始接触时会响应  
	virtual void BeginContact(b2Contact* contact);
	//持续接触时响应  
	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
	//持续接触时响应，调用完preSolve后调用  
	virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
	//分离时响应  
	virtual void EndContact(b2Contact* contact);
	//触摸开始事件 
	bool touchBegin(cocos2d::CCTouch * touch, cocos2d::CCEvent *event);
	

	Block * AddBlock(BlockAttributes &blockAttri);
	void beginCallback(float dt);
	void continueCallback(float dt);
	void wenCallback(float dt);
	void wenImageCallback(float dt);
	void finalCallback(float dt);
	//创建海
	void createOcenion();
	b2World* world;
	b2Body *body_P;

	//初始化block
	void InitBlocks();
	void InitBlocksAttribute();
	
	void removeNodeAndVector();
	double zhongliganying;

	//GLESDebugDraw  debugDraw;
	GLESDebugDraw *m_debugDraw;
	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags);
	//
	
	virtual void didAccelerate(cocos2d::Acceleration* acc, cocos2d::Event* event);
	//获得camera'高度
	void setCameraHeight(float h);
	float _cameraHeight;
	//清除所有对象
	//结束block例子动画
	void bl_action();
	int getJIshu();
	LightEffect * getEffect();
	void beginGame();
	cocos2d::CCActionInterval * fireAction();
	std::string setSpriteFile();
protected:
	LightEffect *_effect;
	EventListenerTouchOneByOne *huanchonglistener;
	int t1;
	int t2;
	cocos2d::Sprite * wen;
	cocos2d::Vec3 _lightPos;
	cocos2d::SpriteBatchNode* parent_B;
private:
	b2BodyDef bodyDef_block;
	b2FixtureDef fixDef_block;
	cocos2d::Sprite * yun;
	b2RevoluteJointDef jd1;
	b2RevoluteJointDef jd2;
	int _colorDotCnt;
	int jishu;
	int cut;
	float xianHeight[10];
	//切换光源
	int _light1;
	//摇动线
	b2Body *dengpaoMove;
	bool xian_sign;
	b2Body* body_fire1;
	b2Body* body_fire2;
	b2Body* body_fire3;
	//b2Body* shengTi;
	//b2Body* head;
	b2Body* hand1;
	//b2Body* hand2;
	b2Body* hand3;
	//b2Body* hand4;
	b2Body * bottomBorder;
	//黑洞
	float holl_hight;
	//b2Body *gamebody_P;
	//bool fire_sign1;
	//bool fire_sign2;
	//bool fire_sign3;
	bool effect;
	bool  Gs0;
	bool  Gs1;
	float width;
	float height;
	FileNames _filesNames;
	void AddColorDot(std::string s);
//	cocos2d::Size visibleSize;
	//std::vector<Block *> Blocks_;
	std::vector<Block *> Sprite_;
	std::vector<b2Body *> xings;
	//黑洞坐标
	std::vector<b2Vec2 > holl;
	std::vector<Block *> block_ZA;
	//激光
	//std::vector<cocos2d::Sprite *> jiguang;
	//boom坐标
	//std::vector<b2Vec2 > boomPos;
	//boom
	bool huanchong_sign;
	bool huanchong_sign2;
	bool zhuzi_sign;
	int zhuzi;
	bool zhongliganyingshiling;
	bool touch_sign;
	bool touch_sign2;
	int sign_HC;
	int cnt;
	int sign_JG;
	std::vector<BlockAttributes> _blocksAttribute;
	std::vector<b2Body *> _bodyVect;
	int l;
	int t;
	//重力感应失灵
	int sign_ZLGY;
	bool xxLight;
	bool isLastBl;
	bool firstXXL;
	//加入和移除block
	void Bupdata1(float dt);
	//使Player不溢出 
	void Bupdata2(float dt);
	//进入时灯泡渐变
	void Bupdata3(float dt);
	//结束block粒子动画
	void Bupdata4(float dt);
	//检测第几个颜色
	void Bupdata5(float dt);
	//开始时灯变暗&并移除joint
	void Bupdata6(float dt);
	//更新光源位置&//切换光源
	void Bupdata7(float dt);
	//更新月亮位置
	void Bupdata8(float dt);
	//fireFly
	void Bupdata9(float dt);
	//fireForce
	void Bupdata10(float dt);
	//fireForce
	//黑洞
	void Bupdata11(float dt);
	//柱子
	void Bupdata12(float dt);
	//随机xx闪烁
	void Bupdata13(float dt);
	virtual void update(float delta);
	//void BlocksActionCallBack();
	//高级版
	//void Bupdata_GJ(float dt);
	void finalGame();
};
#endif