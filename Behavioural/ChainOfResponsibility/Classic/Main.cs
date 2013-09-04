// helper classes
 
public interface IRequest { }
 
public class RequestInfo 
{
    public string CreateBy { get; set; }
    public string UpdateBy { get; set; }
    public DateTime CreateDate { get; set; }
    public DateTime UpdateDate { get; set; }
}
 
public class BaseRequest
    : RequestInfo,IRequest
{
    public State State { get; set; }
}
 
public class LoanRequest
    : BaseRequest 
{
    public decimal Amount { get; set; }
}
 
public enum State 
{
    None,     
    New,
    WaitingApproval,
    ApprovedApproval,  
    RejectedApproval,       
    WaitingCancelledApproval,  
    ApprovedCancelledApproval,    
    RejectedCancelledApproval,
    Completed
}
 
// handler
public abstract class BaseRequestHandler<TRequest>
    where TRequest : BaseRequest
{
    public BaseRequestHandler<TRequest> Successor
    {
        protected get;
        set;
    }
 
    public void ExecuteRequest(TRequest request)
    {
        Execute(request);
 
        if (Successor != null)
            Successor.ExecuteRequest(request);
    }
 
    protected abstract void Execute(TRequest request);
}
 
// concrete handler
public class FirstApproverRequestHandler
    : BaseRequestHandler<LoanRequest>
{
    protected override void Execute(LoanRequest request)
    {
        Console.WriteLine("Execute : FirstApproverRequestHandler");
    }
}
 
// concrete handler
public class SecondApproverRequestHandler
    : BaseRequestHandler<LoanRequest>
{
    protected override void Execute(LoanRequest request)
    {
        Console.WriteLine("Execute : SecondApproverRequestHandler");
    }
}
 
// concrete handler
public class ManagerApproverRequestHandler
    : BaseRequestHandler<LoanRequest>
{
    protected override void Execute(LoanRequest request)
    {
        Console.WriteLine("Execute : ManagerApproverRequestHandler");
    }
}
 
// using 
class Program
{
    static void Main(string[] args)
    {
        BaseRequestHandler<LoanRequest> handler = new FirstApproverRequestHandler();
        BaseRequestHandler<LoanRequest> handler1 = new SecondApproverRequestHandler();
        BaseRequestHandler<LoanRequest> handler2 = new ManagerApproverRequestHandler();
 
        // setup chain of responsibility
        handler.Successor = handler1;
        handler1.Successor = handler2;
 
        // request object
        LoanRequest request = new LoanRequest();
        request.State = State.ApprovedApproval;
 
        // handler -> request executer
        handler.ExecuteRequest(request);
 
        Console.ReadLine();
    }
}