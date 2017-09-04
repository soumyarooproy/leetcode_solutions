// 16 ms, 09/03/2017
// TODO: O(n * k) solution - can it be O(n)?
string removeKdigits(string num, int k)
{
    if (k >= num.size())
        return "0";

    string result;

    auto it = num.begin(), end = num.end();
    while (k) {
        // Find the min of the next k + 1 digits because
        // keeping that will result in the smallest number
        auto it_min = min_element(it, it + k + 1);
        k -= (it_min - it);
        // Skip any leading 0's
        if (!result.empty() || *it_min != '0')
            result += *it_min;
        it = it_min + 1; 
    }

    // Append the remaining digits
    if (it < num.end())
        result += num.substr(it - num.begin());

    return result.empty()? "0" : result;
}
/*------------------------------------------------------------*/
// TODO: Faster (3 ms) solution on leetcode
string removeKdigits(string num, int k) {
    string res;
    if (num.empty()) return res;
    int keep = num.size() - k;

    for (int i = 0; i < num.size(); i++) {
        while(!res.empty() && num[i] < res.back() && k > 0) {
            res.pop_back();
            k--;
        }
        res.push_back(num[i]);
    }
    res.resize(keep);
    while(*res.begin() == '0') {
        res= res.substr(1);
    }
    return res.empty()?"0":res;
}
