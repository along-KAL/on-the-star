#pragma once
#include "cocos2d.h"

#include "EffectSprite/LightEffect.h"
#include "EffectSprite/EffectSprite.h"
USING_NS_CC;
class BlockAttributes
{
public:
	BlockAttributes() :_x(0), _y(0), _color(""), _allow(false), _isMove(false), _isXie(false), _isRota(false), _isMoRo(false){

	}
	BlockAttributes(float x, float y, std::string color, bool allow, bool isMove, bool isXie, bool isRota, bool isMoRo) :
		_x(x), _y(y), _color(color), _allow(allow), _isMove(isMove), _isXie(isXie), _isRota(isRota), _isMoRo(isMoRo){

	}
	BlockAttributes(std::string color, bool allow) :
		 _color(color), _allow(allow){

	}
	BlockAttributes(float y) :
		_y(y){

	}
	BlockAttributes& operator= (const BlockAttributes& other){
		_x = other._x;
		_y = other._y;
		_color = other._color;
		_allow = other._allow;
		_isMove = other._isMove;
		_isXie = other._isXie;
		_isRota = other._isRota;
		_isMoRo = other._isMoRo;
		return *this;
	}
	bool isAllow(){ return _allow; }
	float _x;
	float _y;
	std::string _color;
	bool _allow;
	bool _isMove;
	bool _isXie;
	bool _isRota;
	bool _isMoRo;
	//bool allow_Sign = false;
protected:
private:
};

class Block :public Sprite, public BlockAttributes
{
public:
	
	 std::string Filename;
	 cocos2d::Color4F c;
	Block():Filename(""){
		//this->setTag(BLOCK_TAG);
	}
	void setAttributes(const BlockAttributes &ba){
		att = ba;
		_x = ba._x;
		_y = ba._y;
		_color = ba._color;
		_allow = ba._allow;
		_isMove = ba._isMove;
		_isXie = ba._isXie;
		_isRota = ba._isRota;
		_isMoRo = ba._isMoRo;
		//this->setColor(_color);
		this->initWithFile(ba._color);
		//this->initWithSpriteFrameName(ba._color);
		Filename = _color;
		if (Filename == "bl1.png"){
			c = Color4F(0.6513, 0.6825, 0.6981, 0.5421);
		}

		else if (Filename == "bl2.png"){
			c = Color4F(0.9945, 0.3978, 0.1989, 0.5421);
		}
		else if (Filename == "bl3.png"){
			c = Color4F(0.9945, 0.5967, 0.5967, 0.5421);
		}
		else if (Filename == "bl4.png"){
			c = Color4F(0.3744, 0.3822, 0.4992, 0.5421);
		}
		else if (Filename == "bl5.png"){
			c = Color4F(0.9438, 0.1872, 0.3315, 0.5421);
		}
		else if (Filename == "bl6.png"){
			c = Color4F(0.5655, 0.2223, 0.5967, 0.5421);
		}
		else if (Filename == "bl7.png"){
			c = Color4F(0, 0.7956, 0.3978, 0.5421);
		}
		else if (Filename == "bl8.png"){
			c = Color4F(0.9945, 0.9945, 0.7956, 0.5421);
		}
		else if (Filename == "bl9.png"){
			c = Color4F(0.1989, 0.7956, 0.7956, 0.5421);
		}
		else if (Filename == "bl10.png"){
			c = Color4F(0.9945, 0.7956, 0.1989, 0.5421);
		}
		else if (Filename == "bl11.png"){
			c = Color4F(0.7371, 0.4524, 0.2028, 0.5421);
		}
	}
	BlockAttributes getAttribute(){
		return att;
	}
//	void setSign_jg(int sign_Jg){
//		sign_jg = sign_Jg;
//	};
	//int getSign_jg(){ return sign_jg; }
	virtual bool init(){
		return true;
	}
	
	CREATE_FUNC(Block);
	
protected:

private:
	BlockAttributes att;
	int sign_jg=NULL;
};