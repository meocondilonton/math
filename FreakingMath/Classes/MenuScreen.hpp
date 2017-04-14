//
//  MenuScreen.hpp
//  FreakingMath
//
//  Created by long nguyen on 3/30/17.
//
//

#ifndef MenuScreen_hpp
#define MenuScreen_hpp


#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <ctime>
#include "MenuScreen.hpp"

class MenuScreen : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
   
    
    
protected:
    cocos2d::LayerColor *colorLayer;
    CREATE_FUNC(MenuScreen);
};

#endif /* MenuScreen_hpp */
