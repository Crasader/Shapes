#include "CSVFileCreate.hpp"
#include <fstream>
#include "SimpleAudioEngine.h"
#include <cassert>

using namespace CocosDenshion;

Scene* CSVFileCreate::createScene(string filename)
{
    Scene* scene=Scene::create();
    scene->retain();
    scene->autorelease();
    CSVFileCreate* cSVFileCreate=CSVFileCreate::create(filename);
    scene->addChild(cSVFileCreate);
    
    return scene;
}

CSVFileCreate* CSVFileCreate::create(string filename)
{
    CSVFileCreate* cSVFileCreate=new CSVFileCreate(filename);
    if (!cSVFileCreate->init() ) return nullptr;
    cSVFileCreate->autorelease();
    
    return cSVFileCreate;
}

bool CSVFileCreate::init()
{
    if( !BaseLayer::init()) return false;
    return true;
}

void CSVFileCreate::onEnter()
{
    BaseLayer::onEnter();

    Size windowSize=Director::getInstance()->getVisibleSize();
    LayerColor* bg=LayerColor::create(Color4B::WHITE,windowSize.width,windowSize.height);
    addChild(bg);
    
    auto label = Label::createWithTTF("Let's make" + mFilename+ " Music File" ,
                                      "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(windowSize.width/2,windowSize.height/2));
    label->setColor(Color3B(100,100,200));
    addChild(label);
    
    auto message=Label::createWithTTF("タップすると時間を " +mFilename+ " に記録する" ,
                                      "fonts/ゴシック.ttf",18);
    message->setPosition(Vec2(windowSize.width/2,(windowSize.height*(0.25f) )));
    message->setColor(Color3B(50,125,200));
    addChild(message);
    
    string musicFilename("/Users/sugiharayuukana/cocos2d-x/Game/Shapes_and_Beats/Resources/musicfiles/"+mFilename+".csv");
    
    
    ofs=ofstream(musicFilename);
    if(!ofs)
    {
        cerr << musicFilename << " connot open." << endl;
        exit(1);
    }
    
    SimpleAudioEngine* engine=SimpleAudioEngine::getInstance();
    engine->preloadBackgroundMusic(mFilename.c_str());
    engine->setBackgroundMusicVolume(1.0f);
    
    engine->playBackgroundMusic(mFilename.c_str(),false);
    scheduleUpdate();
}

void CSVFileCreate::update(float dt)
{
    if(isTouched)
    {
        ofs << mTime << ",";
        ofs.flush();
        isTouched=false;
    }
    mTime+=(double) dt;
}

CSVFileCreate::CSVFileCreate(string filename):
BaseLayer::BaseLayer(),
mFilename(filename),
isTouched(false),
mTime(0)
{
    
}

CSVFileCreate::~CSVFileCreate()
{
    
}


bool CSVFileCreate::onTouchBegan(Touch* touch,Event* event)
{
    isTouched=true;
    cout << "time is: " << mTime <<endl;
    return true;
}

void CSVFileCreate::onTouchMoved(Touch* touch,Event* event)
{
    
}

void CSVFileCreate::onTouchEnded(Touch* touch,Event* event)
{
    
}

void CSVFileCreate::onTouchCancelled(Touch* touch,Event* event)
{
    
}
