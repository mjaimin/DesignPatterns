//
//  CRunningState.cpp
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "CRunningState.h"
#include "CContext.h"
using namespace std;
CRunningState::CRunningState()
{
}

CRunningState::~CRunningState()
{}

void CRunningState::Open()
{
    this->CLifeState::context->SetLifeState(CContext::openningState);
    this->CLifeState::context->GetLifeState()->Open();
}

void CRunningState::Close()
{
    this->CLifeState::context->SetLifeState(CContext::closingState);
    this->CLifeState::context->GetLifeState()->Close();
}

void CRunningState::Run()
{
    cout<<"电梯上下跑..."<<endl;
}

void CRunningState::Stop()
{
    this->CLifeState::context->SetLifeState(CContext::stoppingState);
    this->CLifeState::context->GetLifeState()->Stop();
}
