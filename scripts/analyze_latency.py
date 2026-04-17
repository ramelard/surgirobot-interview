import sys
import statistics

def read_latencies(path):
    latencies = []
    with open(path, "r") as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            try:
                latencies.append(int(line))
            except ValueError:
                pass
    return latencies


def percentile(sorted_vals, pct):
    if not sorted_vals:
        return None
    k = int(len(sorted_vals) * pct / 100)
    k = min(k, len(sorted_vals) - 1)
    return sorted_vals[k]


def main(path):
    latencies = read_latencies(path)

    if not latencies:
        print("No latency samples found")
        return

    latencies.sort()

    print(f"Samples: {len(latencies)}")
    print(f"Min    : {latencies[0]} us")
    print(f"Mean   : {int(statistics.mean(latencies))} us")
    print(f"P50    : {percentile(latencies, 50)} us")
    print(f"P90    : {percentile(latencies, 90)} us")
    print(f"P99    : {percentile(latencies, 99)} us")
    print(f"Max    : {latencies[-1]} us")

    # Real-time friendly framing
    deadline_us = 30_000
    misses = sum(1 for x in latencies if x > deadline_us)
    print(f"Deadline misses (> {deadline_us} us): {misses} "
          f"({misses / len(latencies) * 100:.2f}%)")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: analyze_latency.py latency_samples.txt")
        sys.exit(1)

    main(sys.argv[1])