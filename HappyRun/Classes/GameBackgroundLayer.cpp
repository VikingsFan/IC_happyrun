#include "GameBackgroundLayer.h"

#include "GameScene.h"

USING_NS_CC;

bool GameBackgroundLayer::init()
{
	if (CCLayer::init()){
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();

		//CCSprite* background = CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("background"));
		CCSprite* background = CCSprite::create("gameBackground.png");

		background->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.5));
		this->addChild(background);
		return true;
	}
	return false;
}

GameScene* GameBackgroundLayer::getGameScene()
{
	return (GameScene*)this->getParent();
}
