#include "Timer.h"

bool Timer::timer()
{
    static  int startTime = 0;
    int endTime = clock();
    if (endTime - startTime >= dis)
    {
        startTime = endTime;
        return true;
    }
    return false;
}
