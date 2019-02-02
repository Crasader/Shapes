#include "CreditLayer.hpp"
#include "TitleLayer.hpp"

using namespace GameSequence;

Scene* CreditLayer::createScene()
{
    Scene* scene=Scene::create();
    scene->retain();
    scene->autorelease();
    
    CreditLayer* creditLayer=CreditLayer::create();
    scene->addChild(creditLayer);
    
    return scene;
}

CreditLayer* CreditLayer::create()
{
    CreditLayer* creditLayer=new CreditLayer();
    if(!creditLayer->init()) return nullptr;
    creditLayer->autorelease();
    
    return creditLayer;
}

bool CreditLayer::init()
{
    if(!BaseLayer::init()) return false;
    return true;
}

void CreditLayer::onEnter()
{
    BaseLayer::onEnter();
    
    createLabels();
}

CreditLayer::CreditLayer():
BaseLayer::BaseLayer()
{
    
}

CreditLayer::~CreditLayer()
{
    
}

void CreditLayer::changeScene()
{
    Scene* scene=TitleLayer::createScene();
    Director::getInstance()->replaceScene(scene);
}

void CreditLayer::createLabels()
{
    const int fontSize=20;
    LabelTTF* message=LabelTTF::create("Please tap anywhere...","arial",fontSize);
    Size windowSize=Director::getInstance()->getVisibleSize();
    message->setPosition(Vec2(windowSize.width/2,150));
    addChild(message);
}
bool CreditLayer::onTouchBegan(Touch* touch,Event* event)
{
    changeScene();
    return true;
}

void CreditLayer::onTouchMoved(Touch* touch,Event* event)
{
    
}

void CreditLayer::onTouchEnded(Touch* touch,Event* event)
{
    
}

void CreditLayer::onTouchCancelled(Touch* touch,Event* event)
{
    
}
