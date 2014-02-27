#ifndef __SETTING_SCENE_H__
#define __SETTING_SCENE_H__

#include "cocos-ext.h"
#include "cocos2d.h"
USING_NS_CC_EXT;

class SettingPage : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
	void callBack(CCObject *sender, CCControlEvent controlEvent);
    
    // implement the "static node()" method manually
    CREATE_FUNC(SettingPage);
};

#endif // __HELLOWORLD_SCENE_H__
