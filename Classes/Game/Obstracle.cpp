#include "Obstracle.hpp"

using namespace Game;

Obstracle::Obstracle():
mActive(false)
{}

Obstracle::~Obstracle()
{
    
}

bool Obstracle::init()
{
    if(!Sprite::init()) return false;
    return true;
}

void Obstracle::update()
{
    cout << "Obstracle update"<<endl;
}
bool Obstracle::isActive(Size windowSize) const
{
    Vec2 pos=getPosition();
    if(pos.x<0 || pos.x>windowSize.width ||
       pos.y<0 || pos.y>windowSize.height)
        return false;
    
    return true;
}

