// 213 ms, 09/16/2017
// Time  : O(n^2)
// Space : O(m), the max number of unique distances from any point to the rest of the points
// TODO  : Review the faster solution below
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points)
    {
        int total_num = 0;
        for (int i = 0, n = points.size(); i < n; ++i) {
            unordered_map<int, int> map(n); // distance -> number of point pairs
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    continue;
                int first = points[i].first - points[j].first;
                int second = points[i].second - points[j].second;
                ++map[first*first + second*second];
            }
            total_num += accumulate(map.begin(), map.end(), 0,
                                    [] (int sum, const pair<int, int>& x) { return sum + x.second * (x.second - 1); });
        }
        return total_num;
    }
};
/*------------------------------------------------------------------*/
// Faster solution on Leetcode
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int count = 0, n = points.size();
        int dis[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = points[i].first - points[j].first;
                int y = points[i].second - points[j].second;
                dis[j] = x * x + y * y;
            }

            sort(dis, dis + n);
            int k = 1;
            for (int j = 1; j < n; j++) {
                if (dis[j] == dis[j - 1]) {
                    k++;
                } else {
                    count += k * (k - 1);
                    k = 1;
                }
            }
            count += k * (k - 1);
        }
        
        return count;
    }
};
