#include <iostream>

class FlyBehaviour
{
    public:
    virtual void fly()=0;
};
class FlyWithWings:public FlyBehaviour
{
   public:
   void fly()
   {
       std::cout<<"I'm flying"<<std::endl;
   }
};
class FlyNoWay:public FlyBehaviour
{
   public:
   void fly()
   {
       std::cout<<"I can't fly..."<<std::endl;
   }
};

class FlyRocketPowered:public FlyBehaviour
{
    void fly()
    {
        std::cout<<"Fly Rocket Powered ==> Zoooom"<<std::endl;
    }
};

class QuackBehaviour
{
    public:
    virtual void quack()=0;
};
class Quack:public QuackBehaviour
{
    public:
    void quack()
    {
        std::cout<<"Quack"<<std::endl;
    }
};

class MuteQuack:public QuackBehaviour
{
    public:
    void quack()
    {
        std::cout<<"Silence"<<std::endl;
    }
};

class Squeak:public QuackBehaviour
{
    public:
    void quack()
    {
        std::cout<<"Squeak"<<std::endl;
    }
};


class Duck
{

    protected:
    FlyBehaviour *flyBehav;
    QuackBehaviour *quackBehav;

    public:
    Duck(){}

    void swim()
    {
        std::cout<<"All ducks float/swim"<<std::endl;
    }
    virtual void display()=0;

    void performFly()
    {
        flyBehav->fly();
    }
    void performQuack()
    {
        quackBehav->quack();
    }
    void setFlyingBehav(FlyBehaviour *pflyBehav)
    {
        flyBehav = pflyBehav;
    }
    void setQuackingBehav(QuackBehaviour *pquackBehav)
    {
        quackBehav = pquackBehav;
    }
};

class MallardDuck:public Duck
{
    public:
    MallardDuck()
    {
       quackBehav = new Quack();
       flyBehav=new FlyWithWings();

    }
    void display()
    {
        std::cout<<"I am real Mallard Duck"<<std::endl;
    }

	~MallardDuck()
   {
	   std::cout << "Mallard Duck Destroyed" << std::endl;
   }
};

class ModelDuck:public Duck
{
   public:
   ModelDuck()
   {
       quackBehav = new Quack();
       flyBehav=new FlyNoWay();
   }
   void display()
    {
        std::cout<<"I am Model Duck"<<std::endl;
    }
   ~ModelDuck()
   {
	   std::cout << "Model Duck Destroyed" << std::endl;
   }
};



class DuckHunter
{
    private:
    Duck * duckType;
    public:
    void SetDuckType(Duck *pDuck)
    {
        duckType = pDuck;
    }
    void StartHunting()
    {
      for(int i=0;i<3;i++)
	  {
       duckType->performQuack();
	   duckType->performFly();
	  }
    }

};

int main()
{
 std::cout<<"*********Hello Duck*********"<<std::endl;
 Duck *mallard = new MallardDuck();
 mallard->display();
 mallard->performQuack();
 mallard->performFly();

 Duck *model = new ModelDuck();
 model->performFly();
 model->setFlyingBehav(new FlyRocketPowered());
 model->performFly();

 MallardDuck mallardDuck;
 ModelDuck  modelDuck;

 DuckHunter *huntingToy = new DuckHunter();

 //huntingToy->SetDuckType( new MallardDuck() );
 huntingToy->SetDuckType( &mallardDuck );
 huntingToy->StartHunting();

 //huntingToy->SetDuckType( new ModelDuck() );
 huntingToy->SetDuckType( &modelDuck );
 huntingToy->StartHunting();

 return 0;
}