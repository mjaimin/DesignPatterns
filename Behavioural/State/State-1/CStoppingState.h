//
//  CStoppingState.h
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef StateMode_CStoppingState_h
#define StateMode_CStoppingState_h

#include "CLifeState.h"

class CStoppingState : public CLifeState
{
public:
    CStoppingState();
    ~CStoppingState();
    void Open();
    void Close();
    void Run();
    void Stop();
};


#endif
