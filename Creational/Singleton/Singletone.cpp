class Singleton {
public:
    static Singleton* getInstance();
protected:
    Singleton();
private:
    static Singleton* instance;
};

Singleton* Singleton::instance = 0;

Singleton::Singleton() {}

Singleton* Singleton::getInstance () {
    if ( NULL == instance) //synchronized lock only activeted when instance is NULL, first time
    {
    //aquire lock()//this lock ensures only one thread enters beyond this point
    if ( NULL == instance) 
        instance = new Singleton;
    //release lock()
    }
    return Singleton::instance;
}

int main () {
    Singleton* var1 = Singleton::getInstance();
    Singleton* var2 = Singleton::getInstance();
    std::cout << var1 << std::endl;
    std::cout << var2 << std::endl;
    return 0;
}