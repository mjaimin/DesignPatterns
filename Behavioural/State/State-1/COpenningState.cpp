//
//  COpenningState.cpp
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "COpenningState.h"
#include "CContext.h"
using namespace std;

COpenningState::COpenningState()
{
}

COpenningState::~COpenningState()
{}

void COpenningState::Open()
{
    cout<<"电梯门打开..."<<endl;
}

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
