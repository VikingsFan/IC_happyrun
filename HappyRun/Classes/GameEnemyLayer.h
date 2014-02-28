#ifndef __GAME_ENEMY_LAYER_H__
#define __GAME_ENEMY_LAYER_H__
#include "cocos2d.h"

USING_NS_CC;

class GameScene;
class GameEnemy;

class GameEnemyLayer : public cocos2d::CCLayer
{
public:
	CREATE_FUNC(GameEnemyLayer);
	bool init();
	GameScene* getGameScene();

	void recycle(GameEnemy* enemy);
	void refresh(float dt);
	void theBadIsComing();
	void setEnemyAI(float dt);

	CCArray* enemys;

	~GameEnemyLayer();
};

#endif 