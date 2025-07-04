#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"

int main()
{
    int step = CarType_Q;
    int answer;
    while (1)
    {
        printProcess(step);

        answer = checkExitOrNum();

        if (answer == EXIT_FLAG) break;
        if (answer == NONUM_FLAG) continue;
        if (answer == 0 && step == Run_Test)
        {
            step = CarType_Q;
            continue;
        }

        switch (step)
        {
        case CarType_Q:
            step = carTypeProcess(answer);
            break;
        case Engine_Q:
            step = engineProcess(answer);
            break;
        case brakeSystem_Q:
            step = brakeSystemProcess(answer);
            break;
        case SteeringSystem_Q:
            step = steeringSystemProcess(answer);
            break;
        case Run_Test:
            step = runTestProcess(answer);
            break;
        }

    }
}
#endif
