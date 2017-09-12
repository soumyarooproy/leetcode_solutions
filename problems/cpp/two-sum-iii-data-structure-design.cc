// 96 ms, 09/12/2017
// Time  : O(n lg n) for add() and O(n) for find()
// Space : O(n)
// TODO  : Implement using a hash table, ~35 ms solution(s) on leetcode
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number)
    {
        sorted.insert(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if (sorted.size() < 2)
            return false;
        auto it_left = sorted.cbegin(), it_right = prev(sorted.cend());
        while (it_left != it_right) {
            auto sum = *it_left + *it_right;
            if (sum == value)
                return true;
            if (sum < value)
                ++it_left;
            else
                --it_right;
        }
        return false;
    }
private:
    multiset<int> sorted;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
