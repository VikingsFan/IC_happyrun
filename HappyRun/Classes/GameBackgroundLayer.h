#ifndef __GAME_BACKGROUND_LAYER_H__
#define __GAME_BACKGROUND_LAYER_H__
#include "cocos2d.h"

class GameScene;

class GameBackgroundLayer : public cocos2d::CCLayer
{
public:
	CREATE_FUNC(GameBackgroundLayer);
	bool init();
	GameScene* getGameScene();
};

#endif 
