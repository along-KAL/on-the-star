






#ifndef __LOADING_H__

#define __LOADING_H__



#include "cocos2d.h"



class Loading : public cocos2d::Layer
	
{
	
public:
	
	Loading(){};
	
	void loading();
		
		static cocos2d::Scene* createScene();
	
		virtual bool init();
	

		
		void loadingCallback();//����һ��ͼƬ��ɺ���ת�Ļٵ�����
	

		
		
	
		CREATE_FUNC(Loading);
	

	
private:
	int count;
		
};



#endif