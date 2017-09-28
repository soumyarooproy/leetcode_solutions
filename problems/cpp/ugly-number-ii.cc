// 16 ms, 09/27/2017
// Time  : O(n)
// Space : O(n)
// TODO  : More compact solution below
using std::vector;
using std::priority_queue;
class Solution {
private:
    struct q_entry { long num, idx; };
public:
    int nthUglyNumber(int n)
    {
        if (n <= 0)
            return 0;
        
        auto comp = [] (const q_entry& x, const q_entry& y) { return x.num > y.num; };
        priority_queue<q_entry, vector<q_entry>, decltype(comp)> min_heap(comp);
        min_heap.push({1, 2});
        
        q_entry res;
        for (int k = 1; k <= n; ++k) {
            res = min_heap.top();
            min_heap.pop();
            if (res.idx == 2) {
                min_heap.push({res.num * 2, 2});
                min_heap.push({res.num * 3, 3});
            } else if (res.idx == 3) {
                min_heap.push({res.num * 3, 3});
            }
            min_heap.push({res.num * 5, 5});
        }

        return res.num;
    }
};
/*------------------------------------------------------------------*/
// 4 ms solution on leetcode
class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector <int> results (1,1);
        int i = 0, j = 0, k = 0;
        while (results.size() < n)
        {
            results.push_back(min(results[i] * 2, min(results[j] * 3, results[k] * 5)));
            if (results.back() == results[i] * 2) ++i;
            if (results.back() == results[j] * 3) ++j;
            if (results.back() == results[k] * 5) ++k;
        }
        return results.back();
    }
};
