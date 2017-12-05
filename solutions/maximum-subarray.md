# Maximum Subarray

## Fundamental Insight
The maximum sum subarray with `A[i]` as the *last element*, `M(i)` can be expressed using the following recursive relation:
```
M(i) = A[i] + M(i - 1) if M(i - 1) > 0 else A[i], 0 < i < n
     = A[0], i == 0
```
The global max sum subarray is then given by
```
max(M(i)), for all 0 <= i < n
```

## Implementation Notes
1. Recursion
   * `O(n)` time and space
   * Maintain a running max
1. Bottom-up dynamic programming
   * `O(n)` time and space
   * Space can be reduced to `O(1)` by observing that `M(i)` is dependent only on `M(i - 1)` and optimizing for that
