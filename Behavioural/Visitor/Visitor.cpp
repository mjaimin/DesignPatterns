#include <string>
#include <iostream>
#include <list>
#include <algorithm>

class Product;

class BaseSummingVisitor
{
protected:
	int m_nNumProducts;
	double m_ySum;

public:
	BaseSummingVisitor(): m_nNumProducts(0), m_ySum(0.0){}

	void Reset()
	{
		m_nNumProducts = 0;
		m_ySum = 0.0;
	}

	virtual void VisitProduct( Product* p ) { }

	virtual void Results() { }
};



class Product
{
	std::string m_strName;
	int m_nOnHand;
	int m_nSoldToDate;
	double m_yCost;
	double m_yPrice;

public:
	Product(std::string name, int onHand, int sold, double cost, double price):
		m_strName(name), m_nOnHand(onHand), m_nSoldToDate(sold), m_yCost(cost), m_yPrice(price)
	{
	}

	std::string getName() {  return m_strName;  }
	int getOnHand() {  return m_nOnHand;  }
	int getSold() {  return m_nSoldToDate;  }
	double getCost() {  return m_yCost;  }
	double getPrice() {  return m_yPrice;  }

	void Accept(BaseSummingVisitor* v)
	{
		v->VisitProduct(this);
	}
};
class	CostVisitor : public BaseSummingVisitor
{
public:
	void	VisitProduct(Product* p)
	{
		m_nNumProducts += p->getOnHand();
		m_ySum += (p->getOnHand() * p->getCost());
	}

	void	Results()
	{
		std::cout << "Total cost of " << m_nNumProducts << " onhand products is:" << m_ySum << std::endl;
	}
};

class	SalesVisitor : public BaseSummingVisitor
{
public:

	  void	VisitProduct(Product* p)
	{
		m_nNumProducts += p->getSold();
		m_ySum += (p->getSold() * p->getPrice());
	}

	void	Results()
	{
		std::cout << "Total cost of " << m_nNumProducts << " sold products is:" << m_ySum << std::endl;
	}
};


class	PotentialSalesVisitor : public BaseSummingVisitor
{
public:
	void	VisitProduct(Product* p)
	{
		m_nNumProducts += p->getOnHand();
		m_ySum += (p->getOnHand() * p->getPrice());
	}

	void	Results()
	{
		std::cout << "Total price of " << m_nNumProducts << " onhand products is:" << m_ySum << std::endl;
	}
};

 int main()
{
	std::list<Product*> l;

	l.push_front(new Product("chair", 5, 2, 10.00, 24.99));
	l.push_front(new Product("desk", 10, 5, 45.00, 150.00));
	l.push_front(new Product("filing cabinet", 20, 7, 15.00, 45.00));

	CostVisitor*	cv = new CostVisitor();
	SalesVisitor*	sv = new SalesVisitor();
	PotentialSalesVisitor*	psv = new PotentialSalesVisitor();

	for( std::list<Product*>::iterator itr = l.begin(); itr != l.end(); itr++ )
	{
		(*itr)->Accept(cv);
		(*itr)->Accept(sv);
		(*itr)->Accept(psv);
	}

	cv->Results();
	psv->Results();
	sv->Results();
}