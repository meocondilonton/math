#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "CCShake.hpp"
#include "SoundTool.hpp"

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
     auto screenSize = Director::getInstance()->getWinSize();
    Size actualWinSize = Director::getInstance()->getWinSizeInPixels();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    this->colorLayer =  LayerColor::create(this->getRandomColor(), visibleSize.width, visibleSize.height);
    this->colorLayer->setPosition(Vec2(origin.x ,
                                origin.y));
    this->addChild(colorLayer);
    
    ui::Button* trueItem = ui::Button::create("true.png","true_select.png");
    trueItem->setPosition(Vec2(origin.x + 15 + trueItem->getContentSize().width/2,
                               origin.y + 15 + trueItem->getContentSize().height/2));
    trueItem->addTouchEventListener( CC_CALLBACK_2(GameScene::menuTrueCallback, this) );
    this->addChild(trueItem);
    
    ui::Button* falseItem = ui::Button::create("false.png","false_select.png");
    falseItem->setPosition(Vec2(origin.x +  visibleSize.width - falseItem->getContentSize().width/2 - 15 ,
                                origin.y + 15 + falseItem->getContentSize().height/2));
    falseItem->addTouchEventListener( CC_CALLBACK_2(GameScene::menuFalseCallback, this) );
    this->addChild(falseItem);

    
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
     this->labelRow1 = Label::createWithTTF("10+1", "fonts/relay-black.ttf", 60);
    // position the label on the center of the screen
    this->labelRow1->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height/2 + labelRow1->getContentSize().height));
    this->row1Pos =  this->labelRow1->getPosition();

    // add the label as a child to this layer
    this->addChild(this->labelRow1, 1);
    
    
    this->labelRow2 = Label::createWithTTF("=12", "fonts/relay-black.ttf", 60);
    // position the label on the center of the screen
    this->labelRow2->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height/2 - 0.05*labelRow2->getContentSize().height));
    this->row2Pos =  this->labelRow2->getPosition();

    // add the label as a child to this layer
    this->addChild(this->labelRow2, 1);
    
    
    //add popup
    this->popup = Popup::create();
    addChild(popup,1000);
    
    //add progressbar
    
    Sprite* bar =  Sprite::create("bar.png");
   

    bar->setAnchorPoint(Vec2(-1, -0.5f));
    bar->setPosition(Vec2(0, 0));
    auto scale =  675.0f/640.0f ;
    log("this is a log %f" , scale);
    
    bar->setFlippedX(true);
    bar->setScale(scale);
    
    this->addChild(bar);

    fuelBar = ProgressTimer::create(bar);
    fuelBar->setType(ProgressTimer::Type::BAR);
     fuelBar->setScale(scale, 1);
    fuelBar->setAnchorPoint(Vec2(0, 0));
    fuelBar->setPosition(Vec2(origin.x, 0));
    fuelBar->setBarChangeRate(Vec2(1, 0)); // To make width 100% always
    fuelBar->setTag(1);                  // Tag our object for easy access
    fuelBar->setMidpoint(Vec2(0.0f, 0.1f));
//    this->addChild(fuelBar);
    fuelBar->setPercentage(100);
    
    this->newGame();
    
    return true;
}

void GameScene::newGame()
{
    this->updateNewQuestion();
}

void GameScene::updateNewQuestion()
{
    srand(time(NULL));
    std::string row1;
    this->numA = this->getRandomNumber() ;
    this->numB = this->getRandomNumber() ;
    
    row1 =  std::to_string(this->numA ) + "+" +   std::to_string(this->numB);
    this->labelRow1->setString(row1.c_str());
    
    std::string row2;
    int bigger = this->numA  > this->numB ? this->numA : this->numB ;
    auto ran =  rand() % 10;
    if(ran >= 5){
        this->numResult = this->getRandomResultNumber(bigger);
    }else{
        this->numResult = this->getRealResultNumber();
    }
    row2  = "=" +  std::to_string(this->numResult)  ;
    this->labelRow2->setString(row2.c_str());
    
    //update progress
     this->scheduleUpdate();
}

void GameScene::update(float delta) {
  
//    float percent = fuelBar->getPercentage();
//    percent -= 1.0f * delta;
//    fuelBar->setPercentage(percent);
//    
//    if (percent<= 0.0f) {
////        this->unscheduleUpdate();
//        percent = 100.0f ;
//        fuelBar->setPercentage(percent);
//    }
}

void GameScene::nextRound()
{
    this->labelRow1->stopAllActions();
    this->labelRow2->stopAllActions();
    
    //quest
    
    float timeMove = 0.2;
    auto moveOut = MoveTo::create(timeMove, Vec2(0, this->row1Pos.y));
    auto fadeOut = FadeOut::create(timeMove);
    
    auto firstSpawn = Spawn::createWithTwoActions(moveOut, fadeOut);
    auto callbackChangePosition =  CallFunc::create([&, this](){
        auto visibleSize = Director::getInstance()->getWinSize();
        this->labelRow1->setPosition(Vec2(visibleSize.width, this->labelRow1->getPosition().y));
        
        //update question
        this->updateNewQuestion();
        
    });
    auto moveIn = MoveTo::create(timeMove, Vec2(this->row1Pos.x, this->row1Pos.y));
    auto fadeIn = FadeIn::create(timeMove);
    auto secondSpawn = Spawn::createWithTwoActions(moveIn, fadeIn);
    auto sequence = Sequence::create(firstSpawn, callbackChangePosition, secondSpawn, nullptr);
    
    this->labelRow1->runAction(sequence);
    
    //result
    auto moveOut2 = MoveTo::create(timeMove, Vec2(0, this->row2Pos.y));
    auto fadeOut2 = FadeOut::create(timeMove);
    
    auto firstSpawn2 = Spawn::createWithTwoActions(moveOut2, fadeOut2);
    auto callbackChangePosition2 =  CallFunc::create([&, this](){
        auto visibleSize = Director::getInstance()->getWinSize();
        this->labelRow2->setPosition(Vec2(visibleSize.width, this->labelRow2->getPosition().y));
        
    });
    auto moveIn2 = MoveTo::create(timeMove, Vec2(this->row2Pos.x, this->row2Pos.y));
    auto fadeIn2 = FadeIn::create(timeMove);
    auto secondSpawn2 = Spawn::createWithTwoActions(moveIn2, fadeIn2);
    auto sequence2 = Sequence::create(firstSpawn2, callbackChangePosition2, secondSpawn2, nullptr);
 
    this->labelRow2->runAction(sequence2);

}

void GameScene::answareWrong()
{
    auto callback =  CallFunc::create([&, this](){
        this->popup->appear();
        
    });
    auto shake = CCShake::actionWithDuration(0.5f, 0.3f);
     auto sequence = Sequence::create(shake, callback, nullptr);
    SoundTool::getInstance()->playEffect("res/sound/fail.wav");
    this->runAction(sequence);
}

void GameScene::menuTrueCallback(Ref* pSender, cocos2d::ui::Widget::TouchEventType type)
{
    
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        
        if(this->numResult == this->getRealResultNumber()){
              SoundTool::getInstance()->playEffect("res/sound/scored.wav");
            this->nextRound();
        }else{
            this->answareWrong();
        }
    }
   
 
}


void GameScene::menuFalseCallback(Ref* pSender , cocos2d::ui::Widget::TouchEventType type)
{
    
    if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        if(this->numResult == this->getRealResultNumber()){
               this->answareWrong();
        }else{
             SoundTool::getInstance()->playEffect("res/sound/scored.wav");
            this->nextRound();
        }
    }
    
    
}

int GameScene::getRandomNumber()
{
      auto ran =  rand() % 10;
    if(ran > 8){
        auto ran2 =  rand() % 10;
        if(ran2 > 7){
            return this->getRandomBigNumber();
        }else{
              return this->getRandomMediumNumber();
        }
        
    }else{
        return this->getRandomSmallNumber();
    }
}

int GameScene::getRandomBigNumber()
{
      return  rand() % 8 + 8;
}

int GameScene::getRandomMediumNumber()
{
    return  rand() % 3 + 5;
}


int GameScene::getRandomSmallNumber()
{
    return  rand() % 5 + 1;
}

int GameScene::getRandomResultNumber(int max)
{
    int bound = 14 - max;
    return  rand() % bound + max;
}

int GameScene::getRealResultNumber( )
{
    return   this->numA +  this->numB;
}

cocos2d::Color4B GameScene:: getRandomColor()
{
    
    auto ran =  rand() % 8;
    switch (ran) {
        case 0:
            return Color4B::BLUE;
        case 1:
            return Color4B::YELLOW;
        case 2:
            return Color4B::GREEN;
        case 3:
            return Color4B::RED;
        case 4:
            return Color4B::MAGENTA;
        case 5:
            return Color4B::ORANGE;
        case 6:
            return Color4B::GRAY;
        case 7:
            return Color4B(200,0,0,255);
            
        default:
             return Color4B::BLUE;
    }
    
    
}




















