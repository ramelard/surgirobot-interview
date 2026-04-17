#pragma once

#include <string>
#include <mutex>
#include <vector>
#include <cstdint>

namespace common {

class LatencyTracker {
public:
    explicit LatencyTracker(const std::string& name);
    ~LatencyTracker();  // records latency

private:
    std::string name_;
    uint64_t start_;

    // Global shared state
    static std::mutex mutex_;
    static std::vector<uint64_t> latency_buffer_;  // consumed by external service
};

}  // namespace common
