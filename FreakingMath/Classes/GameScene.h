#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <ctime>

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuTrueCallback(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
    void menuFalseCallback(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
    
     void newGame();
     void nextRound();
     cocos2d::Color4B getRandomColor();
     int getRandomNumber();
     int getRandomBigNumber();
     int getRandomSmallNumber();
     int getRandomResultNumber(int max);
     int getRealResultNumber();
    
protected:
     cocos2d::LayerColor *colorLayer;
     cocos2d::Label *labelRow1;
     cocos2d::Label *labelRow2;
     int numA;
     int numB;
     int numResult;
     cocos2d::Vec2 row1Pos;
     cocos2d::Vec2 row2Pos;
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
};

#endif // __HELLOWORLD_SCENE_H__
