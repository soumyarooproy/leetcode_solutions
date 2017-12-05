vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    // All anagrams of a word have the same char->freq map
    // Construct a map from char->freq map to set (array) of words
    unordered_map<string, vector<string>> anagrams;
    for (auto& str : strs) {
        string str_copy(str);
        sort(str_copy.begin(), str_copy.end());
        anagrams[str_copy].emplace_back(str);
    }

    // Return the map contents as a vector
    vector<vector<string>> result;
    result.reserve(anagrams.size());
    for (auto& entry : anagrams) {
        result.emplace_back(move(entry.second));
    }

    return result;
}

/*------------------------------------------------------------------------*/

// Faster solution on leetcode
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<int,vector<string>> map;
    for(string s:strs){
        int ret = 1;
        for(char c:s)
            ret *= (c*c+c+41) % INT_MAX;
        map[ret].push_back(s);
    }
    vector<vector<string>> ret;
    for(auto x:map)
       ret.emplace_back(x.second);
    return ret;
}
