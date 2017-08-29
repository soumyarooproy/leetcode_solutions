class Solution {
private:
    struct greater_pair_second {
        bool operator()(const pair<char, int>& x1, const pair<char, int>& x2) {
            return x1.second < x2.second;
        }
    };
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> char_count;        
        for (auto c : s) {
            ++char_count[c];
        }
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater_pair_second> max_heap;
        for (auto& x : char_count) {
            max_heap.push(move(x));
        }
        
        string result;
        while (!max_heap.empty()) {
            result += string(max_heap.top().second, max_heap.top().first);
            max_heap.pop();
        }
        
        return result;
    }
};

/*------------------------------------------------------------------------------*/
// TODO: faster solution on leetcode
string frequencySort(string s) {

    vector<int> mp(128,0);

    for (char c :s)
    {
        mp[c]++;
    }


    map<int,vector<char>,greater<int>> mp2;

    for (int i=0; i<128; ++i)
    {
        if (mp[i])
            mp2[mp[i]].push_back(i);
    }

    string res;

    for (auto& pr:mp2)
    {

        for (char ch:pr.second)
        {
            res.append(pr.first,ch);
        }
    }

    return res;
}
