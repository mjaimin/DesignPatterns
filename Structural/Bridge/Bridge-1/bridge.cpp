#include <iostream>
using namespace std;
class ProductionLine {
    public:
        virtual void LoaderCmd( void ) = 0;
        virtual void DrillStationCmd( void ) = 0;
        virtual void StampStationCmd( void ) = 0;
        virtual void TesterCmd( void ) = 0;
        virtual void UnloaderCmd( void ) = 0;
};

class ProductionLineA : public ProductionLine {
    public:
        virtual void LoaderCmd( void ) { cout << "  LoaderCmdA()." <<endl; }
        virtual void DrillStationCmd( void ) { cout << "  DrillStationCmdA()." <<endl; }
        virtual void StampStationCmd( void ) { cout << "  StampStationCmdA()." <<endl; }
        virtual void TesterCmd( void ) { cout << "  TesterCmdA()." <<endl; }
        virtual void UnloaderCmd( void ) { cout << "  UnloaderCmdA()." <<endl; }
};

class ProductionLineB : public ProductionLine {
    public:
        virtual void LoaderCmd( void ) { cout << "  LoaderCmdB()." <<endl; }
        virtual void DrillStationCmd( void ) { cout << "  DrillStationCmdB()." <<endl; }
        virtual void StampStationCmd( void ) { cout << "  StampStationCmdB()." <<endl; }
        virtual void TesterCmd( void ) { cout << "  TesterCmdB()." <<endl; }
        virtual void UnloaderCmd( void ) { cout << "  UnloaderCmdB()." <<endl; }
};

class MakeAssembly {
    protected:
        ProductionLine* productionLine;
    public:
        MakeAssembly( ProductionLine* i ):productionLine(i) {};
        virtual void Load(void)=0;
        virtual void Fabricate(void)=0;
        virtual void Test(void)=0;
        virtual void Unload(void)=0;
};

class MakeType1Assembly : public MakeAssembly {
    public:
        MakeType1Assembly( ProductionLine* pl ): MakeAssembly(pl){};
        virtual void Load(void){
            cout << "Type 1 Load Operation:" << endl;
            productionLine->LoaderCmd();
        }
        virtual void Fabricate(void){
            cout << "Type 1 Fabricate Operation" << endl;
            productionLine->DrillStationCmd();
            productionLine->DrillStationCmd();
            productionLine->DrillStationCmd();
            productionLine->StampStationCmd();
        }
        virtual void Test(void){
            cout << "Type 1 Test Operation" << endl;
            productionLine->TesterCmd();
        }
        virtual void Unload(void){
            cout << "Type 1 Unload Operation" << endl;
            productionLine->UnloaderCmd();
        }
};


class MakeType2Assembly : public MakeAssembly {
    public:
        MakeType2Assembly( ProductionLine* pl ): MakeAssembly(pl){};
        virtual void Load(void){
            cout << "Type 2 Load Operation" << endl;
            productionLine->LoaderCmd();
        }
        virtual void Fabricate(void){
            cout << "Type 2 Fabricate Operation" << endl;
            productionLine->DrillStationCmd();
            productionLine->StampStationCmd();
            productionLine->StampStationCmd();
        }
        virtual void Test(void){
            cout << "Type 2 Test Operation" << endl;
            productionLine->TesterCmd();
        }
        virtual void Unload(void){
            cout << "Type 2 Unload Operation" << endl;
            productionLine->UnloaderCmd();
        }
};
int main( void ) {

    cout << "\n  Simulating an Automated Manufacturing Process";
    cout << "\n ===============================================\n";

    ProductionLine* productionLineA = new ProductionLineA();
    MakeAssembly* runProductX = new MakeType1Assembly(productionLineA);

    ProductionLine* productionLineB = new ProductionLineB();
    MakeAssembly* runProductY = new MakeType2Assembly(productionLineB);

    MakeAssembly* runProductZ = new MakeType2Assembly(productionLineA);

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
