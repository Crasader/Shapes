#include "LineObstracle.hpp"

using namespace Game;

LineObstracle::LineObstracle():
Obstracle::Obstracle()
{}

LineObstracle* LineObstracle::create(Vec2 initPos)
{
    LineObstracle* lineObstracle=new LineObstracle();
    if(!lineObstracle || !lineObstracle->init(initPos)) return nullptr;
    
    return lineObstracle;
}

bool LineObstracle::init(Vec2 initPos)
{
    if(!Obstracle::init()) return nullptr;
    autorelease();
    
    setTextureRect(Rect(0,0,mWidth,mHeight));
    setColor(Color3B(200,30,30));
    setPosition(initPos);
    cout << "in init"<<endl;
    return true;
}

LineObstracle::~LineObstracle()
{
    
}

void LineObstracle::doAnimation()
{
    auto fadein=FadeIn::create(0.2f);
    int sign=cocos2d::random()%2 *2 -1;
    Vec2 pos=getPosition();
    auto move=MoveTo::create(5.0f,Vec2(pos.x,-100));
    auto rotate=RotateBy::create(5.0f,sign*720);
   // auto tint=TintTo::create(1.0f,0.0f,0.0f,0.0f);
    auto spawn=Spawn::create(fadein,move,rotate,nullptr);
    //auto sequence=Sequence::create(fadein,spawn,nullptr);
    this->runAction(spawn);
}
void LineObstracle::update()
{
}
