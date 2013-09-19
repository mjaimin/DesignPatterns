/*	Flyweight Pattern
*
*	This progarm is used to show how flyweight pattern works.
*	In this program, we assume that there is a weapon store.
*   We store different kind of guns there. If one kind of gun 
*   is picked up, it is extrinsic.
*
*   @ Wang Qiang  2010 NTU
*
*/
#include <iostream>
#include <list>
using namespace std;

// Class Gun (Flyweight)
class Gun{
private:
    const char* gName;  // intrinsic
    int bullet;         // extrinsic
public:
    ~Gun(){}

    Gun(const char *name) : 
	
    gName(name),
        bullet(0){}

    Gun(const Gun &rhs){
        gName = rhs.gName;
        bullet = rhs.bullet;
    }

    void Load(int num){
        bullet = num;
    }

    bool operator == (const Gun &rhs){
        if(strcmp ( gName,  rhs.gName ) == 0)
            return true;
        else 
            return false;
    }

    bool operator == (const char* rhs){
        if(strcmp ( gName,  rhs) == 0)
            return true;
        else 
            return false;
    }

    void ShowMe(){
        cout<<"Name   :  "<<gName<<endl;
        cout<<"Bullet :  "<<bullet<<endl;
    }

    Gun& operator =(const Gun &rhs){
        gName = rhs.gName;
        return *this;
    }
};

// Class GunFactory (FlyweightFactory)
class GunFactory{
private:
    list<Gun*> gunPool;

public:
    ~GunFactory(){
        list<Gun*>::const_iterator it;
        for (it = gunPool.begin();  it != gunPool.end(); it++) {
            delete *it;
        }
        gunPool.clear();
    }

    GunFactory(){}

    Gun* GetGun(const char *name){
        list<Gun*>::const_iterator it;
        for (it = gunPool.begin();  it != gunPool.end(); it++) {
            if(**it==name)
                return *it;
        }
        Gun* tGun = new Gun(name);
        gunPool.push_back(tGun);
        return tGun;
    }
};

// Class GunCheck
class GunCheck{
private:
    int no;
    const char* gName;
	
public:
    ~GunCheck(){}

    GunCheck(int n, const char *name) :
    no(n),
        gName(name){}

    int GetNum(){
        return no;
    }

    void AddNum(int n){
        no += n;
    }

    bool operator ==(const char *rhs){
        if(strcmp ( gName,  rhs) == 0)
            return true;
        else 
            return false;
    }
};

// Class WeaponStore (Client)
class WeaponStore{
private:
    list<GunCheck> gunList; 
    GunFactory* myFactory;
	
public:
    WeaponStore(){
        myFactory = new GunFactory();
    }

    ~WeaponStore(){
        gunList.clear();
    }

    Gun* AddGun(const char *name, int num){
        bool exist = false;
        list<GunCheck>::iterator it;
        for (it = gunList.begin();  it != gunList.end(); it++) {
            if(*it==name){
                (*it).AddNum(num);
                exist = true;
            }
        }
        if(!exist){
            GunCheck mylist = GunCheck(num,name);
            gunList.push_back(mylist);
        }
        return(myFactory->GetGun(name));
    }

    Gun* PickUp(const char *name, int bullet){
        Gun* tGun = myFactory->GetGun(name);
        Gun* newGun = new Gun(*tGun);
        newGun->Load(bullet);
        return newGun;
    }

};


void main(){
    WeaponStore myStore = WeaponStore();
    Gun* myGun1 = myStore.AddGun("M4A1",10);
    Gun* myGun2 = myStore.AddGun("AK47",15);
    Gun* myGun3 = myStore.PickUp("M4A1",70);
    Gun* myGun4 = myStore.PickUp("AK47",90);
    myGun1->ShowMe();  // Guns in store
    myGun2->ShowMe();  // Guns in store
    myGun3->ShowMe();  // Particular gun I picked up
    myGun4->ShowMe();  // Particular gun I picked up
    while(1){
        ;
    }
}