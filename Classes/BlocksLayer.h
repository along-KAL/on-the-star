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
	//�������忪ʼ�Ӵ�ʱ����Ӧ  
	virtual void BeginContact(b2Contact* contact);
	//�����Ӵ�ʱ��Ӧ  
	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
	//�����Ӵ�ʱ��Ӧ��������preSolve�����  
	virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
	//����ʱ��Ӧ  
	virtual void EndContact(b2Contact* contact);
	//������ʼ�¼� 
	bool touchBegin(cocos2d::CCTouch * touch, cocos2d::CCEvent *event);
	

	Block * AddBlock(BlockAttributes &blockAttri);
	void beginCallback(float dt);
	void continueCallback(float dt);
	void wenCallback(float dt);
	void wenImageCallback(float dt);
	void finalCallback(float dt);
	//������
	void createOcenion();
	b2World* world;
	b2Body *body_P;

	//��ʼ��block
	void InitBlocks();
	void InitBlocksAttribute();
	
	void removeNodeAndVector();
	double zhongliganying;

	//GLESDebugDraw  debugDraw;
	GLESDebugDraw *m_debugDraw;
	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags);
	//
	
	virtual void didAccelerate(cocos2d::Acceleration* acc, cocos2d::Event* event);
	//���camera'�߶�
	void setCameraHeight(float h);
	float _cameraHeight;
	//������ж���
	//����block���Ӷ���
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
	//�л���Դ
	int _light1;
	//ҡ����
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
	//�ڶ�
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
	//�ڶ�����
	std::vector<b2Vec2 > holl;
	std::vector<Block *> block_ZA;
	//����
	//std::vector<cocos2d::Sprite *> jiguang;
	//boom����
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
	//������Ӧʧ��
	int sign_ZLGY;
	bool xxLight;
	bool isLastBl;
	bool firstXXL;
	//������Ƴ�block
	void Bupdata1(float dt);
	//ʹPlayer����� 
	void Bupdata2(float dt);
	//����ʱ���ݽ���
	void Bupdata3(float dt);
	//����block���Ӷ���
	void Bupdata4(float dt);
	//���ڼ�����ɫ
	void Bupdata5(float dt);
	//��ʼʱ�Ʊ䰵&���Ƴ�joint
	void Bupdata6(float dt);
	//���¹�Դλ��&//�л���Դ
	void Bupdata7(float dt);
	//��������λ��
	void Bupdata8(float dt);
	//fireFly
	void Bupdata9(float dt);
	//fireForce
	void Bupdata10(float dt);
	//fireForce
	//�ڶ�
	void Bupdata11(float dt);
	//����
	void Bupdata12(float dt);
	//���xx��˸
	void Bupdata13(float dt);
	virtual void update(float delta);
	//void BlocksActionCallBack();
	//�߼���
	//void Bupdata_GJ(float dt);
	void finalGame();
};
#endif