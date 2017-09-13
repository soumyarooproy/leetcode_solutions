// 0 ms, 09/13/2017
// Time  : O(n), total number of elements
// Space : O(d), nesting depth
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depth_sum(const vector<NestedInteger>& nested_list, int depth) {
        int sum = 0;
        for (auto& x: nested_list)
            sum += (x.isInteger()) ? x.getInteger() * depth : depth_sum(x.getList(), depth + 1);
        return sum;
    }
    int depthSum(vector<NestedInteger>& nestedList) {
        return depth_sum(nestedList, 1);
    }
};
