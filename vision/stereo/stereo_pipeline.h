#pragma once
#include <opencv2/core.hpp>
namespace vision
{
    class StereoPipeline
    {
    public:
        StereoPipeline();
        cv::Mat ComputeDisparity(const cv::Mat &left, const cv::Mat &right);

    private:
        int max_disparity_;
    };
}
