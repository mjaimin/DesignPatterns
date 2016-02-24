class SwipeCard
class Project;
class Manager
{
    public:
	Project oProject ;
	Manager()
	{
	    oProject = new Project(this);
	}
	std::list<Worker> Workers = new std::list<Worker>();
	void Logon(SwipeCard obj)
	{
	    obj.Swipe(this);
	}
	string GetManagerName()
	{
	    return "Shiv";
	}
	double Salary;

	void HowisTheManager(bool Good)
	{
	    if (Good)
	    {
		oProject.Issuccess = true;
	    }
	    else
	    {
		oProject.Issuccess = false;
	    }
	}
}

class SwipeCard
{

    public:
	void Swipe(Manager obj)
	{
	    // goes and swipes the manager
	}
	string MakeofSwipecard()
	{
	    return "c001";
	}
}

class Worker
{
    public:
	string WorkerName = "";
}
class Project
{
    private: 
	Manager omanager;
	bool IsSuccess = false;

    public:
	void getSuccess() 
	{ 
	    return IsSuccess; 
	}
	void setSuccess( bool value ) 
	{ 
	    IsSuccess = value;
	    if (value)
	    {
		omanager.Salary++;
	    }
	    else
	    {
		omanager.Salary--;
	    }
	}

	Project(Manager obj)
	{
	    omanager = obj;
	}
}
