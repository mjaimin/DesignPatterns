//The OrderService code implemented below breaks OCP, since the class has dependency on both OrderRepository and EmailRepository which makes it tightly coupled. Ideally as per SRP, each class should have related set of functionalities. In this case, if any modification required in OrderRepository and EmailRepository, it opens up OrderRespository which breaks OCP principle.
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
        EmailRepository* _emailRepository;

    public:
        OrderService()
        {
            _orderRepository = new OrderRepository();
            _emailRepository = new EmailRepository();
        }

        OrderService(OrderRepository* orderRepository,
                EmailRepository* emailRepository)
        {
            _orderRepository = orderRepository;
            _emailRepository = emailRepository;
        }

        bool SaveOrder(Order* order)
        {
            bool saveResult = false;
            if (order->IsValid())
            {
                saveResult = _orderRepository->Save(order);
            }
            if (saveResult)
            {
                _emailRepository->SendMail();
            }
            return true;
        }
};
int main()
{
}
