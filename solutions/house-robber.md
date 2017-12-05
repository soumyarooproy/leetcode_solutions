# House Robber

## Fundamental Insight
This problem can be rephrased as finding the maximum sum subsequence with the constraints that
1. The subsequence may not have any consecutive elements
1. All array elements are non-negative

The maximum sum subsequence with `A[i]` as the last element, `M[i]`, can be expressed using the following recursive equation: 
```
M(i) = A[i] + max(M(i - 2) + M(i - 3)), 2 < i < n
     = A[0], i = 0
     = A[1], i = 1
     = A[2] + A[0], i = 2
```
The inclusion of the `i`th element in the subsequence precludes the inclusion of `i - 1st` element and the decision to include the `(i - 2)`th or the `(i - 3)`th element depends on whichever gives a larger sum.

The global maximum sum subsequence is then given by:
```
max(M(i)), for all 0 <= i < n
```

## Alternate Insight
Another approach is to think directly in terms of whether the `i`th element should be included in the subsequence or not. If it is, then the maximum sum subsequence till `(i - 2)` elements can be considered. Otherwise, the maximum sum subsequence till `(n - 1)` should be considered. The option that results in a larger sum should be chosen.

This gives the following recursive equation:
```
M'(i) = max(A[i] + M'(i - 2), M'(i - 1)), 2 <= i < n
      = A[0], i = 0
      = max(A[0], A[1]), i = 1
```
This gives a significantly simpler formulation.

## Implementation Notes
1. Recursion
   * `O(c^n)` time, `O(1)` space
1. Memoization (recursion with caching)
   * `O(n)` time and space
1. Bottom-up dynamic programming
   * `O(n)` time and space
   * Space can be reduced to `O(1)` by observing that only a window comprising of the last 3 (or 2) computed values of `M`  (`M'`) needs to be preserved and optimizing for that
