//
//  CContext.h
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef StateMode_CContext_h
#define StateMode_CContext_h

#include "CLifeState.h"
#include "CClosingState.h"
#include "COpenningState.h"
#include "CRunningState.h"
#include "CStoppingState.h"

class CContext
{
public:
    CContext();
    ~CContext();
    static CClosingState *closingState;
    static COpenningState *openningState;
    static CRunningState *runningState;
    static CStoppingState *stoppingState;
    CLifeState *GetLifeState();
    void SetLifeState(CLifeState *lifeState);
    void Open();
    void Close();
    void Run();
    void Stop();
private:
    CLifeState *lifeContext;
};

#endif
