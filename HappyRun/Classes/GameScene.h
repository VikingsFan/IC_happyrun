#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "GameBackgroundLayer.h"
#include "GamePlayerLayer.h"
#include "GameMapLayer.h"
#include "GameEnemyLayer.h"
#include "GameControlLayer.h"
#include "GameBulletLayer.h"

class GameScene : public cocos2d::CCScene
{
public:
	CREATE_FUNC(GameScene);

	bool init();
	void menuCloseCallback(CCObject* pSender);
	void attackComand(int kind, GameEnemy* targetNode);
	void moveComand();
	void jumpComand();

	bool isInView(CCPoint p);

	void update(float dt);
	void refreshPlayer(float dt);
	void refreshEnemy(float dt);
	void refreshBullet(float dt);
	void setPlayerJump(float dt);
	void setEnemyAI(float dt);
	void setView(float dt);


	GameBackgroundLayer* gameBackgroundLayer;
	GamePlayerLayer* gamePlayerLayer;
	GameMapLayer* gameMapLayer;
	GameEnemyLayer* gameEnemyLayer;
	GameControlLayer* gameControlLayer;
	GameBulletLayer* gameBulletLayer;

	float game_g;
	CCPoint gameViewOriginPoint;

	~GameScene();
};

#endif // __GAME_SCENE_H__
