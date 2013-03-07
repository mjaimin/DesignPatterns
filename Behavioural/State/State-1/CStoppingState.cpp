//
//  CStoppingState.cpp
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "CStoppingState.h"
#include "CContext.h"
using namespace std;
CStoppingState::CStoppingState()
{
}

CStoppingState::~CStoppingState()
{}

void CStoppingState::Open()
{
    this->CLifeState::context->SetLifeState(CContext::openningState);
    this->CLifeState::context->GetLifeState()->Open();
}

void CStoppingState::Close()
{
    this->CLifeState::context->SetLifeState(CContext::closingState);
    this->CLifeState::context->GetLifeState()->Close();
}

void CStoppingState::Run()
{
    this->CLifeState::context->SetLifeState(CContext::runningState);
    this->CLifeState::context->GetLifeState()->Run();
}

void CStoppingState::Stop()
{
    cout<<"电梯停止了..."<<endl;
}
