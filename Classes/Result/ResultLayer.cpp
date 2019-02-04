#include "ResultLayer.hpp"
#include "StageSelectLayer.hpp"
#include "GameLayer.hpp"

using namespace GameSequence;

Scene* ResultLayer::createScene()
{
    Scene* scene=Scene::create();
    scene->retain();
    scene->autorelease();
    
    ResultLayer* resultLayer=ResultLayer::create();
    scene->addChild(resultLayer);
    
    return scene;
}

ResultLayer* ResultLayer::create()
{
    ResultLayer* resultLayer=new ResultLayer();
    if(!resultLayer->init()) return nullptr;
    resultLayer->autorelease();
    
    return resultLayer;
}

bool ResultLayer::init()
{
    if(!BaseLayer::init()) return false;
    return true;
}

void ResultLayer::onEnter()
{
    BaseLayer::onEnter();
    
    auto label = Label::createWithTTF("ResultScene Layer", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(200,300));
    addChild(label);
    
    const int fontSize=36;
    const float menuWidth=50;
    const float topHeight=650;
    LabelTTF* stageSelectLabel=LabelTTF::create("to StageSelect","arial",fontSize);
    MenuItemLabel* toStageSelectLabel=
    MenuItemLabel::create(stageSelectLabel,CC_CALLBACK_1(ResultLayer::toStageSelect,this));
    toStageSelectLabel->setPosition(Vec2(0,topHeight));
    
    LabelTTF* GameLabel=LabelTTF::create("to Game","arial",fontSize);
    MenuItemLabel* toGameLabel=
    MenuItemLabel::create(GameLabel,CC_CALLBACK_1(ResultLayer::toGame,this));
    toGameLabel->setPosition(Vec2(0,topHeight - fontSize - menuWidth));
    
    Menu* menu=Menu::create(toStageSelectLabel,toGameLabel,NULL);
    Size windowSize=Director::getInstance()->getVisibleSize();
    menu->setPosition(Vec2(windowSize.width/2,0));
    addChild(menu);
    
}

ResultLayer::ResultLayer():
BaseLayer::BaseLayer()
{
    
}

ResultLayer::~ResultLayer()
{
    
}

void ResultLayer::toStageSelect(Ref *sender)
{
    Scene* scene=StageSelectLayer::createScene();
    Director::getInstance()->replaceScene(scene);
}
void ResultLayer::toGame(Ref *sender)
{
    Scene* scene=GameLayer::createScene();
    Director::getInstance()->replaceScene(scene);
}

bool ResultLayer::onTouchBegan(Touch* touch,Event* event)
{
    
    return true;
}

void ResultLayer::onTouchMoved(Touch* touch,Event* event)
{
    
}

void ResultLayer::onTouchEnded(Touch* touch,Event* event)
{
    
}

void ResultLayer::onTouchCancelled(Touch* touch,Event* event)
{
    
}
