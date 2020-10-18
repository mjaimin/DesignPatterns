#include <iostream>
#include <string>

class IIcecream {
    public:
        virtual std::string makeIcecream( void ) = 0;
};

class SimpleIcecream: public IIcecream {
    public:
        SimpleIcecream(){}
        std::string makeIcecream( void )
        {
            return "Base Icecream";
        }
};

class IcecreamDecorator: public IIcecream
{
    protected:
        IIcecream* m_specialIcecream;

    public:
        IcecreamDecorator(){}
        IcecreamDecorator( IIcecream* specialIcecream )
        {
            this->m_specialIcecream = specialIcecream;
        }

        std::string makeIcecream( void ) {
            return m_specialIcecream->makeIcecream();
        }
};

class NuttyDecorator: public IcecreamDecorator
{
    NuttyDecorator(){}
    public:
    NuttyDecorator( IIcecream* specialIcecream )
    {
        m_specialIcecream = specialIcecream ;
    }

    std::string makeIcecream( void )
    {
        return m_specialIcecream->makeIcecream() + addNuts();
    }

    private:
    std::string addNuts( void )
    {
        return " + cruncy nuts";
    }
};

class HoneyDecorator: public IcecreamDecorator
{
    HoneyDecorator(){}
    public:
    HoneyDecorator( IIcecream* specialIcecream )
    {
        m_specialIcecream = specialIcecream ;
    }

    std::string makeIcecream( void )
    {
        return m_specialIcecream->makeIcecream() + addHoney();
    }

    private:
    std::string addHoney( void )
    {
        return " + sweet honey";
    }
};

int main()
{
    IIcecream* icecream = new HoneyDecorator( new NuttyDecorator( new SimpleIcecream() ) );
    std::cout << icecream->makeIcecream() << std::endl;
}

