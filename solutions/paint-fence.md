# Paint Fence

## Fundamental Insight
* Let `SC(i)` indicate the number of ways of coloring the `i`th post so that the `(i - 1)`th post and the `i`th post have the same color
* Let `DC(i)` indicate the number of ways of coloring the `i`th post so that the `(i - 1)`th post and the `i`th post have different colors

The following recursive equations hold:
```
SC[i] = DC[i - 1]
```
The `i`th post has to be colored with `(i - 1)`th post's color, which has to be different than `(i - 2)`th post's color.
```
DC[i] = (SC[i - 1] + DC[i - 1]) * (k - 1)
```
The `i`th post can be colored with anything other than `(i - 1)`th post's color; there are `(k - 1)` options to do so

## Implementation Notes
1. Recursion (memoization does not help; confirm by drawing the call tree)
   * `O(n)` time and space
1. Bottom-up dynamic programming
   * `O(n)` time and space
   * Space can be reduced to `O(1)` by observing that the computing `SC` and `DC` for the `i`th element is dependent only on the same for the `(i - 1)`th element and optimizing for that
