
#include <iostream>

COpenningState *CContext::openningState = NULL;
CClosingState *CContext::closingState = NULL;
CStoppingState *CContext::stoppingState = NULL;
CRunningState *CContext::runningState = NULL;

class CContext
{
    private:
	CLifeState *lifeContext;
    public:
	static CClosingState *closingState;
	static COpenningState *openningState;
	static CRunningState *runningState;
	static CStoppingState *stoppingState;

	CContext()
	{
	    lifeContext = NULL;
	    openningState = new COpenningState();
	    closingState = new CClosingState();
	    stoppingState = new CStoppingState();
	    runningState = new CRunningState();
	}

	CLifeState *GetLifeState() { return lifeContext; }
	void SetLifeState(CLifeState *lifeState) { lifeContext = lifeState; }
	void Open() { this->lifeContext->Open(); }
	void Close() { this->lifeContext->Close(); }
	void Stop() { this->lifeContext->Stop(); }
	void Run() { this->lifeContext->Run(); }

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


CContext *CLifeState::context = NULL;

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
	void Open()
	{
	    this->CLifeState::context->SetLifeState(CContext::openningState);
	    this->CLifeState::context->GetLifeState()->Open();
	}
	void Close() { cout<<"电梯门关闭..."<<endl; }

	void Run()
	{
	    this->CLifeState::context->SetLifeState(CContext::runningState);
	    this->CLifeState::context->GetLifeState()->Run();
	}

	void Stop()
	{
	    this->CLifeState::context->SetLifeState(CContext::stoppingState);
	    this->CLifeState::context->GetLifeState()->Stop();
	}

};
class COpenningState : public CLifeState
{
    public:
	COpenningStateCOpenningState() { }
	COpenningState~COpenningState() {} 
	void Open() { cout<<"电梯门打开..."<<endl; }
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
	    this->CLifeState::context->SetLifeState(CContext::stoppingState);
	    this->CLifeState::context->GetLifeState()->Stop();
	}
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

	void Stop()
	{
	    this->CLifeState::context->SetLifeState(CContext::stoppingState);
	    this->CLifeState::context->GetLifeState()->Stop();
	}
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
int main()
{
    //LiftState.h, LiftState.cpp, OpenningState.h, CloseingState.h, RunningState.h, StoppingState.h
    //Context.h, Context.cpp
    CContext context;
    CLifeState::SetContext(&context);
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
