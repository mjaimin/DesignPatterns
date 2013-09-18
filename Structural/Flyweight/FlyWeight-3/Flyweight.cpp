



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
public:
	~Gun();
	Gun(const char* name);
	Gun(const Gun& rhs);
	void Load(int num);
	void ShowMe();
	bool operator == (const Gun& rhs);
	bool operator == (const char* rhs);
	Gun& operator = (const Gun& rhs);
private:
	const char* gName;  // intrinsic
	int bullet;         // extrinsic
};

// Class GunFactory (FlyweightFactory)
class GunFactory{
public:
	~GunFactory();
	GunFactory();
	Gun* GetGun(const char* name);
private:
	list<Gun*> gunPool;
};

// Class GunCheck
class GunCheck{
public:
	~GunCheck();
	GunCheck(int n, const char* name);
	int GetNum();
	void AddNum(int n);
	bool operator ==(const char* rhs);
private:
	int no;
	const char* gName;
};

// Class WeaponStore (Client)
class WeaponStore{
public:
	~WeaponStore();
	WeaponStore();
	Gun* AddGun(const char* name, int num);
	Gun* PickUp(const char* name, int bullet);
private:
	list<GunCheck> gunList; 
	GunFactory* myFactory;
};
// Class Gun
Gun::~Gun(){}

Gun::Gun(const char *name) : 
						gName(name),
						bullet(0){}

Gun::Gun(const Gun &rhs){
	gName = rhs.gName;
	bullet = rhs.bullet;
}

void Gun::Load(int num){
	bullet = num;
}

bool Gun::operator == (const Gun &rhs){
	if(strcmp ( gName,  rhs.gName ) == 0)
		return true;
	else 
		return false;
}

bool Gun::operator == (const char* rhs){
	if(strcmp ( gName,  rhs) == 0)
		return true;
	else 
		return false;
}

void Gun::ShowMe(){
	cout<<"Name   :  "<<gName<<endl;
	cout<<"Bullet :  "<<bullet<<endl;
}

Gun& Gun::operator =(const Gun &rhs){
	gName = rhs.gName;
	return *this;
}

// Class GunFactory
GunFactory::~GunFactory(){
	list<Gun*>::const_iterator it;
	for (it = gunPool.begin();  it != gunPool.end(); it++) {
			delete *it;
    }
	gunPool.clear();
}

GunFactory::GunFactory(){}

Gun* GunFactory::GetGun(const char *name){
	list<Gun*>::const_iterator it;
	for (it = gunPool.begin();  it != gunPool.end(); it++) {
		if(**it==name)
			return *it;
    }
	Gun* tGun = new Gun(name);
	gunPool.push_back(tGun);
	return tGun;
}

// Class GunCheck
GunCheck::~GunCheck(){}

GunCheck::GunCheck(int n, const char *name) :
					no(n),
					gName(name){}

int GunCheck::GetNum(){
	return no;
}

void GunCheck::AddNum(int n){
	no += n;
}

bool GunCheck::operator ==(const char *rhs){
	if(strcmp ( gName,  rhs) == 0)
		return true;
	else 
		return false;
}

// Class WeaponStore 
WeaponStore::WeaponStore(){
	myFactory = new GunFactory();
}

WeaponStore::~WeaponStore(){
	gunList.clear();
}

Gun* WeaponStore::AddGun(const char *name, int num){
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

Gun* WeaponStore::PickUp(const char *name, int bullet){
	Gun* tGun = myFactory->GetGun(name);
	Gun* newGun = new Gun(*tGun);
	newGun->Load(bullet);
	return newGun;
}


#include <iostream>
#include "Flyweight.h"
using namespace std;

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