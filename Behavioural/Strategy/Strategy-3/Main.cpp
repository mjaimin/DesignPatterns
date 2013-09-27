#include <iostream>
using namespace std;

class Kongfu;

// Class Context
class KongfuMan{
public:
	KongfuMan(const char* name);
	~KongfuMan();
	void Attack();
	void ChangeKongfu(Kongfu* newKongfu);
	const char* GetName();
private:
	Kongfu* myKongfu;
	const char* myName;
};

// Class Strategy
class Kongfu{
protected:
	KongfuMan* myKongfuMan;
public:
	Kongfu(KongfuMan* tMan);
	virtual ~Kongfu();
	virtual void Attack() = 0;
};

class BasicKongfu : public Kongfu{
    public:
	BasicKongfu( KongfuMan* tMan ) : Kongfu(tMan){ }
	virtual ~BasicKongfu(){ }
	virtual void Attack(){
	    cout<<myKongfuMan->GetName()<<": Show Basic Kongfu!"<<endl;
	}
};


class WingChun : public Kongfu{
    public:
	WingChun( KongfuMan* tMan ) : Kongfu(tMan){ }
	virtual ~WingChun(){ }
	virtual void Attack(){
	    cout<<myKongfuMan->GetName()<<": Show Wing Chun!"<<endl;
	}
};

class Taiji : public Kongfu{
    public:
	Taiji( KongfuMan* tMan ) : Kongfu(tMan){ }
	virtual ~Taiji(){ }
	virtual void Attack(){
	    cout<<myKongfuMan->GetName()<<": Show Tai Ji!"<<endl;
	}
};

class Shaolin : public Kongfu{
public:
    Shaolin(KongfuMan* tMan) : Kongfu(tMan){ }
    virtual ~Shaolin(){ }
    virtual void Attack()
    {
	cout<<myKongfuMan->GetName()<<": Show Shao lin kongfu!"<<endl;
    }
};

// Class KongfuMan


KongfuMan::KongfuMan( const char* name ) :
					myName(name){
	myKongfu = new BasicKongfu(this);
}

KongfuMan::~KongfuMan(){
	delete myKongfu;
}

void KongfuMan::Attack(){
	myKongfu->Attack();
}

void KongfuMan::ChangeKongfu( Kongfu* newKongfu ){
	delete myKongfu;
	myKongfu = newKongfu;
}

const char* KongfuMan::GetName(){
	return myName;
}


// Class Kongfu
Kongfu::Kongfu(KongfuMan* tMan) : myKongfuMan(tMan){

}

Kongfu::~Kongfu(){
	//delete myKongfuMan;
}


int main(){
	KongfuMan* master1 = new KongfuMan("Zhang Sanfeng");
	KongfuMan* master2 = new KongfuMan("Ye Weng");
	KongfuMan* master3 = new KongfuMan("Fang Zhang");
	master1->Attack();
	master2->Attack();
	master3->Attack();
	master1->ChangeKongfu(new Taiji(master1));
	master2->ChangeKongfu(new WingChun(master2));
	master3->ChangeKongfu(new Shaolin(master3));
	master1->Attack();
	master2->Attack();
	master3->Attack();
}

