#ifndef __GAME_CONTROL_LAYER_H__
#define __GAME_CONTROL_LAYER_H__
#include "cocos2d.h"

USING_NS_CC;

class GameScene;

class GameControlLayer : public cocos2d::CCLayer
{
public:
	CREATE_FUNC(GameControlLayer);

	bool init();
	int getWordIndex();
	void createComandMenu();
	GameScene* getGameScene();

	void attackComand(cocos2d::CCObject* pSender);
	void moveComand(cocos2d::CCObject* pSender);
	void jumpComand(cocos2d::CCObject* pSender);

	int attackIndex;
	int moveIndex;
	int jumpIndex;
	CCLabelTTF* attackWord;
	CCLabelTTF* moveWord;
	CCLabelTTF* jumpWord;
	CCMenuItemLabel* attack;
	CCMenuItemLabel* move;
	CCMenuItemLabel* jump;
};

#endif 