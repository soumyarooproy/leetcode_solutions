// 0 ms, 09/09/2017
// Time  : O(n)
// Space : O(m), m is the number of letters in the english alphabet
class Solution {
public:
    vector<string> findWords(vector<string>& words)
    {
        vector<vector<char>> keyb_rows({
            {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
            {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
            {'z', 'x', 'c', 'v', 'b', 'n', 'm'},
        });
        array<int, 256> char2row;
        for (int i = 0; i < 3; ++i)
            for (auto c : keyb_rows[i])
                char2row[c] = i, char2row[toupper(c)] = i;
        
        vector<string> result;
        for (auto& word : words) {
            int row = char2row[word[0]];
            bool is_good = true;
            for (auto c : word)
                if (char2row[c] != row) {
                    is_good = false;
                    break;
                }
            if (is_good)
                result.emplace_back(word);
        }
        
        return result;
    }
};
