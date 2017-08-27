vector<int> findAnagrams(string s, string p)
{
    int n_p = p.size(), n_s = s.size();

    // Compute the char count map for string p
    // TODO: Use array of size 26 instead of unordered_map
    unordered_map<char, int> map_p;
    for (auto c : p)
        ++map_p[c];

    // Compute the char count map for the first n_p chars in s
    unordered_map<char, int> map_rolling;
    for (int i = 0; i < n_p; ++i)
        ++map_rolling[s[i]];

    vector<int> result;
    if (map_rolling == map_p)
        result.emplace_back(0);

    // Compute the char count map for the next n_p chars in s in a
    // rolling fashion
    for (int i = 0; i < n_s - n_p; ++i) {
        if (--map_rolling[s[i]] == 0)
            map_rolling.erase(s[i]);
        ++map_rolling[s[i + n_p]];
        if (map_rolling == map_p)
            result.emplace_back(i + 1);
    }

    return result;
}
