//
//  Popup.cpp
//  FreakingMath
//
//  Created by long on 4/14/17.
//
//

#include "Popup.hpp"
#include "Const.hpp"

bool Popup::init()
{
    if (!Node::init()) return false;
    
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
    m_popupLayer = Layer::create();
    m_popupLayer->setAnchorPoint(Vec2::ZERO);
    m_popupLayer->setPosition(Vec2(visibleSize.width , visibleSize.height + origin.y));
    addChild(m_popupLayer);
    
//    auto _background = Sprite::create("game_over_bg.png");
//    _background->setAnchorPoint(Vec2::ZERO);
//    _background->setPosition(Point::ZERO);
//    m_popupLayer->addChild(_background);
//    
//    backgroundContentSize = _background->getContentSize();
    
    ui::Button* trueItem = ui::Button::create("true.png","true_select.png");
    trueItem->setPosition(Vec2(origin.x + visibleSize.width/2 + trueItem->getContentSize().width/2,
                               origin.y + visibleSize.height/2 + trueItem->getContentSize().height/2));
    trueItem->addTouchEventListener( CC_CALLBACK_2(Popup::startGame, this) );
    m_popupLayer->addChild(trueItem);
    
    m_appearAction = TargetedAction::create(m_popupLayer,
                                            MoveTo::create(POPUP_FADING_TIME,
                                                           Vec2(visibleSize.width/2 - backgroundContentSize.width/2 + origin.x, visibleSize.height/2 - backgroundContentSize.height/2 + origin.y)));
    
    m_disappearAction = TargetedAction::create(m_popupLayer,
                                               MoveTo::create(POPUP_FADING_TIME,
                                                              Vec2(origin.x, origin.y)));
    
    m_appearAction->retain();
    m_disappearAction->retain();
    
    return true;
}

void Popup::startGame(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType type)
{
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        CCLOG("sss");
      
    }
}
void Popup::disappear()
{
    this->runAction(m_disappearAction->clone());
}

void Popup::appear()
{
    this->runAction(m_appearAction->clone());
}

void Popup::setTitlePopup(std::string _titlePopup)
{
    auto _title =  Label::createWithTTF("=12", "fonts/relay-black.ttf", 60);

    
    _title->setAdditionalKerning(7.0f);
    _title->setPosition(Point(backgroundContentSize.width / 2 + origin.x,
                              backgroundContentSize.height * 8 / 10 + origin.y));
    
//    _title->setColor(COLOR_TEXT_YELOW);
    _title->setScale(1.5f);
    
    m_popupLayer->addChild(_title);
}

void Popup::onExit() 
{ 
    m_appearAction->release(); 
    m_disappearAction->release(); 
    
    Node::onExit(); 
}
