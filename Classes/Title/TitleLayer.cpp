#include "TitleLayer.hpp"
#include "CreditLayer.hpp"
#include "TitleOptionLayer.hpp"
#include "StageSelectLayer.hpp"

#include <vector>

using namespace GameSequence;

Scene* TitleLayer::createScene()
{
    Scene* scene=Scene::create();
    scene->retain();
    scene->autorelease();
    
    TitleLayer* titleLayer=TitleLayer::create();
    scene->addChild(titleLayer);
    
    return scene;
}

TitleLayer* TitleLayer::create()
{
    TitleLayer* titleLayer=new TitleLayer();
    titleLayer->init();
    titleLayer->autorelease();
    
    return titleLayer;
}

bool TitleLayer::init()
{
    if(!BaseLayer::init()) return false;
    cout <<"in TitleLayer::init" <<endl;
    return true;
}

void TitleLayer::onEnter()
{
    BaseLayer::onEnter();
    auto label = Label::createWithTTF("TitleScene Layer", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(200,300));
    addChild(label);
    
    createMenu();
    
}

TitleLayer::TitleLayer():
BaseLayer::BaseLayer()
{
    
}

TitleLayer::~TitleLayer()
{
    
}


void TitleLayer::createMenu()
{
    const int fontSize=36;
    const float menuWidth=50;
    const float topHeight=650;
    LabelTTF* creditLabel=LabelTTF::create("to Credit","arial",fontSize);
    MenuItemLabel* toCreditLabel=
    MenuItemLabel::create(creditLabel,CC_CALLBACK_1(TitleLayer::toCredit,this));
    toCreditLabel->setPosition(Vec2(0,topHeight));
    
    LabelTTF* optionLabel=LabelTTF::create("to option","arial",fontSize);
    MenuItemLabel* toOptionLabel=
    MenuItemLabel::create(optionLabel,CC_CALLBACK_1(TitleLayer::toTitleOption,this));
    toOptionLabel->setPosition(Vec2(0,topHeight - fontSize - menuWidth));
    
    LabelTTF* stageSelectLabel=LabelTTF::create("to StageSelect","arial",fontSize);
    MenuItemLabel* toStageSelectLabel=
    MenuItemLabel::create(stageSelectLabel,CC_CALLBACK_1(TitleLayer::toStageSelect,this));
    toStageSelectLabel->setPosition(Vec2(0,topHeight - fontSize*2 - menuWidth*2));
    
    Menu* menu=Menu::create(toCreditLabel,toOptionLabel,toStageSelectLabel,NULL);
    Size windowSize=Director::getInstance()->getVisibleSize();
    menu->setPosition(Vec2(windowSize.width/2,0));
    addChild(menu);
}
void TitleLayer::toCredit(Ref* sender)
{
    Scene* scene=CreditLayer::createScene();
    Director::getInstance()->replaceScene(scene);
}

void TitleLayer::toTitleOption(Ref *sender)
{
    Scene* scene=TitleOptionLayer::createScene();
    Director::getInstance()->replaceScene(scene);
}

void TitleLayer::toStageSelect(Ref *sender)
{
    Scene* scene=StageSelectLayer::createScene();
    Director::getInstance()->replaceScene(scene);
}


bool TitleLayer::onTouchBegan(Touch* touch,Event* event)
{
    cout << "touch.x: " << touch->getLocation().x<<endl;
    cout << "touch.y: " << touch->getLocation().y<<endl;
    return true;
}

void TitleLayer::onTouchMoved(Touch* touch,Event* event)
{
    
}

void TitleLayer::onTouchEnded(Touch* touch,Event* event)
{
    
}

void TitleLayer::onTouchCancelled(Touch* touch,Event* event)
{
    
}
