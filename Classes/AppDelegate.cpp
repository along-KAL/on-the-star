#include "AppDelegate.h"
#include "Loading.h"
#define  int HD_PORT_SCHEME = 1;
USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
		glview = GLViewImpl::create("My Game");
		glview->setFrameSize(320, 480);
        director->setOpenGLView(glview);
	
	
    }//EXACT_FIT
	
	//glview->setDesignResolutionSize(640, 960, ResolutionPolicy::EXACT_FIT);
	CCSize frameSize = glview->getFrameSize();
	
	if (frameSize.width == 960 && frameSize.height == 1440)
		
	{
		
			//标准分辨率，不做调整
			
	}
	
	else if (frameSize.width == 960 && frameSize.height == 1616)
	
	{
		
			//标准分辨率，不做调整
			
	}
	
	else
	
	{
		
			CCSize winSize;
		

		
			
				//SD资源
			std::vector<std::string> searchPaths;
			searchPaths.push_back("SD");
			CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);
				winSize = CCSize(960, 1440);
			
		
		

			
		

		

			

			
			//WHR宽高比 width height ratio
			
			float winSizeWHR = winSize.width / winSize.height;
		
			float frameSizeWHR = frameSize.width / frameSize.height;
		

			
		if (winSizeWHR > frameSizeWHR)
			
			glview->setDesignResolutionSize(winSize.width, winSize.height, kResolutionFixedWidth);
		
		else
		
			glview->setDesignResolutionSize(winSize.width, winSize.height, kResolutionFixedHeight);
		
	}

    // turn on display FPS
   // director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
	glClearColor(1.0, 1.0, 1.0, 1.0);
    // create a scene. it's an autorelease object
    auto scene = Loading::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
