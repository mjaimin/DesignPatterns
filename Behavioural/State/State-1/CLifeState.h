//
//  CLifeState.h
//  StateMode
//
//  Created by Gun Li on 4/5/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef StateMode_CLifeState_h
#define StateMode_CLifeState_h

class CContext;

class CLifeState
{
public:
    CLifeState();
    virtual ~CLifeState();
    static void SetContext(CContext *pContext);
    virtual void Open() = 0;
    virtual void Close() = 0;
    virtual void Run() = 0;
    virtual void Stop()= 0;
protected:
    static CContext *context;
};


#endif
