#include <iostream>
#include "companystock.h"
#include "investor.h"
#include "stock.h"

using namespace std;

int main()
{
  companyStock* c1 = new companyStock("IBM", 123.0);

  investor* i1 = new investor("Sorros");
  c1->registerObserver(i1);

  c1->setStockPrice(125.0);

  investor* i2 = new investor("Berkshire");
  c1->registerObserver(i2);

  c1->setStockPrice(145.0);

  c1->removeObserver(i1);

  c1->setStockPrice(165.0);

  delete i1;
  delete i2;
  delete c1;

  return 0;
}
