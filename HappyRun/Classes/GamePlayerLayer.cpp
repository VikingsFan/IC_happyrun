#include "GamePlayerLayer.h"
#include "GameScene.h"

USING_NS_CC;

bool GamePlayerLayer::init()
{
	if (CCLayer::init())
	{
		gameYou = GameYou::create(1);
		this->addChild(gameYou);

		gameBullet = GameBullet::create(1);
		gameBullet->setVisible(false);
		this->addChild(gameBullet);
		return true;
	}
	return false;
}

GameScene* GamePlayerLayer::getGameScene()
{
	return (GameScene*)this->getParent();
}

GameYou* GamePlayerLayer::getGameYou()
{
	return gameYou;
}