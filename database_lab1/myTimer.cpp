#include "myTimer.h"
using namespace std;

void myTimer::start()
{
    i_start = std::chrono::system_clock::now();
}

void myTimer::stop(string titleName)
{
    i_end = std::chrono::system_clock::now();
    auto totalTime = i_end - i_start;
    cout << endl << endl << titleName << " :" << std::chrono::duration_cast<std::chrono::nanoseconds>(totalTime).count() << " nanoseconds" << endl;
}
