---
layout: default
title: "HW08: STL Benchmarks"
due: "Mon Apr 13, 11:59pm"
categories: [assignments]
---

# HW08: STL Benchmarks

As discussed in the videos related to this assignment ([here](https://youtu.be/ViXI87a4gYo) and [here](https://youtu.be/v1JmGCd-1Xg) and [here](https://youtu.be/nSPb7AAAosQ)), the various containers in the standard C++ library have different performance characteristics.

## Task

Using the Google Benchmark framework, demonstrate the performance of each of the following actions, operating on containers of a range of sizes:

Vector:

- `push_back`, insert at front (`myvec.insert(myvec.begin(), value)` -- correction from the video), iterate through whole container, `find`, `sort`

Deque:

- `push_back`, `push_front`, iterate through whole container, `find`, `sort`

List:

- `push_back`, `push_front`, iterate through whole container, `find`, `sort`

Set:

- `insert`, `find`, iterate through whole container

Unordered set:

- `insert`, `find`, iterate through whole container

## Example code

Here is some example starting code:

```
#include <benchmark/benchmark.h>
#include <vector>
#include <random>
using namespace std;

static void push_back_vector(benchmark::State& state) {
    for(auto _ : state) {
        vector<int> myvec;
        for(int i = 0; i < state.range(0); i++) {
            myvec.push_back(rand());
        }
    }
}
BENCHMARK(push_back_vector)->Range(1, 1e6);
```

See the [video](https://youtu.be/nSPb7AAAosQ) related to this homework for some explanation of the Google Benchmark framework.

## Makefile

Use this makefile:

```
CXXFLAGS=-Wall -std=c++11 -isystem /opt/google-benchmark/include -L/opt/google-benchmark/build/src -lbenchmark -lbenchmark_main -lpthread

main: main.cpp
        g++ main.cpp $(CXXFLAGS) -o main

.PHONY: clean
clean:
        rm main
```

