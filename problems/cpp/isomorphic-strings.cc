// 16 ms, 09/03/2017
vector<vector<int>> string_to_indices(const string& s)
{
    unordered_map<char, int> char_first_index;
    vector<vector<int>> indices;
    for (int i = 0; i < s.size(); ++i) {
        if (!char_first_index.count(s[i])) {
            indices.emplace_back();
            char_first_index[s[i]] = indices.size() - 1;
        }
        indices[char_first_index[s[i]]].emplace_back(i);
    }
    return indices;
}

bool isIsomorphic(string s, string t)
{
    auto indices_s = move(string_to_indices(s));
    auto indices_t = move(string_to_indices(t));

    return indices_s == indices_t;
}
/*---------------------------------------------------------------*/
// TODO: Faster solution (6 ms) on leetcode
bool isIsomorphic(string s, string t) {
    vector<int> m(256, 0), n(256, 0);
    for (int i = 0; i < s.size(); i++) {
        if (m[s[i]] != n[t[i]])
            return false;
        m[s[i]] = i+1;
        n[t[i]] = i+1;
    }
    return true;
}
