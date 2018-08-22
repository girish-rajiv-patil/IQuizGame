#include "AppDelegate.h"

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() {
}

bool AppDelegate::applicationDidFinishLaunching() {
// 	CCDirector *pDirector = CCDirector::sharedDirector();
// 	pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
// 
// 	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(720, 1280,
// 			kResolutionShowAll);
// 
// //	pDirector->setDisplayStats(true);
// 
// 	pDirector->setAnimationInterval(1.0 / 60);
// 
// 	pDirector->runWithScene(Home::scene());

     auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::createWithRect("IQuiz__Girish", Rect(0, 0, 450, 700));
        director->setOpenGLView(glview);
    }

    director->getOpenGLView()->setDesignResolutionSize(700, 1280, ResolutionPolicy::SHOW_ALL);
    
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);



    // create a scene. it's an autorelease object


    // run
    director->runWithScene(Home::scene());
    
	auto soundManager = SoundManager::sharedSoundManager();
	soundManager->onAppStarting();
	soundManager->playLoopingBackground("Background");

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
	CCDirector::sharedDirector()->pause();

	// if you use SimpleAudioEngine, it must be pause
	SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	CCDirector::sharedDirector()->resume();

	// if you use SimpleAudioEngine, it must resume here
	SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
