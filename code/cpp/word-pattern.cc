// 0 ms, 09/12/2017
// Time  : O(n)
// Space : O(m), number of distinct elements
class Solution {
private:
    vector<string> tokenize(string str, char delim = ' ')
    {
        vector<string> tokens;
        for (auto it = str.begin(), it_end = it, end = str.end(); it < end; it = it_end + 1) {
            it_end = find(it, end, ' ');
            tokens.emplace_back(it, it_end);
            it = it_end + 1;
        }
        return tokens;
    }
public:
    bool wordPattern(string pattern, string str)
    {
        auto tokens = tokenize(str);
        if (tokens.size() != pattern.size())
            return false;
        array<int, 26> map; unordered_set<string> mapped_set;
        map.fill(-1);
        for (int i = 0, n = pattern.size(); i < n; ++i) {
            auto& mapping = map[pattern[i] - 'a'];
            if (mapping == -1) {
                if (!mapped_set.insert(tokens[i]).second)
                    return false;
                else
                    mapping = i;
            } else if (tokens[mapping] != tokens[i])
                return false;

        }
        return true;
    }
};
/*-------------------------------------------------------------------*/
// TODO  : More compact solution on leetcode
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        istringstream in(str);
        int i=0;
        for (string word; in >> word; i++){
            if(m1.find(pattern[i])!=m1.end() || m2.find(word)!=m2.end()){
                if(m1[pattern[i]]!=m2[word]) return false;
            }
            else{
                m1[pattern[i]]=i+1;
                m2[word]=i+1;
            }
        }
        return i==pattern.size();
    }
};
