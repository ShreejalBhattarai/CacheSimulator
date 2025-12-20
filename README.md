# Cache Simulator in C++
**Direct-Mapped Cache, LRU Policy, and Machine Learning–Based Comparison**

## Overview
This project is a **cycle-accurate cache simulator** written in C++ that models the behavior of a **direct-mapped memory cache** and extends it to analyze cache performance using both deterministic and data-driven approaches:

- **Traditional hardware-based cache management**
  - Direct-mapped cache simulation  
  - Least Recently Used (LRU) replacement policy for comparison
- **Machine learning–based cache behavior modeling**
  - Logistic regression model to predict cache hits and misses  
  - Performance evaluation against deterministic cache policies

The goal of this project is to bridge **classical computer architecture concepts** with **modern machine learning techniques**, demonstrating how data-driven approaches can complement or approximate hardware heuristics.

## Cache Architecture Modeled

### Direct-Mapped Cache
- Each memory block maps to exactly **one cache line**  
- Index is derived directly from the memory address  
- Simple and fast, but prone to **conflict misses**

**Address Breakdown**

| Field | Description |
|--------|--------------|
| Tag | Used to validate cache line |
| Index | Selects cache line |
| Offset | Selects data within the block |

### Replacement Policy: LRU (Comparison)
Although a direct-mapped cache does not require replacement logic, this simulator includes an **LRU-based cache model** (set-associative extension) for performance comparison.

**LRU Characteristics**
- Tracks the **recency of access** for all cache lines  
- Evicts the **least recently used** block  
- Approximates real-world cache behavior more accurately than FIFO

This allows:
- Baseline comparison between deterministic policies  
- Ground truth for evaluating ML-based predictions  

## Machine Learning Component: Logistic Regression
This component explores a non-traditional cache management technique—using **logistic regression** to predict cache outcomes.

**Prediction Objective**
- **Cache Hit (1)**  
- **Cache Miss (0)**  

**Why Logistic Regression?**
- Lightweight and interpretable  
- Suitable for binary classification  
- Aligned with hardware constraints due to low computational cost  

**Feature Set**
Extracted from memory access traces:
- Memory address patterns (tag/index bits)  
- Access history (recent hit/miss sequence)  
- Temporal locality features  
- Frequency of block access  

The model outputs the probability of a cache hit:

\[
P(hit) = sigmoid(w0 + w1*x1 + w2*x2 + ... + wn*xn)
\]

Where:
- \(\sigma\): Sigmoid activation function  
- \(w\): Learned weights  
- \(x\): Input features  

## Performance Comparison

| Metric | Direct-Mapped | LRU Cache | Logistic Regression |
|--------|----------------|------------|----------------------|
| Hit Rate | ✓ | ✓✓ | ✓✓ (approximate) |
| Miss Rate | ✓ | ✓✓ | ✓✓ |
| Determinism | High | High | Low |
| Adaptability | Low | Medium | High |
| Compute Overhead | Very Low | Low | Medium |

**Key Insights**
- Logistic regression can **approximate cache behavior trends**.  
- ML models **adapt better to changing access patterns**.  
- Traditional caches remain superior for **latency-critical systems**.  
- ML-based strategies show potential for **adaptive, intelligent caching** in the future.

## Project Structure
```
cache-simulator/
│
├── src/
│   ├── direct_cache.cpp
│   ├── lru_cache.cpp
│   ├── cache_simulator.cpp
│   └── logistic_regression.cpp
│
├── include/
│   ├── cache.h
│   ├── lru.h
│   └── logistic_regression.h
│
├── data/
│   └── memory_trace.txt
│
├── results/
│   └── performance_metrics.csv
│
└── README.md
```

## How It Works
1. **Parse** memory access traces.  
2. **Simulate** cache accesses (index, tag, offset).  
3. **Detect** hits and misses.  
4. **Update** cache state.  
5. **Collect statistics**:
   - Hit rate, miss rate, latency.  
6. **Train logistic regression** on the collected trace.  
7. **Evaluate performance**:
   - Compare ML predictions with actual cache behavior.

## Build and Run
**Compile**
```bash
g++ -std=c++17 src/*.cpp -o cache_simulator
```

**Execute**
```bash
./cache_simulator data/memory_trace.txt
```

## Learning Objectives
- Understand **direct-mapped cache design**  
- Implement **LRU replacement policy**  
- Measure and analyze **cache performance metrics**  
- Apply **machine learning techniques** to computer architecture  
- Compare **deterministic vs. probabilistic** cache models  

## Future Work
- Extend to **N-way set associative caches**  
- Integrate **hardware-friendly ML algorithms**  
- Add **prefetching strategies**  
- Explore **neural networks** and **reinforcement learning** for dynamic cache management  
- Visualize **cache performance trends** over time  

## Author
**Shreejal Bhattarai**  
Electrical & Computer Engineering  
Focus: Computer Architecture, Embedded Systems, Machine Learning for Hardware
