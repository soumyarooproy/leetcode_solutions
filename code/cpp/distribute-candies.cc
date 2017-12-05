// 279 ms, 09/07/2017
// Time  : O(n)
// Space : O(m), m is the distinct types of candies
// TODO  : Use a bit vector (or bitset) to speed up
int distributeCandies(vector<int>& candies)
{
    unordered_map<int, int> candy_map;

    for (auto& x : candies)
        ++candy_map[x];

    return min(candy_map.size(), candies.size() / 2);

}
