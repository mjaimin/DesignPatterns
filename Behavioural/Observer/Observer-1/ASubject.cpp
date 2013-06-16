#include "ASubject.h"
#include <algorithm>

using namespace std;

void ASubject::Attach(Shop *shop)
{
	list.push_back(shop);
}
void ASubject::Detach(Shop *shop)
{	
	list.erase(std::remove(list.begin(), list.end(), shop), list.end());	
}

void ASubject::Notify(float price)
{
	for(vector<Shop*>::const_iterator iter = list.begin(); iter != list.end(); ++iter)
	{
		if(*iter != 0)
		{
			(*iter)->Update(price);
		}
	}
}
