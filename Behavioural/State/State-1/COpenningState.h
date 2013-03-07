//
//  COpenningState.h
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef StateMode_COpenningState_h
#define StateMode_COpenningState_h
#include "CLifeState.h"

class COpenningState : public CLifeState
{
public:
    COpenningState();
    ~COpenningState();
    void Open();
    void Close();
    void Run();
    void Stop();
};

#endif
