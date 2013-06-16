//
//  main.cpp
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "CLifeState.h"
#include "CContext.h"
#include "CClosingState.h"
#include "COpenningState.h"
#include "CRunningState.h"
#include "CStoppingState.h"

void DoNew()
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

int main(int argc, const char * argv[])
{
    // insert code here...
    printf("******State*********\n");
    DoNew();
    return 0;
}

