//
//  MenuScreen.cpp
//  FreakingMath
//
//  Created by long nguyen on 3/30/17.
//
//

#include "MenuScreen.hpp"
USING_NS_CC;

Scene* MenuScreen::createScene()
{
    return MenuScreen::create();
}

// on "init" you need to initialize your instance
bool MenuScreen::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    

//    this->colorLayer =  LayerColor::create(Color4B::BLUE, visibleSize.width, visibleSize.height);
//    this->colorLayer->setPosition(Vec2(origin.x ,
//                                       origin.y));
//    this->addChild(colorLayer);

    
    return true;
}
