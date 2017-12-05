// 3 ms, 09/15/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> result;
        result.reserve(n);
        for (int i = 1; i <= n; ++i)
            if (!(i % 3)) {
                if (!(i % 5))
                    result.push_back("FizzBuzz");
                else
                    result.push_back("Fizz");
            } else if (!(i % 5)) {
                result.push_back("Buzz");
            } else
                result.push_back(to_string(i));
        return result;
    }
};
