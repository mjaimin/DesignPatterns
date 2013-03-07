//
//  CContext.cpp
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "CContext.h"

COpenningState *CContext::openningState = NULL;
CClosingState *CContext::closingState = NULL;
CStoppingState *CContext::stoppingState = NULL;
CRunningState *CContext::runningState = NULL;

CContext::CContext()
{
    lifeContext = NULL;
    openningState = new COpenningState();
    closingState = new CClosingState();
    stoppingState = new CStoppingState();
    runningState = new CRunningState();
}

CContext::~CContext()
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

CLifeState *CContext::GetLifeState()
{
    return lifeContext;
}

void CContext::SetLifeState(CLifeState *lifeState)
{
    lifeContext = lifeState;
}

void CContext::Open()
{
    this->lifeContext->Open();
}

void CContext::Close()
{
    this->lifeContext->Close();
}

void CContext::Stop()
{
    this->lifeContext->Stop();
}

void CContext::Run()
{
    this->lifeContext->Run();
}