// The number of birds migrating to Objective has overwhelmed the Quackologists
// who are complaining that it is hard to keep up because the journaling program
// you wrote is getting sluggish. Quackologists capture birds, categorize them, 
// weight them, tag them, and finally, record them with your program. After hours 
// of drinking coffee at Starbuzz reviewing your design, you realize that some 
// traits are common to each type of bird; its type, the sound it makes and how
// it swims. If only you could isolate the common (intrinsic) traits from the 
// unique (extrinsic) traits, its weight and tag number. Your redesign implements
// the ‘Flyweight’ pattern by creating a single instance for each type of bird and
// each bird contains a reference back to its type.
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

class Fowl {

public: 
    const enum type{mallard, redhead, rubber, model, turkey, last};

protected: 
    Fowl() {
    }
public: 
    virtual ~Fowl() = 0 {
    }
    virtual void quack() const = 0;
    virtual void swim() const = 0;
    virtual std::string toString() const = 0;
};
// Unshared ConcreteFlyweight

class Bird : public Fowl {

private: 
    const Fowl* m_fowl;
    int m_number;
    double m_weight;

    Bird( const Bird& ); // Disable copy constructor
    void operator=( const Bird& ); // Disable assignment operator

public: 
    Bird( const Fowl* fowl, int number = 0, double weight = 0.0 ) :
      m_fowl( fowl ), m_number( number ), m_weight( weight ) { assert( fowl );
      }
      void quack() const { assert( m_fowl );
      m_fowl->quack();
      }
      void swim() const { assert( m_fowl );
      m_fowl->swim();
      }
      double getWeight() const {
          return m_weight;
      }
      double getNumber() const {
          return m_number;
      }
      std::string toString() const { assert( m_fowl );
      std::stringstream value; 
      value << "Bird #"<< m_number + 1 << ", ";
      value << "weighs " << m_weight << " pounds, ";
      value << "is a " << m_fowl->toString();
      return value.str();
      }
};

// Abstract Flyweight

class Turkey {

public: 
    virtual ~Turkey() = 0 {
    }
    virtual void gobble() const = 0;
    virtual void walk() const = 0;
    virtual std::string toString() const = 0;
};



// ConcreteFlyweights

class MallardDuck : public Fowl {

private: std::string m_type;
         std::string m_sound;
         std::string m_swim;

public:
    MallardDuck() : m_type( "Mallard Duck" ), m_sound( "Quack" ), m_swim( "swims" ) {	}

    void quack() const {
        std::cout << m_sound.c_str();
    }
    void swim() const {
        std::cout << m_swim.c_str();
    }
    std::string toString() const {
        return m_type.c_str();
    }
};

class ModelDuck : public Fowl {

private: std::string m_type;
         std::string m_sound;
         std::string m_swim;

public: ModelDuck() : 
    m_type( "Model duck" ), m_sound( "<< Silence >>" ), m_swim( "sinks" ) {
    }

    void quack() const {
        std::cout << m_sound.c_str();
    }
    void swim() const {
        std::cout << m_swim.c_str();
    }
    std::string toString() const {
        return m_type.c_str();
    }
};

class RedheadDuck : public Fowl {
private: std::string m_type;
         std::string m_sound;
         std::string m_swim;

public: 
    RedheadDuck() : 

      m_type( "Redhead Duck" ), m_sound( "Quack" ), m_swim( "swims" ) {
      }
      void quack() const {
          std::cout << m_sound.c_str();
      }
      void swim() const {
          std::cout << m_swim.c_str();
      }
      std::string toString() const {
          return m_type.c_str();
      }
};

class RubberDuck : public Fowl {

private: 
    std::string m_type;
    std::string m_sound;
    std::string m_swim;

public: 
    RubberDuck() :
      m_type( "Rubber Duck" ), m_sound( "Squeak" ), m_swim( "floats" ) {
      }
      void quack() const {
          std::cout << m_sound.c_str();
      }
      void swim() const {
          std::cout << m_swim.c_str();
      }
      std::string toString() const {
          return m_type.c_str();
      }
};


class TurkeyAdapter : public Fowl {

private: 
    std::auto_ptr< const Turkey > m_turkey;

    TurkeyAdapter( const TurkeyAdapter& ); // Disable copy constructor
    void operator=( const TurkeyAdapter& ); // Disable assignment operator

public: 
    explicit TurkeyAdapter( const Turkey* turkey ) :
    m_turkey( turkey ) { assert( turkey );
    }
    void quack() const { assert( m_turkey.get() );
    m_turkey->gobble();
    }
    void swim() const { assert( m_turkey.get() );
    m_turkey->walk();
    }
    std::string toString() const { assert( m_turkey.get() );
    return m_turkey->toString();
    }
};
// ConcreteFlyweight (once its wrapped in an adapter)

class WildTurkey : public Turkey {

private: 
    std::string m_type;
    std::string m_sound;
    std::string _walk;

public: 
    WildTurkey() : 
      m_type( "Wild Turkey" ), m_sound( "Gobble gobble" ), _walk( "struts" ) {}
      void gobble() const {
          std::cout << m_sound.c_str();
      }
      void walk() const {
          std::cout << _walk.c_str();
      }
      std::string toString() const {
          return m_type.c_str();
      }
};


// Flyweight Factory

// As also mentioned by GoF [pp 205] we could omit the operation getBird() and
// let clients instantiate unshared objects directly; however, if we decided to
// make these objects sharable later, we'll have to change client code that
// creates them.


class FowlFactory {

private: 
    std::map< int, Fowl* > map;

    FowlFactory( const FowlFactory& ); // Disable copy constructor
    void operator=( const FowlFactory& ); // Disable assignment operator

public: 
    FowlFactory() {
    }
    ~FowlFactory() {
        std::map< int, Fowl* >::iterator iterator = map.begin();
        while( iterator != map.end() ) {
            delete ( *iterator ).second;
            ( *iterator ).second = 0;
            iterator++;
        }
        map.clear();
    }
    const Fowl* getFowl( int type ) {
        Fowl* value = 0;
        std::map< int, Fowl* >::iterator iterator = map.find( type );

        if( iterator != map.end() ) {
            value = iterator->second;
        } else {
            switch( type ) {
                case Fowl::mallard: {
                    value = new MallardDuck();
                                    } break;
                case Fowl::redhead: {
                    value = new RedheadDuck();
                                    } break;
                case Fowl::rubber: {
                    value = new RubberDuck();
                                   } break;
                case Fowl::model: {
                    value = new ModelDuck();
                                  } break;
                case Fowl::turkey: {
                    value = new TurkeyAdapter( new WildTurkey() );
                                   } break;
                default: {
                    value = new ModelDuck();
                         } break;
            }
            map[type] = value;
        }

        return value;
    }
    const Bird* getBird( int type, int number, double weight ) {
        return new Bird( getFowl( type ) , number, weight );
    }
};





bool compare( const Bird* lhs, const Bird* rhs )
{
    return lhs->getWeight() < rhs->getWeight();
}

int main( int argc, char* argv[] ) {

    FowlFactory fowlFactory;

    //	Create a flock of mixed birds with random weights and tag them with a number

    std::vector<  const Bird* > flock;
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
    std::vector< const Bird* >::const_iterator iterator = flock.begin();

    while( iterator != flock.end() ) {
        std::cout << ( *iterator )->toString().c_str();
        std::cout << ", says \"";
        ( *iterator )->quack();
        std::cout << "\" and ";
        ( *iterator )->swim();
        std::cout << std::endl;
        iterator++;
    }

    return 0;
}
