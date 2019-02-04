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
    if(_position.x<0 || _position.x>windowSize.width ||
       _position.y<0 || _position.y>windowSize.height)
        return false;
    
    return true;
}

