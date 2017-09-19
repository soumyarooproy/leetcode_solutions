// 19 ms, 09/18/2017
// Time  : O(n)
// Space : O(1)
// TODO  : Take a look at the solution below
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int max_area = 0;
        for (int i = 0, j = height.size() - 1; i < j; ) {
            max_area = max(max_area, (j - i) * min(height[i], height[j]));
            if (height[i] > height[j])
                --j;
            else if (height[i] < height[j])
                ++i;
            else
                ++i, --j;
        }
        return max_area;
    }
};
/*--------------------------------------------------------*/
// A more compact solution on leetcode
class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j){
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return water;
    }
};
