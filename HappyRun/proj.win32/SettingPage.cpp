#include "SettingPage.h"
#include "HomePage.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

CCScene* SettingPage::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SettingPage *layer = SettingPage::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SettingPage::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(SettingPage::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);




    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Setting Page", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
	
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("lucky.mid");
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("lucky.mid", true);
	
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	CCControlSlider *slider = CCControlSlider::create("sliderTrack.jpg", "progress.jpg", "voiceButton.jpg");
	slider -> setMinimumAllowedValue(0);
	slider -> setMaximumAllowedValue(1);
	slider -> setValue(0.5);

	slider -> setAnchorPoint(ccp(0.5, 1));
	slider -> setPosition(ccp(size.width / 2, size.height / 2));

	slider -> addTargetWithActionForControlEvents(this, cccontrol_selector(SettingPage::callBack), CCControlEventValueChanged);

	addChild(slider, 2);


    return true;
}

void SettingPage::callBack(CCObject *pSender, CCControlEvent controlEvent)
{
	CCControlSlider* pSlider = (CCControlSlider*) pSender;
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(pSlider->getValue());
	CCLOG("%f", pSlider->getValue() * 5);
}


void SettingPage::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
	CCScene *pScene = HomePage::scene();
	CCDirector::sharedDirector() -> replaceScene(pScene);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
