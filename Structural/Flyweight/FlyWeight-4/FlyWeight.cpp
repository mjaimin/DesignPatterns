#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

class FlyWeight
{
private:
    std::string m_intrinsicState;
public:
    FlyWeight( std::string intrinsicState ) : m_intrinsicState(intrinsicState){}
    virtual ~FlyWeight(void){}
    std::string GetIntrinsicState(  ){	return m_intrinsicState; }
    virtual void Operator(const std::string& extrinsicState){}
};

class ConcreteFlyWeight : public FlyWeight
{
public:
    ConcreteFlyWeight( std::string intrinsicState ):FlyWeight(intrinsicState){}
    virtual void Operator( const std::string& extrinsicState )
    {
        std::cout << "ConcreteFlyWeight:[" << this->GetIntrinsicState() << "]"
            << "[" << extrinsicState << "]" << std::endl;
    }
    ~ConcreteFlyWeight(){};
};

class FlyWeightFactory
{
private:
    std::vector<FlyWeight *> fly;
public:
    FlyWeightFactory(void){}
    ~FlyWeightFactory(void){}

    FlyWeight* GetFlyWeight( const std::string& key )
    {
        std::vector<FlyWeight *>::iterator iter;
        for(iter = fly.begin(); iter != fly.end(); iter++)
        {
            if((*iter)->GetIntrinsicState() == key)
            {
                std::cout << "Already have :" << key << std::endl;
                return *iter;
            }
        }

        FlyWeight* fw = new ConcreteFlyWeight(key);
        fly.push_back(fw);
        return fw;
    }
};

void main()
{
    FlyWeightFactory* fwFactory = new FlyWeightFactory();
    fwFactory->GetFlyWeight("Hello");
    fwFactory->GetFlyWeight("World");
    fwFactory->GetFlyWeight("Me");
    fwFactory->GetFlyWeight("World");
    fwFactory->GetFlyWeight("Hello")->Operator(" Great");

    system("pause");

}