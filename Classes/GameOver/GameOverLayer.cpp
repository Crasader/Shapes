#include "GameOverLayer.hpp"
#include "StageSelectLayer.hpp"
#include "GameLayer.hpp"

using namespace GameSequence;

Scene* GameOverLayer::createScene()
{
    Scene* scene=Scene::create();
    scene->retain();
    scene->autorelease();
    
    GameOverLayer* gameOverLayer=GameOverLayer::create();
    scene->addChild(gameOverLayer);
    
    return scene;
}

GameOverLayer* GameOverLayer::create()
{
    GameOverLayer* gameOverLayer=new GameOverLayer();
    if(!gameOverLayer->init()) return nullptr;
    gameOverLayer->autorelease();
    
    return gameOverLayer;
}

bool GameOverLayer::init()
{
    if(!BaseLayer::init()) return false;
    return true;
}

void GameOverLayer::onEnter()
{
    BaseLayer::onEnter();
    
    auto label = Label::createWithTTF("GameOverScene Layer", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(200,300));
    addChild(label);
    
    const int fontSize=36;
    const float menuWidth=50;
    const float topHeight=650;
    LabelTTF* stageSelectLabel=LabelTTF::create("to StageSelect","arial",fontSize);
    MenuItemLabel* toStageSelectLabel=
    MenuItemLabel::create(stageSelectLabel,
                          CC_CALLBACK_1(GameOverLayer::toStageSelect,this));
    toStageSelectLabel->setPosition(Vec2(0,topHeight));
    
    LabelTTF* GameLabel=LabelTTF::create("to Game","arial",fontSize);
    MenuItemLabel* toGameLabel=
    MenuItemLabel::create(GameLabel,
                          CC_CALLBACK_1(GameOverLayer::toGame,this));
    toGameLabel->setPosition(Vec2(0,topHeight - fontSize - menuWidth));
    
    Menu* menu=Menu::create(toStageSelectLabel,toGameLabel,NULL);
    Size windowSize=Director::getInstance()->getVisibleSize();
    menu->setPosition(Vec2(windowSize.width/2,0));
    addChild(menu);
    
}

GameOverLayer::GameOverLayer():
BaseLayer::BaseLayer()
{
    
}

GameOverLayer::~GameOverLayer()
{
    
}

void GameOverLayer::toStageSelect(Ref *sender)
{
    Scene* scene=StageSelectLayer::createScene();
    Director::getInstance()->replaceScene(scene);
}
void GameOverLayer::toGame(Ref *sender)
{
    Scene* scene=GameLayer::createScene();
    Director::getInstance()->replaceScene(scene);
}

bool GameOverLayer::onTouchBegan(Touch* touch,Event* event)
{
    
    return true;
}

void GameOverLayer::onTouchMoved(Touch* touch,Event* event)
{
    
}

void GameOverLayer::onTouchEnded(Touch* touch,Event* event)
{
    
}

void GameOverLayer::onTouchCancelled(Touch* touch,Event* event)
{
    
}

