//
//  CLifeState.cpp
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "CLifeState.h"
CContext *CLifeState::context = NULL;

CLifeState::CLifeState()
{
    context = NULL;
}

CLifeState::~CLifeState()
{
    context = NULL;
}

void CLifeState::SetContext(CContext *pContext)
{
    context = pContext;
}