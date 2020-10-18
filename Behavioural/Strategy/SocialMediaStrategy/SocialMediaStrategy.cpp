#include <iostream>
#include <stdio.h>

class ISocialMediaStrategy
{
    public:
        virtual void connectTo(std::string friendName) = 0;
};


class SocialMediaContext
{
    ISocialMediaStrategy* smStrategy;
    public:
    void setSocialmediaStrategy(ISocialMediaStrategy* smStrategy) {
        this->smStrategy = smStrategy;
    }

    void connect(std::string name) {
        smStrategy->connectTo(name);
    }
};



class FacebookStrategy: public ISocialMediaStrategy {
    public:
        void connectTo(std::string friendName) {
            std::cout << "Connecting with " + friendName + " through Facebook" << std::endl;
        }
};



class GooglePlusStrategy: public ISocialMediaStrategy {
    public:
        void connectTo(std::string friendName) {
            std::cout << "Connecting with " + friendName + " through GooglePlus" << std::endl;
        }
};



class TwitterStrategy: public ISocialMediaStrategy {
    public:
        void connectTo(std::string friendName) {
            std::cout << "Connecting with " + friendName + " through Twitter" << std::endl;
        }
};



class OrkutStrategy: public ISocialMediaStrategy {
    public:
        void connectTo(std::string friendName) {
            std::cout << "Connecting with " + friendName + " through Orkut [not possible though :)]" << std::endl;
        }
};

main()
{

    // Creating social Media Connect Object for connecting with friend by
    // any social media strategy.
    SocialMediaContext* context = new SocialMediaContext();

    // Setting Facebook strategy.
    context->setSocialmediaStrategy(new FacebookStrategy());
    context->connect("Lokesh");

    std::cout << "====================" << std::endl;

    // Setting Twitter strategy.
    context->setSocialmediaStrategy(new TwitterStrategy());
    context->connect("Lokesh");

    std::cout << "====================" << std::endl;

    // Setting GooglePlus strategy.
    context->setSocialmediaStrategy(new GooglePlusStrategy());
    context->connect("Lokesh");

    std::cout << "====================" << std::endl;

    // Setting Orkut strategy.
    context->setSocialmediaStrategy(new OrkutStrategy());
    context->connect("Lokesh");
}
