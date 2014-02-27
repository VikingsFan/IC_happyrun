#include "GameMapLayer.h"
#include "GameScene.h"

USING_NS_CC;

bool GameMapLayer::init()
{
	if (CCLayer::init())
	{
		CCLayerColor* colorBlock = CCLayerColor::create(ccc4(0, 0, 0, 255), 1366, 200);
		colorBlock->setPosition(CCPointMake(0, 0));
		this->addChild(colorBlock);
		return true;
	}
	return false;
}

GameScene* GameMapLayer::getGameScene()
{
	return (GameScene*)this->getParent();
}
