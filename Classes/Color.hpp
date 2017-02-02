#pragma once
#include "cocos2d.h"
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>



class FileNames {
public:
	FileNames() {
		_allFaileName.push_back("bl1.png");
		_allFaileName.push_back("bl2.png");
		_allFaileName.push_back("bl3.png");
		_allFaileName.push_back("bl4.png");
		_allFaileName.push_back("bl5.png");
		_allFaileName.push_back("bl6.png");
		_allFaileName.push_back("bl7.png");
		_allFaileName.push_back("bl8.png");
		_allFaileName.push_back("bl9.png");
		_allFaileName.push_back("bl10.png");
	//	_allFaileName.push_back("bl11.png");
	}
	void randomFaileNames() {
		//random_shuffle(_allColors.begin(),_allColors.end(),MyRand());
		std::vector<std::string> tmp;
		std::random_device rd;
		std::default_random_engine e(rd());//生成随机无符号数
		while (_allFaileName.size() > 0) {
			std::uniform_int_distribution<int> u(0, _allFaileName.size() - 1); //生成0到10（包含）均匀分布的随机数
			auto iter = _allFaileName.begin() + (int)u(e);
			tmp.push_back(*iter);
			_allFaileName.erase(iter);
		}
		_allFaileName = tmp;
	}
	ssize_t cnt() {
		return _allFaileName.size();
	}
	 std::string operator[](int index) {
		 return _allFaileName[index];
	}
protected:

private:
	std::vector<std::string> _allFaileName;
};















/*#pragma once
#include "cocos2d.h"
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>

class Color {
public:
	Color() : _r(0), _b(0), _g(0) {}
	Color(GLubyte r, GLubyte g, GLubyte b) : _r(r), _g(g), _b(b) {

	}
	Color& operator= (const Color& other) {
		_r = other._r;
		_g = other._g;
		_b = other._b;
		return *this;
	}

	const cocos2d::Color3B getCCColor() {
		return cocos2d::ccc3(_r, _g, _b);
	}

	GLubyte _r;
	GLubyte _g;
	GLubyte _b;
protected:
private:

};


class Colors {
public:
	Colors() {
		_allColors.push_back(Color(167, 175, 179));
		_allColors.push_back(Color(255, 102, 51));
		_allColors.push_back(Color(255, 153, 153)); 
		_allColors.push_back(Color(96, 98, 128));
		_allColors.push_back(Color(242, 48, 85));
		_allColors.push_back(Color(145, 57, 153));
		_allColors.push_back(Color(0, 204, 102));
		_allColors.push_back(Color(255, 255, 204));
		_allColors.push_back(Color(51, 204, 204));
		_allColors.push_back(Color(255, 204, 51));
		_allColors.push_back(Color(189, 116, 52));
	}
	void randomColors() {
		//random_shuffle(_allColors.begin(),_allColors.end(),MyRand());
		std::vector<Color> tmp;
		std::random_device rd;
		std::default_random_engine e(rd());//生成随机无符号数
		while (_allColors.size() > 0) {
			std::uniform_int_distribution<int> u(0, _allColors.size() - 1); //生成0到10（包含）均匀分布的随机数
			auto iter = _allColors.begin() + (int)u(e);
			tmp.push_back(*iter);
			_allColors.erase(iter);
		}
		_allColors = tmp;
	}
	ssize_t cnt() {
		return _allColors.size();
	}
	const cocos2d::Color3B operator[](int index) {
		return _allColors[index].getCCColor();
	}
protected:

private:
	std::vector<Color> _allColors;
};
*/