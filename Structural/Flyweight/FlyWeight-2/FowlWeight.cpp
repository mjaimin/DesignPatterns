#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <sstream> 

static const int MAX_BIRDS = 100;
static const double MIN_WIEGHT = 0.1;

// Flyweight
class Fowl{
public: 
    enum type{mallard, redhead, rubber, model, last};

protected: 
    Fowl() { }
public: 

    virtual ~Fowl() { }
    virtual std::string quack()  = 0;
    virtual std::string swim()  = 0;
    virtual std::string toString()  = 0;
};

// Unshared ConcreteFlyweight
class Bird : public Fowl {
private: 
    Fowl* m_fowl;
    int m_number;
    double m_weight;

    Bird( const Bird& ); // Disable copy constructor
    void operator=( const Bird& ); // Disable assignment operator

public: 
    Bird( Fowl* fowl, int number = 0, double weight = 0.0 ) :
      m_fowl( fowl ), m_number( number ), m_weight( weight ) {      }
      std::string quack()  {
          return m_fowl->quack();
      }
      std::string swim()  {
          return m_fowl->swim();
      }
      double getWeight()  {
          return m_weight;
      }
      double getNumber()  {
          return m_number;
      }
      std::string toString()  {
          std::stringstream value; 
          value << "Bird #"<< m_number + 1 << ", ";
          value << "weighs " << m_weight << " pounds, ";
          value << "is a " << m_fowl->toString();
          return value.str();
      }
};

// ConcreteFlyweights
class MallardDuck : public Fowl {

private: std::string m_type;
         std::string m_sound;
         std::string m_swim;

public:
    MallardDuck() : m_type( "Mallard Duck" ), m_sound( "Quack" ), m_swim( "swims" ) {    }

    std::string quack(){return m_sound;}
    std::string swim(){return m_swim;}
    std::string toString(){return m_type.c_str();}
};

class ModelDuck : public Fowl {

private: std::string m_type;
         std::string m_sound;
         std::string m_swim;

public:
    ModelDuck(): m_type( "Model duck" ), m_sound( "<< Silence >>" ), m_swim( "sinks" ) {}

    std::string quack(){return m_sound;}
    std::string swim(){return m_swim;}
    std::string toString(){return m_type.c_str();}
};

class RedheadDuck : public Fowl {
private: 
    std::string m_type;
    std::string m_sound;
    std::string m_swim;

public: 
    RedheadDuck() :m_type( "Redhead Duck" ), m_sound( "Quack" ), m_swim( "swims" ) {}
    std::string quack(){return m_sound;}
    std::string swim(){return m_swim;}
    std::string toString(){return m_type.c_str();}
};

class RubberDuck : public Fowl {

private: 
    std::string m_type;
    std::string m_sound;
    std::string m_swim;

public: 
    RubberDuck() :m_type( "Rubber Duck" ), m_sound( "Squeak" ), m_swim( "floats" ) {}
    std::string quack(){return m_sound;}
    std::string swim(){return m_swim;}
    std::string toString(){return m_type.c_str();}
};

// Flyweight Factory
class FowlFactory {

private: 
    std::map< int, Fowl* > map;

    FowlFactory( const FowlFactory& ); // Disable copy constructor
    void operator=( const FowlFactory& ); // Disable assignment operator

public: 
    FowlFactory() { }
    ~FowlFactory() { //clean map
        std::map< int, Fowl* >::iterator iterator = map.begin();
        while( iterator != map.end() ) {
            delete ( *iterator ).second;
            ( *iterator ).second = 0;
            iterator++;
        }
        map.clear();
    }
    Fowl* getFowl( int type ) 
    {
        Fowl* value = 0;
        std::map< int, Fowl* >::iterator iterator = map.find( type );

        if( iterator != map.end() ) {
            value = iterator->second;
        } else {
            switch( type ) 
            {
            case Fowl::mallard: { value = new MallardDuck();} break;
            case Fowl::redhead: {value = new RedheadDuck();} break;
            case Fowl::rubber: {value = new RubberDuck();} break;
            case Fowl::model: {value = new ModelDuck();} break;   
            default: {value = new ModelDuck();} break;
            }
            map[type] = value;
        }
        return value;
    }
    Bird* getBird( int type, int number, double weight ) {
        return new Bird( getFowl( type ) , number, weight );
    }
};

bool compare( Bird* lhs, Bird* rhs )
{
    return lhs->getWeight() < rhs->getWeight();
}

int main( int argc, char* argv[] ) {

    FowlFactory fowlFactory;

    //	Create a flock of mixed birds with random weights and tag them with a number

    std::vector<  Bird* > flock;
    flock.resize( MAX_BIRDS );

    srand( 5000 );
    for( int i = 0; i < MAX_BIRDS; i++ ) {
        int type = rand() % Fowl::last;
        double weight = (rand() % 100) * MIN_WIEGHT;
        if( weight < MIN_WIEGHT ) {
            weight = MIN_WIEGHT;
        }
        flock[i] = fowlFactory.getBird( type, i, weight );
    }

    //	Sort flock by ascending weight and display a journal

    std::sort( flock.begin(), flock.end(), compare );
    std::vector<  Bird* >::iterator itr = flock.begin();

    while( itr != flock.end() ) 
    {
        std::cout << ( *itr )->toString().c_str()
            << ", says \"" <<( *itr )->quack()
            << "\" and " <<( *itr )->swim() << std::endl;
        itr++;
    }
    while(1);
    return 0;
}
