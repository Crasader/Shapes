#ifndef CSVFileCreate_hpp
#define CSVFileCreate_hpp

#include "BaseLayer.hpp"
#include <fstream>

using namespace GameSequence;


class CSVFileCreate:public BaseLayer
{
public:
    static Scene* createScene(string filename);
    static CSVFileCreate* create(string filename);
    bool init();
    void onEnter();
    void update(float dt);
    
    bool onTouchBegan(Touch* touch,Event* event);
    void onTouchMoved(Touch* touch,Event* event);
    void onTouchEnded(Touch* touch,Event* event);
    void onTouchCancelled(Touch* touch,Event* event);
private:
    string mFilename;
    bool isTouched;
    double mTime;
    ofstream ofs;
    
    CSVFileCreate(string filename);
    ~CSVFileCreate();
    CSVFileCreate(const CSVFileCreate& );
    
};

#endif /* CSVFileCreate_hpp */
