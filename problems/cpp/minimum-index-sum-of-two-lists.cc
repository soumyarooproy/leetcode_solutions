// 99 ms, 09/05/2017
// Time  : O(n1 + n2 + m lg m), m is the number of common items
// Space : O(n1 + m)
vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
{
    unordered_map<string, int> pref1;
    map<int, vector<string>> most_preferred;

    int i = 0;
    for (auto& x : list1)
        pref1[x] = i++;

    for (int i = 0, n2 = list2.size(); i < n2; ++i) {
        auto x = list2[i];
        if (pref1.count(x))
            most_preferred[i + pref1[x]].emplace_back(x);
    }

    return most_preferred.empty() ? vector<string>({}) : most_preferred.begin()->second;
}
