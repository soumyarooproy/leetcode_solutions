# Best Time to Buy and Sell Stock

## Fundamental Insight
The maximum profit that can be made by selling a stock on day `i` is:
```
A[i] - Min(i - 1), i >= 1
```
where
* `A[i]` is the price of the stock on day `i`, and
* `Min(i - 1)` is the minimum price of the stock on day `(i - 1)` or earlier, with `Min(0)` being `A[0]`

If, however, this amount is less than the maximum profit that could have been made by selling the stock at an earlier day, i.e., between day `0` and day `(i - 1)`, then the stock should have been sold during that earlier day
for global maximum profit.

Therefore, the maximum profit that can be made between day `0` and day `i`, `MP(i)`, can be expressed using the following recursive equation:
```
MP(i) = max(A[i] + Min(i - 1), MP(i - 1))
```

## Implementation Notes
1. Recursion
   * `O(n)` time and space
   * No memoization (recursion with caching) needed
1. Bottom-up dynamic programming
   * `O(n)` time and space - if naively implemented
   * Space can be reduced to `O(1)` by observing that  and optimizing for that
