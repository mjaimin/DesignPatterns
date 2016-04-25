//The solution to above problem is to have separate OrderRepository and EmailRepository. Each repository should contain functionalities related to it. Please note in below example SaveOrder is defined as virtual.



class Order
{
    public:
	bool IsValid() { return true; }
};

class OrderRepository
{
    public:
	bool Save(Order* newOrder)
	{
	    return true;
	}
};

class EmailRepository
{
    public:
	void SendMail()
	{
	    // send mail code goes here
	}
};


class OrderService
{
    private:
	OrderRepository* _orderRepository;

    public:
	OrderService()
	{
	    _orderRepository = new OrderRepository();
	}

	OrderService(OrderRepository* orderRepository)
	{
	    _orderRepository = orderRepository;
	}

	virtual bool SaveOrder(Order* order)
	{
	    bool saveResult = false;
	    if (order->IsValid())
	    {
		saveResult = _orderRepository->Save(order);
	    }
	    return true;
	}
};

class EmailOrderService : public  OrderService
{
    private:
	EmailRepository* _emailRepository;

    public:
	EmailOrderService(OrderRepository* orderRepo, EmailRepository* emailRepository)
	{
	    _emailRepository = emailRepository;
	}

	bool SaveOrder(Order* order)
	{
	    if (OrderService::SaveOrder(order))
	    {
		_emailRepository->SendMail();
	    }
	    return OrderService::SaveOrder(order);
	}
};

int main()
{
}
