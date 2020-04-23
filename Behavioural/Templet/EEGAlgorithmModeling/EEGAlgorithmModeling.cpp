#include <iostream>
using namespace std;

class EEGAlgorithm
{
public:
   EEGAlgorithm() {}
   void DataProcess()
   {
      DataRead();
      Calculation();
      DeviceClose();
   }

protected:
   virtual void DataRead() { cout << "Read Data from Device!" << endl;   }
   virtual void Calculation() = 0;
   virtual void DeviceClose() { cout << "The device is closed!" << endl;    }
};


class HiguchiAlgorithm : public EEGAlgorithm {
public:
   HiguchiAlgorithm() {}
protected: virtual void Calculation() { std::cout<<"Higuchi Method is used!"<<std::endl; }
};

class BoxcountingAlgorithm : public EEGAlgorithm {
public:
   BoxcountingAlgorithm() {}
protected:
   virtual void Calculation() { cout << "Box-counting Method is used!" << endl;     }
};
int main()
{
   HiguchiAlgorithm     method1 = HiguchiAlgorithm();
   BoxcountingAlgorithm method2 = BoxcountingAlgorithm();

   method1.DataProcess();
   method2.DataProcess();
}
