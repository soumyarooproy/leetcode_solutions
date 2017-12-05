// 0 ms, 09/13/2017
// Time  : O(n)
// Space : O(n)
// TODO  : Implement a tokenizer using string::find()
class Solution {
public:
    int countSegments(string s)
    {
        stringstream ss(s);
        int count = 0;
        for (string segment; ss; ss >> segment, ++count);
        return count - 1;
    }
};
