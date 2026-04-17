
#include "latency_tracker.h"
#include "frame_time.h"

namespace common {

std::mutex LatencyTracker::mutex_;
std::vector<uint64_t> LatencyTracker::latency_data_;

LatencyTracker::LatencyTracker(const std::string& name)
    : name_(name), start_(NowMicros()) {}

LatencyTracker::~LatencyTracker() {
    uint64_t end = NowMicros();
    uint64_t latency = end - start_;

    std::lock_guard<std::mutex> lock(mutex_);
    samples_.push_back(latency_data_);
}

}  // namespace common
