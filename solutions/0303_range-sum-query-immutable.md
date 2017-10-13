# Range Sum Query - Immutable

## Fundamental Insight
Compute the prefix sums of the array elements:
```
P[i] = A[i - 1] + P[i - 1], 1 <= i < n
     = A[0], i == 0
```
Subarray sum for the range `[i, j], 0 <= i <= j < n` can then be computed as:
```
S([i, j]) = P[j] - P[i - 1], 1 <= i <= j < n
          = P[j], i == 0
```

## Implementation Notes
* The prefix sums can be computed simply using a `for`-loop although it can also be computed recursively
* `O(n)` time to compute the prefix sums
* `O(1)` time to compute the subarray sum
* `O(n)` space
