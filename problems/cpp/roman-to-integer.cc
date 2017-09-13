// 66 ns, 09/13/2017
// Time  : O(n)
// Space : O(m), size of the Roman numeral set
class Solution {
public:
    int romanToInt(string s)
    {
        if (!s.size())
            return 0;
        
        array<int, 26> val;
        val['I' - 'A'] = 1;
        val['V' - 'A'] = 5;
        val['X' - 'A'] = 10;
        val['L' - 'A'] = 50;
        val['C' - 'A'] = 100;
        val['D' - 'A'] = 500;
        val['M' - 'A'] = 1000;
        
        int result = val[s.back() - 'A'];
        for (int i = s.size() - 2; i >= 0 ; --i)
            result += (val[s[i + 1] - 'A'] > val[s[i] - 'A']) ? -val[s[i] - 'A'] : val[s[i] - 'A'];
        
        return result;
    }
};
