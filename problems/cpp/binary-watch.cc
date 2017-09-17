// 0 ms, 09/16/2017
// Time  : O(n!), n is 10
// Space : O(n), n is 10
// TODO  : Check the compact solution using bitset below; also use
//         recursion to generate the permutations (with duplicates)
class Solution {
public:
    vector<string> readBinaryWatch(int num)
    {
        string bit_repr = string(10 - num, '0') + string(num, '1');
        vector<string> times;
        do {
            string time_str;
            if ((time_str = bit_string_to_time(bit_repr)) != ":")
                times.push_back(time_str);
        } while (next_permutation(bit_repr.begin(), bit_repr.end()));
        return times;
    }
private:
    string bit_string_to_time(string bits)
    {
        string str;
        
        // hour
        int val = 0;
        for (int i = 0; i < 4; ++i)
            val = (val << 1) + (bits[i] == '1');
        if (val >= 12)
            return ":";
        
        str += to_string(val) + ":";
        
        // minute
        val = 0;
        for (int i = 0; i < 6; ++i)
            val = (val << 1) + (bits[4 + i] == '1');
        if (val >= 60)
            return ":";
        
        str += (val < 10 ? "0" : "") + to_string(val);

        return str;
    }
};
/*-------------------------------------------------------------*/
vector<string> readBinaryWatch(int num) {
    vector<string> rs;
    for (int h = 0; h < 12; h++)
    for (int m = 0; m < 60; m++)
        if (bitset<10>(h << 6 | m).count() == num)
            rs.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
    return rs;
}
