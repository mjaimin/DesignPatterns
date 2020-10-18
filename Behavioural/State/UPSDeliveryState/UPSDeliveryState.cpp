#include <iostream>
#include <stdio.h>

class DeliveryContext;
class Acknowledged;
class Shipped;
class OutForDelivery;
class Delivered;

class PackageState
{
    public:
        virtual void updateState(DeliveryContext* ctx) = 0;
};

class Acknowledged: public PackageState
{
    //Acknowledged
    private:
        static	Acknowledged* instance;
        Acknowledged() {}
    public:
        static Acknowledged *getInstance();

        //Business logic and state transition
        void updateState(DeliveryContext* ctx);

};
class Shipped: public PackageState
{
    //Singleton
    private:
        static	Shipped* instance;
        Shipped() {}
    public:
        static Shipped* getInstance();

        //Business logic and state transition
        void updateState(DeliveryContext* ctx);

};

class InTransition: public PackageState
{
    //Singleton
    private:
        static	InTransition* instance;
        InTransition() {}
    public:
        static InTransition *getInstance();

        //Business logic and state transition
        void updateState(DeliveryContext* ctx);
};

class OutForDelivery: public PackageState
{
    //Singleton
    private:
        static	OutForDelivery* instance;
        OutForDelivery() {}
    public:
        static OutForDelivery *getInstance();

        //Business logic and state transition
        void updateState(DeliveryContext* ctx);

};

class Delivered: public PackageState
{
    //Singleton
    private:
        static	Delivered* instance;
        Delivered() {}
    public:
        static Delivered *getInstance();

        //Business logic
        void updateState(DeliveryContext* ctx);

};

Acknowledged* Acknowledged::instance = NULL;
Shipped* Shipped::instance = NULL;
InTransition* InTransition::instance = NULL;
OutForDelivery* OutForDelivery::instance = NULL;
Delivered* Delivered::instance = NULL;

Acknowledged *Acknowledged::getInstance() {
    if (!instance)
        instance = new Acknowledged;
    return instance;
}


Shipped* Shipped::getInstance() {
    if (!instance)
        instance = new Shipped;
    return instance;
}
InTransition *InTransition:: getInstance() {
    if (!instance)
        instance = new InTransition;
    return instance;
}


OutForDelivery *OutForDelivery::getInstance() {
    if (!instance)
        instance = new OutForDelivery;
    return instance;
}

Delivered *Delivered::getInstance() {
    if (!instance)
        instance = new Delivered;
    return instance;
}

//The Context
class DeliveryContext {

    private:
        PackageState* currentState;
        std::string packageId;

    public:
        DeliveryContext(std::string packageId)
        {
            this->packageId = packageId;
            this->currentState = Acknowledged::getInstance();
        }

        PackageState* getCurrentState() {
            return currentState;
        }

        void setCurrentState(PackageState* currentState) {
            this->currentState = currentState;
        }

        std::string getPackageId() {
            return packageId;
        }

        void setPackageId(std::string packageId) {
            this->packageId = packageId;
        }

        void update() {
            currentState->updateState(this);
        }
};

//Business logic and state transition
void Acknowledged::updateState(DeliveryContext* ctx)
{
    std::cout << "Package is acknowledged !!" << std::endl;
    ctx->setCurrentState(Shipped::getInstance());
}

//Business logic and state transition
void Shipped::updateState(DeliveryContext* ctx)
{
    std::cout << "Package is shipped !!" << std::endl;
    ctx->setCurrentState(InTransition::getInstance());
}

//Business logic and state transition
void InTransition:: updateState(DeliveryContext* ctx)
{
    std::cout << "Package is in transition !!" << std::endl;
    ctx->setCurrentState(OutForDelivery::getInstance());
}

//Business logic and state transition
void OutForDelivery::updateState(DeliveryContext* ctx)
{
    std::cout << "Package is out of delivery !!" << std::endl;
    ctx->setCurrentState(Delivered::getInstance());
}

//Business logic
void Delivered::updateState(DeliveryContext* ctx)
{
    std::cout << "Package is delivered!!" << std::endl;
}

int main()
{
    DeliveryContext ctx("Order Received");

    ctx.update();
    ctx.update();
    ctx.update();
    ctx.update();
    ctx.update();
};
