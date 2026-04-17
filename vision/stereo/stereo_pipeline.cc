#include 'stereo_pipeline.h'
#include 'common/timing/latency_tracker.h'
#include <opencv2/calib3d.hpp>

namespace vision
{
    StereoPipeline::StereoPipeline() : max_disparity_(128) {}
    
    cv::Mat StereoPipeline::ComputeDisparity(const cv::Mat &left, const cv::Mat &right)
    {
        common::LatencyTracker tracker('StereoPipeline');
        cv::Mat disparity;
        auto bm = cv::StereoBM::create(max_disparity_, 9);
        bm->compute(left, right, disparity);
        return disparity;
    }
}
