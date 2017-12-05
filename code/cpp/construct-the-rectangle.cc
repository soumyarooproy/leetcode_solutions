// 0 ms, 09/15/2017
// Time  : O(sqrt(n))
// Space : O(1)
class Solution {
public:
    vector<int> constructRectangle(int area)
    {
        int max_width = static_cast<int>(floor(sqrt(area)));
        for (int i = max_width; i > 1; --i)
            if (!(area % i))
                return { area / i, i};
        return {area, 1};
    }
};
