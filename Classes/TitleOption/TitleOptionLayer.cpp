#include "TitleOptionLayer.hpp"
#include "TitleLayer.hpp"

using namespace GameSequence;

Scene* TitleOptionLayer::createScene()
{
    Scene* scene=Scene::create();
    scene->retain();
    scene->autorelease();
    
    TitleOptionLayer* titleOptionLayer=TitleOptionLayer::create();
    scene->addChild(titleOptionLayer);
    
    return scene;
}

TitleOptionLayer* TitleOptionLayer::create()
{
    TitleOptionLayer* titleOptionLayer=new TitleOptionLayer();
    if(!titleOptionLayer->init()) return nullptr;
    titleOptionLayer->autorelease();
    
    return titleOptionLayer;
}

bool TitleOptionLayer::init()
{
    if(!BaseLayer::init()) return false;
    return true;
}

void TitleOptionLayer::onEnter()
{
    BaseLayer::onEnter();
    
    auto label = Label::createWithTTF("TitleOptionScene Layer", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(200,300));
    addChild(label);
    
}

TitleOptionLayer::TitleOptionLayer():
BaseLayer::BaseLayer()
{
    
}

TitleOptionLayer::~TitleOptionLayer()
{
    
}

void TitleOptionLayer::changeScene()
{
    Scene* scene=TitleLayer::createScene();
    Director::getInstance()->replaceScene(scene);
}

bool TitleOptionLayer::onTouchBegan(Touch* touch,Event* event)
{
    changeScene();
    return true;
}

void TitleOptionLayer::onTouchMoved(Touch* touch,Event* event)
{
    
}

void TitleOptionLayer::onTouchEnded(Touch* touch,Event* event)
{
    
}

void TitleOptionLayer::onTouchCancelled(Touch* touch,Event* event)
{
    
}
