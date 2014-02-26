#ifndef __GAME_ENEMY_LAYER_H__
#define __GAME_ENEMY_LAYER_H__
#include "cocos2d.h"

USING_NS_CC;

class GameScene;

class GameEnemyLayer : public cocos2d::CCLayer
{
public:
	CREATE_FUNC(GameEnemyLayer);
	bool init();
	GameScene* getGameScene();

	CCArray* enemys;

	~GameEnemyLayer();
};

#endif 