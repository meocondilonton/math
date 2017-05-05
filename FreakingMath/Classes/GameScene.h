#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <ctime>
#include "MenuScreen.hpp"
#include "Popup.hpp"

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
     int getRandomMediumNumber();
     int getRandomResultNumber(int max);
     int getRealResultNumber();
    void updateNewQuestion();
    void answareWrong();
    void update(float delta);
    
protected:
     cocos2d::LayerColor *colorLayer;
     cocos2d::Label *labelRow1;
     cocos2d::Label *labelRow2;
     Popup  *popup ;
     ProgressTimer *fuelBar;
     int numA;
     int numB;
     int numResult;
     cocos2d::Vec2 row1Pos;
     cocos2d::Vec2 row2Pos;
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
};

#endif // __HELLOWORLD_SCENE_H__
