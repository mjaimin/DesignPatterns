#include <iostream>
using namespace std;

// Parts of the car
class Door{
    public:
        Door(){}
        ~Door(){}
        virtual void Door::Open(){ cout<<"The Door is open!"<<endl; }
        virtual void Door::Close(){	cout<<"The Door is locked!"<<endl; }
};

class Engine{
    public:
        Engine(){}
        virtual ~Engine(){}
        virtual void Start(){ cout<<"The Engine is started!"<<endl;	}
        virtual void Stop(){ cout<<"The Engine is stopped!"<<endl; }
};

class Brake{
    public:
        Brake(){}
        virtual ~Brake(){}
        virtual void Skid(){ cout<<"The car is skidded!"<<endl;	}
};

class GPS{
    private:
        double longitude;
        double latitude;
    public:

        GPS() : longitude(0),latitude(0){}
        virtual GPS::~GPS(){}
        virtual void Open(){ cout<<"GPS is open!"<<endl; }
        virtual void TurnOff(){	cout<<"GPS is turned off!"<<endl; }
        virtual void GetPosition(){	longitude = 100.55;	latitude = 1.14; }
        virtual void DisplayPosition()
        {
            cout<<"Position:"<<endl;
            cout<<"  Longitude:"<<longitude<<endl;
            cout<<"  Latitude :"<<latitude<<endl;
        }
};

// Facade class
class Car{
    private:
        Door* myDoor;
        Engine* myEngine;
        GPS* myGPS;
        Brake* myBrake;

    public:
        Car()
        {
            myDoor = new Door();
            myEngine = new Engine();
            myGPS = new GPS();
            myBrake = new Brake();
        }
        virtual void OpenDoor()	{ myDoor->Open();}
        virtual void LockDoor()	{ myDoor->Close();}
        virtual void Start()
        {
            myEngine->Start();
            myGPS->Open();
        }
        virtual void Skid(){myBrake->Skid();}
        virtual void Stop()
        {
            myEngine->Stop();
            myGPS->TurnOff();
        }
        virtual void DisplayPosition()
        {
            myGPS->GetPosition();
            myGPS->DisplayPosition();
        }
        virtual ~Car()
        {
            delete myDoor;
            delete myEngine;
            delete myGPS;
            delete myBrake;
        }
};

// Class Car
void main(){
    Car myCar = Car();
    myCar.OpenDoor();
    myCar.Start();
    myCar.DisplayPosition();
    myCar.Skid();
    myCar.Stop();
    myCar.LockDoor();
    while(1){;}
}
