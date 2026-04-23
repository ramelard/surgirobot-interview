#pragma once
#include <opencv2/core.hpp>
namespace vision
{
    // (Incomplete) minimal stereoscopic imaging pipeline with depth mapping.
    class StereoPipeline
    {
    public:
        StereoPipeline();

        // Called on every stereo frame acquisition.
        cv::Mat ComputeDisparity(const cv::Mat &left, const cv::Mat &right);

    private:
        int max_disparity_;
    };
}
