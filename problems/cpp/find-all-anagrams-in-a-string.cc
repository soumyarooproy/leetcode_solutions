vector<int> findAnagrams(string s, string p)
{
    int n_p = p.size(), n_s = s.size();

    // Compute the char count map for string p
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

/*-----------------------------------------------------------------------*/

vector<int> findAnagrams(string s, string p)
{
    int n_p = p.size(), n_s = s.size();
    
    if (n_s < n_p)
        return {};

    // Compute the char count map for string p
    array<int, 26> map_p;
    fill(map_p.begin(), map_p.end(), 0);
    for (auto c : p)
        ++map_p[c - 'a'];

    // Compute the char count map for the first n_p chars in s
    array<int, 26> map_rolling;
    fill(map_rolling.begin(), map_rolling.end(), 0);
    for (int i = 0; i < n_p; ++i)
        ++map_rolling[s[i] - 'a'];

    vector<int> result;
    if (map_rolling == map_p)
        result.emplace_back(0);

    // Compute the char count map for the next n_p chars in s in a
    // rolling fashion
    for (int i = 0; i < n_s - n_p; ++i) {
        --map_rolling[s[i] - 'a'];
        ++map_rolling[s[i + n_p] - 'a'];
        if (map_rolling == map_p)
            result.emplace_back(i + 1);
    }

    return result;
}

/*-----------------------------------------------------------------------*/

// This is one of the faster solutions on leetcode
vector<int> findAnagrams(string s, string p)
{
    vector<int> res, hash(256, 0);
    if (s.size() < p.size()) return res;

    for (char c : p)
        hash[c]++;

    int left = 0, right = 0, cnt = p.size();

    while (right < s.size()) {
        if (hash[s[right++]]-- >= 1) cnt--;
        if (cnt == 0) res.push_back(left);
        if (right-left == p.size() && hash[s[left++]]++ >= 0) cnt++;
    }
    return res;
}
