#include "GameLayer.hpp"
#include "StageSelectLayer.hpp"
#include "ResultLayer.hpp"
#include "GameOverLayer.hpp"

#include "ObstracleFactory.hpp"

using namespace GameSequence;
using namespace Game;
Scene* GameLayer::createScene()
{
    Scene* scene=Scene::create();
    scene->retain();
    scene->autorelease();
    
    GameLayer* gameLayer=GameLayer::create();
    scene->addChild(gameLayer);
    
    return scene;
}

GameLayer* GameLayer::create()
{
    GameLayer* gameLayer=new GameLayer();
    if(!gameLayer->init()) return nullptr;
    gameLayer->autorelease();
    
    return gameLayer;
}

bool GameLayer::init()
{
    if(!BaseLayer::init()) return false;
    return true;
}

void GameLayer::onEnter()
{
    BaseLayer::onEnter();
    
    SimpleAudioEngine* engine=SimpleAudioEngine::getInstance();
    engine->preloadBackgroundMusic("Different Heaven.mp3");
    engine->setBackgroundMusicVolume(1.0f);
    
    /*
    auto label = Label::createWithTTF("GameScene Layer", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(200,300));
    addChild(label);
  
    const int fontSize=36;
    const float menuWidth=50;
    const float topHeight=650;
    LabelTTF* StageSelectLabel=LabelTTF::create("to StageSelect","arial",fontSize);
    MenuItemLabel* toStageSelectLabel=
    MenuItemLabel::create(StageSelectLabel,CC_CALLBACK_1(GameLayer::toStageSelect,this));
    toStageSelectLabel->setPosition(Vec2(0,topHeight));
    
    LabelTTF* resultLabel=LabelTTF::create("to result","arial",fontSize);
    MenuItemLabel* toResultLabel=
    MenuItemLabel::create(resultLabel,CC_CALLBACK_1(GameLayer::toResult,this));
    toResultLabel->setPosition(Vec2(0,topHeight - fontSize - menuWidth));
    
    LabelTTF* gameOverLabel=LabelTTF::create("to GameOver","arial",fontSize);
    MenuItemLabel* toGameOverLabel=
    MenuItemLabel::create(gameOverLabel,CC_CALLBACK_1(GameLayer::toGameOver,this));
    toGameOverLabel->setPosition(Vec2(0,topHeight - fontSize*2 - menuWidth*2));
    
    Menu* menu=Menu::create(toStageSelectLabel,toResultLabel,toGameOverLabel,NULL);
    Size windowSize=Director::getInstance()->getVisibleSize();
    menu->setPosition(Vec2(windowSize.width/2,0));
    addChild(menu);
     */
    /*
    ObstracleFactory* factory=ObstracleFactory::getInstance();
    Obstracle* lineObstracle=factory->generateObstracle(O_Line,Vec2(200,200),3.0);
    mObstracleList.push_back(lineObstracle);
    cout <<mObstracleList.size()<< endl;
    addChild(lineObstracle);
    
    */
    Obstracle* circleObstracle=ObstracleFactory::
    getInstance()->generateObstracle(O_Circle,Vec2(300,200));
    mObstracleList.push_back(circleObstracle);
    cout <<mObstracleList.size()<< endl;
    addChild(circleObstracle);
    circleObstracle->doAnimation();
    
    
    engine->playBackgroundMusic("Different Heaven.mp3",false);
    scheduleUpdate();
}

void GameLayer::update(float dt)
{
    cout << "gameLayer::update" <<endl;
    mPassedTime+=dt;
    
    
    if(ObstracleFactory::getInstance()->checkGenerateTiming(mPassedTime))
    {
        int initPosX=cocos2d::random<int>(20,620);
        int initPosY=cocos2d::random<int>(100,1100);
        //Obstracle* obstracle=ObstracleFactory::getInstance()
        //->generateObstracle(O_Line,Vec2(initPosX,1100));
        Obstracle* obstracle=ObstracleFactory::getInstance()
        ->generateObstracle(O_Circle,Vec2(initPosX,initPosY));
        mObstracleList.push_back(obstracle);
        cout <<mObstracleList.size()<< endl;
        addChild(obstracle);
        obstracle->doAnimation();
    }
    
    list<Obstracle*>::iterator it;
    for(it=mObstracleList.begin();it!=mObstracleList.end(); )
    {
        if((*it)->isActive(Director::getInstance()->getVisibleSize()))
        {
            (*it)->update();
            it++;
        }
        else
        {
            cout << "remove"<<endl;
            (*it)->removeFromParentAndCleanup(true);
            it=mObstracleList.erase(it);
        }
    }
    cout << "size: " << mObstracleList.size() <<endl;
    
}
GameLayer::GameLayer():
BaseLayer::BaseLayer(),
mPassedTime(0)
{
    
}

GameLayer::~GameLayer()
{
    cout << "~GameLayer" <<endl;
    mObstracleList.clear();
    ObstracleFactory::destroy();
}

void GameLayer::toStageSelect(Ref* sender)
{
    Scene* scene=StageSelectLayer::createScene();
    Director::getInstance()->replaceScene(scene);
}
void GameLayer::toResult(Ref* sender)
{
    Scene* scene=ResultLayer::createScene();
    Director::getInstance()->replaceScene(scene);
}
void GameLayer::toGameOver(Ref* sender)
{
    Scene* scene=GameOverLayer::createScene();
    Director::getInstance()->replaceScene(scene);
}
bool GameLayer::onTouchBegan(Touch* touch,Event* event)
{
    return true;
}

void GameLayer::onTouchMoved(Touch* touch,Event* event)
{
    
}

void GameLayer::onTouchEnded(Touch* touch,Event* event)
{
    
}

void GameLayer::onTouchCancelled(Touch* touch,Event* event)
{
    
}
