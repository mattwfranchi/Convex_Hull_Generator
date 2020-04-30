//
// Created by Matt Franchi on 3/4/20.
//

#include "Cilli.h"

int main()
{
    Cilli C;
    // insertItem test
    for(int n = 0; n < 1000; n ++)
    {
        C.insertItem(n);
        C.dumpForwards();
        C.dumpBackwards();
    }

    // deleteItem test
    for(int n = 0; n < 1000; n ++)
    {
        C.deleteItem();
        C.dumpForwards();
        C.dumpBackwards();
    }


    
    for(int n = 0; n < 1000; n ++)
    {
        C.insertItem(n);
        C.dumpForwards();
        C.dumpBackwards();
    }

    // moveHandleForward test
    for(int n = 0; n < 1000; n ++)
    {
        C.moveHandleForward();
        C.dumpForwards();
        C.dumpBackwards();
    }

    // moveHandleBack test
    for(int n = 0; n < 1000; n ++)
    {
        C.moveHandleBack();
        C.dumpForwards();
        C.dumpBackwards();
    }

    // destructor test




}