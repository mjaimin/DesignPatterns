//
//  ClosingState.cpp
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "CClosingState.h"
#include "CContext.h"
using namespace std;

CClosingState::CClosingState()
{
}

CClosingState::~CClosingState()
{}

void CClosingState::Open()
{
    this->CLifeState::context->SetLifeState(CContext::openningState);
    this->CLifeState::context->GetLifeState()->Open();
}

void CClosingState::Close()
{
    cout<<"电梯门关闭..."<<endl;
}

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
