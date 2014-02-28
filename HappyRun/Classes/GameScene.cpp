#include "GameScene.h"
#include "GameEnemy.h"

USING_NS_CC;

enum {
	gameBackgroundLayerZ = 0,
	gameBulletLayerZ,
	gameMapLayerZ,
	gameControlLayerZ,
	gameEnemyLayerZ,
	gamePlayerLayerZ
};
bool GameScene::init()
{
	//preloadResources();
	if (CCScene::init()){
		gameBackgroundLayer = GameBackgroundLayer::create();
		this->addChild(gameBackgroundLayer, gameBackgroundLayerZ);

		gameMapLayer = GameMapLayer::create();
		this->addChild(gameMapLayer, gameMapLayerZ);

		gameControlLayer = GameControlLayer::create();
		this->addChild(gameControlLayer, gameControlLayerZ);
		
		gameBulletLayer = GameBulletLayer::create();
		this->addChild(gameBulletLayer, gameBulletLayerZ);

		gameEnemyLayer = GameEnemyLayer::create();
		this->addChild(gameEnemyLayer, gameEnemyLayerZ);

		gamePlayerLayer = GamePlayerLayer::create();
		this->addChild(gamePlayerLayer, gamePlayerLayerZ);

		game_g = 600;

		//for (int i = 0; i < 1000000; i++)
		gameViewOriginPoint = CCPointZero;
		this->scheduleUpdate();

		return true;
	}
	return false;
}

void GameScene::attackComand(int kind, GameEnemy* targetNode)
{
	gameBulletLayer->attack(kind, targetNode, "Fuck");
}

void GameScene::moveComand()
{
	gamePlayerLayer->getGameYou()->moveComand();
}

void GameScene::jumpComand()
{
	gamePlayerLayer->gameYou->jumpComand();
}

bool GameScene::isInView(CCPoint p)
{
	if (p.x < (-gameViewOriginPoint.x - 100))
		return false;
	return true;
}

void GameScene::update(float dt)
{
	this->refreshPlayer(dt);
	this->refreshBullet(dt);
	this->refreshEnemy(dt);
	this->setView(dt);
}

void GameScene::refreshPlayer(float dt)
{
	this->setPlayerJump(dt);
}

void GameScene::refreshEnemy(float dt)
{
	gameEnemyLayer->refresh(dt);
}

void GameScene::refreshBullet(float dt)
{
	gameBulletLayer->refresh(dt);
}

void GameScene::setPlayerJump(float dt)
{
	if ((gamePlayerLayer->gameYou->getPositionY() > 215) || (gamePlayerLayer->gameYou->jumpSpeed != 0))
	{
		float y = gamePlayerLayer->gameYou->getPositionY();
		y += gamePlayerLayer->gameYou->jumpSpeed * dt;
		if (y <= 215)
		{
			gamePlayerLayer->gameYou->jumpSpeed = 0;
			y = 215;
		}
		else
			gamePlayerLayer->gameYou->jumpSpeed -= dt * game_g;
		gamePlayerLayer->gameYou->setPositionY(y);
	}
}

void GameScene::setView(float dt)
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	int x = gamePlayerLayer->gameYou->getPositionX()-(-gameViewOriginPoint.x) - visibleSize.width / 3;
	//CCLog("%d %d", x, gamePlayerLayer->getGameYou()->getPositionX());
	if (x >= 0)
	{
		gameViewOriginPoint.x -= x;
		gamePlayerLayer->setPosition(gameViewOriginPoint);
		gameEnemyLayer->setPosition(gameViewOriginPoint);
		gameBulletLayer->setPosition(gameViewOriginPoint);
	}
}

void GameScene::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
#else
	CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
#endif
}

GameScene::~GameScene()
{
	this->unscheduleUpdate();
}