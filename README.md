# SurgiBot Fake Monorepo

Simplified stereo-vision stack used for development and analysis.

## Repository Structure

```
surgibot/
├── common/
│   └── timing/
│       ├── frame_time.h          # Latency helper functions
│       ├── latency_tracker.h     # LatencyTracker class declaration
│       └── latency_tracker.cc    # RAII latency tracker; logs elapsed time on destruction
├── vision/
│   └── stereo/
│       ├── stereo_pipeline.h     # StereoPipeline class declaration
│       └── stereo_pipeline.cc    # ComputeDisparity() using OpenCV StereoBM
├── scripts/
│   └── analyze_latency.py        # Parses latency log output and prints frame count, avg, and max
└── WORKSPACE                     # Bazel workspace root
```

## Building

Uses [Bazel](https://bazel.build/).

```sh
bazel build //vision/stereo:stereo_pipeline
```

## Latency Analysis

`LatencyTracker` is an RAII object that measures elapsed microseconds between construction and destruction. A consumer reads adn writes latency value to a log file. To analyze a captured log:

```sh
python scripts/analyze_latency.py <logfile>
```

## Dependencies

- [OpenCV](https://opencv.org/) — stereo block matching (`cv::StereoBM`)
- C++11 or later
- Python 3 (for analysis script)