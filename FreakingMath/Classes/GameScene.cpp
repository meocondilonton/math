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
 
    ui::Button* falseItem = ui::Button::create("false.png","false_select.png");
    falseItem->setPosition(Vec2(origin.x +  visibleSize.width - falseItem->getContentSize().width/2 - 10 ,
                                origin.y + 10 + falseItem->getContentSize().height/2));
    falseItem->addTouchEventListener( CC_CALLBACK_1(GameScene::menuFalseCallback, this) );
    this->addChild(falseItem);
    
    ui::Button* trueItem = ui::Button::create("true.png","true_select.png");
    trueItem->setPosition(Vec2(origin.x + 10 + trueItem->getContentSize().width/2,
                               origin.y + 10 + trueItem->getContentSize().height/2));
    trueItem->addTouchEventListener( CC_CALLBACK_1(GameScene::menuTrueCallback, this) );
    this->addChild(trueItem);
    
   
    
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
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























