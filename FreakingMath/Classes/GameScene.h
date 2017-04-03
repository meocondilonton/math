#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuTrueCallback(cocos2d::Ref* pSender);
    void menuFalseCallback(cocos2d::Ref* pSender);
    
    void newGame();
    cocos2d::Color4B getRandomColor();
    
protected:
     cocos2d::LayerColor *colorLayer;
     cocos2d::Label *labelRow1;
     cocos2d::Label *labelRow2;
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
};

#endif // __HELLOWORLD_SCENE_H__
