#include "GameControlLayer.h"
#include "GameScene.h"

USING_NS_CC;

bool GameControlLayer::init()
{
	if (CCLayer::init())
	{
		this->createComandMenu();
		return true;
	}
	return false;
}

int GameControlLayer::getWordIndex()
{
	return (int)CCRANDOM_0_1()*1000;
}

void GameControlLayer::createComandMenu()
{
	int fontSize = 20;
	CCString* fontName = CCString::create("");
	
	attackIndex = getWordIndex();
	moveIndex = getWordIndex();
	jumpIndex = getWordIndex();

	attackWord = CCLabelTTF::create("attack: " + attackIndex, fontName->getCString(), fontSize);
	moveWord = CCLabelTTF::create("move: " + attackIndex, fontName->getCString(), fontSize);
	jumpWord = CCLabelTTF::create("jump: " + attackIndex, fontName->getCString(), fontSize);

	attack = CCMenuItemLabel::create(attackWord, this, menu_selector(GameControlLayer::attackComand));
	move = CCMenuItemLabel::create(moveWord, this, menu_selector(GameControlLayer::moveComand));
	jump = CCMenuItemLabel::create(jumpWord, this, menu_selector(GameControlLayer::jumpComand));

	CCMenu* menu= CCMenu::create(attack, move, jump, NULL);
	menu->alignItemsVerticallyWithPadding(5);
	menu->setPosition(CCPointMake(178,100));
	this->addChild(menu);
}

GameScene* GameControlLayer::getGameScene()
{
	return (GameScene*)this->getParent();
}

void GameControlLayer::attackComand(cocos2d::CCObject* pSender)
{
	this->getGameScene()->gamePlayerLayer->gameYou->attackComand();
}

void GameControlLayer::moveComand(cocos2d::CCObject* pSender)
{
	this->getGameScene()->moveComand();
}

void GameControlLayer::jumpComand(cocos2d::CCObject* pSender)
{
	this->getGameScene()->jumpComand();
}