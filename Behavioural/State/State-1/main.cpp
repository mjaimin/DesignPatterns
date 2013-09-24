
#include <iostream>
using namespace std;

class CClosingState;
class COpenningState;
class CRunningState;
class CStoppingState;
class CLifeState;
class CContext;


class CContext
{
    private:
	CLifeState *lifeContext;
    public:
	static CClosingState *closingState;
	static COpenningState *openningState;
	static CRunningState *runningState;
	static CStoppingState *stoppingState;

    CContext();
    

	CLifeState *GetLifeState() { return lifeContext; }
	void SetLifeState(CLifeState *lifeState) { lifeContext = lifeState; }
void Open() ;
void Close();
void Stop() ;
void Run() ;

	~CContext()
	{
	    delete openningState;
	    openningState = NULL;
	    delete closingState;
	    closingState = NULL;
	    delete runningState;
	    runningState = NULL;
	    delete stoppingState;
	    stoppingState = NULL;
	}
};

class CLifeState
{
    protected:
	static CContext *context;
    public:
	CLifeState() { context = NULL; }
	virtual void Open() = 0;
	virtual void Close() = 0;
	virtual void Run() = 0;
	virtual void Stop()= 0;

	void SetContext(CContext *pContext) { context = pContext; }
	virtual ~CLifeState() { context = NULL; }
};


class CClosingState : public CLifeState
{
    public:
	CClosingState() { }
	~CClosingState() {}
    void Open() ;
void Close();
void Stop() ;
void Run() ;



};
class COpenningState : public CLifeState
{
    public:
	COpenningState() { }
	~COpenningState() {}
        void Open() ;
void Close();
void Stop() ;
void Run() ;

};

class CRunningState : public CLifeState
{
    public:

	CRunningState() { }
	~CRunningState() {}
	void Open()
	{
	    this->CLifeState::context->SetLifeState(CContext::openningState);
	    this->CLifeState::context->GetLifeState()->Open();
	}

	void Close()
	{
	    this->CLifeState::context->SetLifeState(CContext::closingState);
	    this->CLifeState::context->GetLifeState()->Close();
	}

	void Run() { cout<<"电梯上下跑..."<<endl; }

	void Stop();
};

class CStoppingState : public CLifeState
{
    public:
	CStoppingState() { }
	~CStoppingState() {}
	void Open()
	{
	    this->CLifeState::context->SetLifeState(CContext::openningState);
	    this->CLifeState::context->GetLifeState()->Open();
	}

	void Close()
	{
	    this->CLifeState::context->SetLifeState(CContext::closingState);
	    this->CLifeState::context->GetLifeState()->Close();
	}

	void Run()
	{
	    this->CLifeState::context->SetLifeState(CContext::runningState);
	    this->CLifeState::context->GetLifeState()->Run();
	}

	void Stop()
	{
	    cout<<"电梯停止了..."<<endl;
	}
};



COpenningState *CContext::openningState = NULL;
CClosingState *CContext::closingState = NULL;
CStoppingState *CContext::stoppingState = NULL;
CRunningState *CContext::runningState = NULL;
CContext *CLifeState::context = NULL;


    void CContext::Open() { this->lifeContext->Open(); }
    void CContext::Close() { this->lifeContext->Close(); }
    void CContext::Stop() { this->lifeContext->Stop(); }
    void CContext::Run() { this->lifeContext->Run(); }
CContext::CContext()
	{
	    lifeContext = NULL;
	    openningState = new COpenningState();
	    closingState = new CClosingState();
	    stoppingState = new CStoppingState();
	    runningState = new CRunningState();
	}
    void CClosingState::Open()
	{
	    this->CLifeState::context->SetLifeState(CContext::openningState);
	    this->CLifeState::context->GetLifeState()->Open();
	}
    void CClosingState::Close() { cout<<"电梯门关闭..."<<endl; }

    void CClosingState::Run()
	{
	    this->CLifeState::context->SetLifeState(CContext::runningState);
	    this->CLifeState::context->GetLifeState()->Run();
	}

    void CClosingState::Stop()
	{
	    this->CLifeState::context->SetLifeState(CContext::stoppingState);
	    this->CLifeState::context->GetLifeState()->Stop();
	}
        void COpenningState::Open() { cout<<"电梯门打开..."<<endl; }
	void COpenningState::Close()
	{
	    this->CLifeState::context->SetLifeState(CContext::closingState);
	    this->CLifeState::context->GetLifeState()->Close();
	}
	void COpenningState::Run()
	{
	    this->CLifeState::context->SetLifeState(CContext::runningState);
	    this->CLifeState::context->GetLifeState()->Run();
	}
	void COpenningState::Stop()
	{
	    this->CLifeState::context->SetLifeState(CContext::stoppingState);
	    this->CLifeState::context->GetLifeState()->Stop();
	}
    
        void CRunningState::Stop()
	{
	    this->CLifeState::context->SetLifeState(CContext::stoppingState);
	    this->CLifeState::context->GetLifeState()->Stop();
	}
int main()
{
    CContext context;
    CLifeState lifeState;
    lifeState.SetContext(&context);
    context.SetLifeState(CContext::closingState);
    context.Close();
    context.Open();
    context.Run();
    context.Stop();
    context.Close();
    context.Close();
    context.Open();
    context.Stop();
    context.Run();
    context.Stop();
}
