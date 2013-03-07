//
//  CRunningState.h
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef StateMode_CRunningState_h
#define StateMode_CRunningState_h

#include "CLifeState.h"

class CRunningState : public CLifeState
{
public:
    CRunningState();
    ~CRunningState();
    void Open();
    void Close();
    void Run();
    void Stop();
};

#endif
