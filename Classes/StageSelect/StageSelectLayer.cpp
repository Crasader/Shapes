#include "StageSelectLayer.hpp"
#include "TitleLayer.hpp"
#include "GameLayer.hpp"

using namespace GameSequence;

Scene* StageSelectLayer::createScene()
{
    Scene* scene=Scene::create();
    scene->retain();
    scene->autorelease();
    
    StageSelectLayer* stageSelectLayer=StageSelectLayer::create();
    scene->addChild(stageSelectLayer);
    
    return scene;
}

StageSelectLayer* StageSelectLayer::create()
{
    StageSelectLayer* stageSelectLayer=new StageSelectLayer();
    if(!stageSelectLayer->init()) return nullptr;
    stageSelectLayer->autorelease();
    
    return stageSelectLayer;
}

bool StageSelectLayer::init()
{
    if(!BaseLayer::init()) return false;
    return true;
}

void StageSelectLayer::onEnter()
{
    BaseLayer::onEnter();
    
    const int fontSize=36;
    const float menuWidth=50;
    const float topHeight=650;
    LabelTTF* titleLabel=LabelTTF::create("to title","arial",fontSize);
    MenuItemLabel* toTitleLabel=
    MenuItemLabel::create(titleLabel,CC_CALLBACK_1(StageSelectLayer::toTitle,this));
    toTitleLabel->setPosition(Vec2(0,topHeight));
    
    LabelTTF* GameLabel=LabelTTF::create("to Game","arial",fontSize);
    MenuItemLabel* toGameLabel=
    MenuItemLabel::create(GameLabel,CC_CALLBACK_1(StageSelectLayer::toGame,this));
    toGameLabel->setPosition(Vec2(0,topHeight - fontSize - menuWidth));
    
    Menu* menu=Menu::create(toTitleLabel,toGameLabel,NULL);
    Size windowSize=Director::getInstance()->getVisibleSize();
    menu->setPosition(Vec2(windowSize.width/2,0));
    addChild(menu);
    
}

StageSelectLayer::StageSelectLayer():
BaseLayer::BaseLayer()
{
    
}

StageSelectLayer::~StageSelectLayer()
{
    
}

void StageSelectLayer::toTitle(Ref* sender)
{
    Scene* scene=TitleLayer::createScene();
    Director::getInstance()->replaceScene(scene);
}

void StageSelectLayer::toGame(Ref* sender)
{
    Scene* scene=GameLayer::createScene();
    Director::getInstance()->replaceScene(scene);
}

bool StageSelectLayer::onTouchBegan(Touch* touch,Event* event)
{
    
    return true;
}

void StageSelectLayer::onTouchMoved(Touch* touch,Event* event)
{
    
}

void StageSelectLayer::onTouchEnded(Touch* touch,Event* event)
{
    
}

void StageSelectLayer::onTouchCancelled(Touch* touch,Event* event)
{
    
}
