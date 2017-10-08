// 1430 ms, 10/07/2017
// Time  : O(1)
// Space : O(n)
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers)
    {
        for (int i = 0; i < maxNumbers; ++i)
            release(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get()
    {
        if (_pool.empty())
            return -1;
        auto tmp = *_pool.begin();
        _pool.erase(_pool.begin());
        _lookup.erase(tmp);
        return tmp;
    }
    
    /** Check if a number is available or not. */
    bool check(int number)
    {
        return _lookup.count(number);
    }
    
    /** Recycle or release a number. */
    void release(int number)
    {
        if (check(number))
            return;
        _pool.push_back(number), _lookup.insert(number);
    }
private:
    unordered_set<int> _lookup;
    list<int> _pool;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
