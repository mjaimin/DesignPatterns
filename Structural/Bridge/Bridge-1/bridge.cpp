#include <iostream>
using namespace std;
class ProductionLine {

  public:
    ProductionLine() {};

    virtual void LoaderCmd( void ) = 0;
    virtual void DrillStationCmd( void ) = 0;
    virtual void StampStationCmd( void ) = 0;
    virtual void TesterCmd( void ) = 0;
    virtual void UnloaderCmd( void ) = 0;
};


class ProductionLineA : public ProductionLine {

  public:
    ProductionLineA() {};

    virtual void LoaderCmd( void );
    virtual void DrillStationCmd( void );
    virtual void StampStationCmd( void );
    virtual void TesterCmd( void );
    virtual void UnloaderCmd( void );
};


class ProductionLineB : public ProductionLine {

  public:
    ProductionLineB(){};

    virtual void LoaderCmd( void );
    virtual void DrillStationCmd( void );
    virtual void StampStationCmd( void );
    virtual void TesterCmd( void );
    virtual void UnloaderCmd( void );
};


class MakeAssembly {

  public:
    MakeAssembly( ProductionLine* i ):_imp(i) {};
    virtual void Load(void)=0;
    virtual void Fabricate(void)=0;
    virtual void Test(void)=0;
    virtual void Unload(void)=0;
  protected:
    ProductionLine* _imp;
};


class MakeType1Assembly : public MakeAssembly {

  public:
    MakeType1Assembly( ProductionLine* i ): MakeAssembly(i){};
    ~MakeType1Assembly( void ){};

    virtual void Load(void);
    virtual void Fabricate(void);
    virtual void Test(void);
    virtual void Unload(void);
};


class MakeType2Assembly : public MakeAssembly {

  public:
    MakeType2Assembly( ProductionLine* i ): MakeAssembly(i){};
    ~MakeType2Assembly( void ){};

    virtual void Load(void);
    virtual void Fabricate(void);
    virtual void Test(void);
    virtual void Unload(void);
};



void ProductionLineA::LoaderCmd( void ) {
  cout << "  LoaderCmdA()." <<endl;
}

void ProductionLineA::DrillStationCmd( void ) {
  cout << "  DrillStationCmdA()." <<endl;
}

void ProductionLineA::StampStationCmd( void ) {
  cout << "  StampStationCmdA()." <<endl;
}

void ProductionLineA::TesterCmd( void ) {
  cout << "  TesterCmdA()." <<endl;
}

void ProductionLineA::UnloaderCmd( void ) {
  cout << "  UnloaderCmdA()." <<endl;
}


void ProductionLineB::LoaderCmd( void ) {
  cout << "  LoaderCmdB()." <<endl;
}

void ProductionLineB::DrillStationCmd( void ) {
  cout << "  DrillStationCmdB()." <<endl;
}

void ProductionLineB::StampStationCmd( void ) {
  cout << "  StampStationCmdB()." <<endl;
}

void ProductionLineB::TesterCmd( void ) {
  cout << "  TesterCmdB()." <<endl;
}

void ProductionLineB::UnloaderCmd( void ) {
  cout << "  UnloaderCmdB()." <<endl;
}


void MakeType1Assembly::Load(void) {
  cout << "Type 1 Load Operation:" << endl;
  _imp->LoaderCmd();
}

void MakeType1Assembly::Fabricate(void) {
  cout << "Type 1 Fabricate Operation" << endl;
  _imp->DrillStationCmd();
  _imp->DrillStationCmd();
  _imp->DrillStationCmd();
  _imp->StampStationCmd();
}

void MakeType1Assembly::Test(void) {
  cout << "Type 1 Test Operation" << endl;
  _imp->TesterCmd();
}

void MakeType1Assembly::Unload(void) {
  cout << "Type 1 Unload Operation" << endl;
  _imp->UnloaderCmd();
}


void MakeType2Assembly::Load(void) {
  cout << "Type 2 Load Operation" << endl;
  _imp->LoaderCmd();
}

void MakeType2Assembly::Fabricate(void) {
  cout << "Type 2 Fabricate Operation" << endl;
  _imp->DrillStationCmd();
  _imp->StampStationCmd();
  _imp->StampStationCmd();
}

void MakeType2Assembly::Test(void) {
  cout << "Type 2 Test Operation" << endl;
  _imp->TesterCmd();
}

void MakeType2Assembly::Unload(void) {
  cout << "Type 2 Unload Operation" << endl;
  _imp->UnloaderCmd();
}


int main( void ) {

  // Note:
  //   The client is NOT compile-independent of the implementations
  //   because the implemenation objects are created here.
  //   To achieve compile-independence we would have to move these
  //   creation operations into static factory functions in the 
  //   base ProductionLine class.

  cout << "\n  Simulating an Automated Manufacturing Process";
  cout << "\n ===============================================\n";

  ProductionLine* productionLineAX = new ProductionLineA();
  MakeAssembly* runProductX = new MakeType1Assembly(productionLineAX);

  ProductionLine* productionLineBY = new ProductionLineB();
  MakeAssembly* runProductY = new MakeType2Assembly(productionLineBY);

  ProductionLine* productionLineAZ = new ProductionLineA();
  MakeAssembly* runProductZ = new MakeType2Assembly(productionLineAZ);

  cout << "\nRunning Product X, Type 1 using production line A...\n";
  runProductX->Load();
  runProductX->Fabricate();
  runProductX->Test();
  runProductX->Unload();

  cout << "\nRunning Product Y, Type 2 using production line B...\n";
  runProductY->Load();
  runProductY->Fabricate();
  runProductY->Test();
  runProductY->Unload();

  cout << "\nRunning Product Z, Type 2 using production line A...\n";
  runProductZ->Load();
  runProductZ->Fabricate();
  runProductZ->Test();
  runProductZ->Unload();

  return 0;
}
