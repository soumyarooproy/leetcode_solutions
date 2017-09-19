// 35 ms, 09/18/2017
// Time  : O(n)
// Space : O(m), longest substring with unique characters
// TODO  : Refer to the better solution below 
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int max_len = 0;
        unordered_map<char, int> map;
        for (int i = 0, j = i, n = s.size(); i < n; ++i) {
            auto it = map.find(s[i]);
            // If s[i] is already in the map, s[j, i) is a
            // candidate longest substring
            if (it != map.end()) {
                max_len = max(max_len, static_cast<int>(map.size())); 
                while (j <= it->second)
                    map.erase(s[j++]);
            }
            map[s[i]] = i;
        }
        return max(max_len, static_cast<int>(map.size()));
    }
};
/*--------------------------------------------------------------*/
// Better solution on leetcode, 9 ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int place[255];
        fill(place, place + 255, -1);
        int start = 0;
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            if(place[s[i]] >= start){
                result = max(result, i - start);
                start = place[s[i]] + 1;
            }
            place[s[i]] = i;
        }
        return max(result, int(s.size()) - start);
    }
};
