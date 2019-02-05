#include "ObstracleFactory.hpp"
#include "LineObstracle.hpp"
#include "CircleObstracle.hpp"
#include "CSVFileLoader.hpp"
using namespace Game;

ObstracleFactory* ObstracleFactory::instance=0;

ObstracleFactory::ObstracleFactory()
{
    mTimingList=loadCSVFile("Different Heaven.mp3.csv");
    mIt=mTimingList.begin();
    cout << "factory constructor" <<endl;
}
ObstracleFactory::~ObstracleFactory(){}
ObstracleFactory::ObstracleFactory(const ObstracleFactory& ){}

ObstracleFactory* ObstracleFactory::getInstance()
{
    if(instance==nullptr) instance=new ObstracleFactory();
    return instance;
}

Obstracle* ObstracleFactory::generateObstracle(Obstracles type,Vec2 initPos)
{
    Obstracle* obst=nullptr;
    switch (type)
    {
        case O_Line:
            obst=LineObstracle::create(initPos);
            break;
        case O_Circle:
            cout << "generate"<<endl;
            obst=CircleObstracle::create(initPos);
            break;
        default:
            cerr << "generateObstracleの引数が違います" << endl;
            break;
    }
    mIt++;
    return obst;
}

bool ObstracleFactory::checkGenerateTiming(float passedTime)
{
    cout << "it: "<< (*mIt) <<endl;
    cout << "passedTime: " <<passedTime <<endl;
    if((*mIt)<=passedTime && mIt!=mTimingList.end())
    {
        return true;
    }
    return false;
}

void ObstracleFactory::destroy()
{
    delete instance;
    instance=nullptr;
}
