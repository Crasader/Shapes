#include "CircleObstracle.hpp"

using namespace Game;

CircleObstracle::CircleObstracle():
Obstracle::Obstracle(),
mCircle(nullptr),
mColor(Color4F(1.0f,0.0f,0.0f,1.0f))
{}

CircleObstracle* CircleObstracle::create(Vec2 initPos)
{
    CircleObstracle* circleObstracle=new CircleObstracle();
    if(!circleObstracle || !circleObstracle->init(initPos)) return nullptr;
    
    return circleObstracle;
}

bool CircleObstracle::init(Vec2 initPos)
{
    if(!Obstracle::init()) return nullptr;
    autorelease();
    
    mCircle=DrawNode::create();
    mCircle->drawDot(Vec2::ZERO,mRadius,Color4F(1.0f,0.2f,0.2f,1.0f));
    addChild(mCircle);

    setPosition(initPos);
    cout << "in init"<<endl;
    return true;
}

CircleObstracle::~CircleObstracle()
{
    
}

void CircleObstracle::doAnimation()
{
    if(mColor.a>0.01)
    {
        cout << "in doAnimation"<<endl;
        mCircle->clear();
        mColor.a-=0.01f;
        mCircle->drawDot(Vec2::ZERO,mRadius,mColor);
        
    }else
    {
        removeFromParentAndCleanup(true);
    }
  
    
}
void CircleObstracle::update()
{
    doAnimation();
}

bool CircleObstracle::isActive(Size windowSize) const
{
    if(mColor.a<0.01)  return false;
    return true;
}
