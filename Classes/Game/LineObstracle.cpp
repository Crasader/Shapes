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
    setColor(Color3B(150,30,30));
    setPosition(initPos);
    cout << "in init"<<endl;
    return true;
}

LineObstracle::~LineObstracle()
{
    
}

void LineObstracle::update()
{
    cout << "in update"<<endl;
    
    Vec2 position=getPosition();
    position.y+=5;
    //cout << _position.y <<endl;
    this->setPosition(position);
    
    //auto up=MoveTo::create(3.0f,Vec2(300,1000));
    //this->runAction(up);
}
