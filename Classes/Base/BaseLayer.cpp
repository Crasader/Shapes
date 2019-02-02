#include "BaseLayer.hpp"

using namespace GameSequence;

bool BaseLayer::init()
{
    if(!Layer::init()) return false;
    
    return true;
}

void BaseLayer::onEnter()
{
    Layer::onEnter();
    
    EventListenerTouchOneByOne* baseListener=EventListenerTouchOneByOne::create();
    baseListener->setSwallowTouches(true);
    baseListener->onTouchBegan=CC_CALLBACK_2(BaseLayer::onTouchBegan,this);
    baseListener->onTouchMoved=CC_CALLBACK_2(BaseLayer::onTouchMoved,this);
    baseListener->onTouchEnded=CC_CALLBACK_2(BaseLayer::onTouchEnded,this);
    baseListener->onTouchCancelled=CC_CALLBACK_2(BaseLayer::onTouchCancelled,this);
    
    Director::getInstance()->getEventDispatcher()
    ->addEventListenerWithSceneGraphPriority(baseListener,this);
    
    
}
BaseLayer::BaseLayer()
{
    
}

