//
//  Popup.hpp
//  FreakingMath
//
//  Created by long on 4/14/17.
//
//

#ifndef Popup_hpp
#define Popup_hpp

#include <stdio.h>
#include "string"

#include "cocos2d.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;

USING_NS_CC;

class Popup : public Node
{
public:
    CREATE_FUNC(Popup);
    
    virtual bool init();
    virtual void onExit();
    
    virtual void disappear();
    virtual void appear();
    
    virtual void setTitlePopup(std::string _titlePopup);
    void startGame(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType type);

    
protected:
    Layer                       *m_popupLayer;
    
    Size                        backgroundContentSize;
    Size                        visibleSize;
    Point                       origin;
    
    ActionInterval              *m_appearAction;
    ActionInterval              *m_disappearAction;
    
private:
};


#endif /* Popup_hpp */
