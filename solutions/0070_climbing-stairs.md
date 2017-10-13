# Climbing Stairs

## Fundamental Insight
Since each time, only `1` step or `2` steps are allowed to be taken, to get to the `n`th step, one has to have come from either step `(n - 1)` or step `(n - 2)`. Therefore, the number of ways to take `n` steps, `W(n)`, can be expressed using the following recursive equation:
```
W(n) = W(n - 1) + W(n - 2)
```

The equation is the same as the Fibonnaci sequence.

## Implementation Notes
1. Recursion
   * `O(c^n)` time, `O(1)` space
1. Memoization (recursion with caching)
   * `O(n)` time and space
1. Bottom-up dynamic programming
   * `O(n)` time and space
   * Space can be reduced to `O(1)` by observing that `W(i)` is dependent only on `W(i - 1)` and `W(i - 2)` and optimizing for that
