#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "CCShake.hpp"

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    this->colorLayer =  LayerColor::create(Color4B(200,0,0,255), visibleSize.width, visibleSize.height);
    this->colorLayer->setPosition(Vec2(origin.x ,
                                origin.y));
    this->addChild(colorLayer);
    
    ui::Button* trueItem = ui::Button::create("true.png","true_select.png");
    trueItem->setPosition(Vec2(origin.x + 15 + trueItem->getContentSize().width/2,
                               origin.y + 15 + trueItem->getContentSize().height/2));
    trueItem->addTouchEventListener( CC_CALLBACK_1(GameScene::menuTrueCallback, this) );
    this->addChild(trueItem);
    
    ui::Button* falseItem = ui::Button::create("false.png","false_select.png");
    falseItem->setPosition(Vec2(origin.x +  visibleSize.width - falseItem->getContentSize().width/2 - 15 ,
                                origin.y + 15 + falseItem->getContentSize().height/2));
    falseItem->addTouchEventListener( CC_CALLBACK_1(GameScene::menuFalseCallback, this) );
    this->addChild(falseItem);

    
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
     this->labelRow1 = Label::createWithTTF("2+2", "fonts/relay-black.ttf", 60);
    // position the label on the center of the screen
    labelRow1->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height/2 + labelRow1->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(this->labelRow1, 1);
    
    
    this->labelRow2 = Label::createWithTTF("=6", "fonts/relay-black.ttf", 60);
    // position the label on the center of the screen
    labelRow2->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/2 - 0.25*labelRow2->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(this->labelRow2, 1);

   
    
    return true;
}

void GameScene::newGame()
{
    
}

void GameScene::menuTrueCallback(Ref* pSender)
{
    
    //Close the cocos2d-x game scene and quit the application
//    Director::getInstance()->end();
//
//    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    this->runAction(CCShake::actionWithDuration(0.5f, 1.0f));
    
}


void GameScene::menuFalseCallback(Ref* pSender)
{
    
    this->runAction(CCShake::actionWithDuration(0.5f, 1.0f));
    
}


cocos2d::Color4B GameScene:: getRandomColor()
{
    
}




















