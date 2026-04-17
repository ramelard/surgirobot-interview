#pragma once
#include <chrono>

namespace common
{
    inline uint64_t NowMicros() { 
        return std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count(); 
    }
}
