#pragma once
#include <chrono>
#include <iostream>

class myTimer
{
    std::chrono::time_point<std::chrono::system_clock>  i_start, i_end;
public:
    void start();
    void stop(std::string titleName);
};
