#include <iostream>
using namespace std;

class EEGAlgorithm
{
public:
	EEGAlgorithm(){};
	virtual ~EEGAlgorithm(){};
	void EEGDataProcess()
	{
		EEGDataRead();
		EEGFDCalculation();
		EEGDeviceClose();
	}
protected:
	virtual void EEGDataRead(){		cout<<"Read Data from Device!"<<endl;	}

	virtual void EEGFDCalculation()	
	{
		cout<<"Higuchi Method is used!"<<endl;// This Can be empty line also
	}

	virtual void EEGDeviceClose(){		cout<<"The device is closed!"<<endl;	}
};


class HiguchiAlgorithm : public EEGAlgorithm{
public:
	HiguchiAlgorithm(){};
	virtual ~HiguchiAlgorithm(){};
protected:
	virtual void EEGFDCalculation()
	{
		//cout<<"Higuchi Method is used!"<<endl;// This line is perfect, and below line is not required, bust showing in Templet That implementation is also possible
		EEGAlgorithm::EEGFDCalculation();
	}

};

class BoxcountingAlgorithm : public EEGAlgorithm{
public:
	BoxcountingAlgorithm(){};
	virtual ~BoxcountingAlgorithm(){};
protected:
	virtual void EEGFDCalculation()	{		cout<<"Box-counting Method is used!"<<endl;	}
};
void main()
{
	HiguchiAlgorithm myMethod1 = HiguchiAlgorithm();
	BoxcountingAlgorithm myMethod2 = BoxcountingAlgorithm();
	myMethod1.EEGDataProcess();
	myMethod2.EEGDataProcess();
	while(1){
		;
	}
}
