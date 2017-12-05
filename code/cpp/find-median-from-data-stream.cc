class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
        _max_heap.emplace(numeric_limits<int>::min());
        _min_heap.emplace(numeric_limits<int>::max());
    }
    
    void addNum(int num)
    {
        if (_max_heap.size() > _min_heap.size()) {
            // min_heap size needs to increase by 1
            if (num >= _max_heap.top())
                _min_heap.emplace(num);
            else {
                _min_heap.emplace(_max_heap.top());
                _max_heap.pop();
                _max_heap.emplace(num);
            }
        } else {
            // max_heap size needs to increase by 1
            if (num <= _min_heap.top())
                _max_heap.emplace(num);
            else {
                _max_heap.emplace(_min_heap.top());
                _min_heap.pop();
                _min_heap.emplace(num);
            }
        }
        /*
        cout <<   "_min_heap.top() = "  << _min_heap.top();
        cout << ", _min_heap.size() = " << _min_heap.size();
        cout << "; _max_heap.top() = "  << _max_heap.top();
        cout << ", _max_heap.size() = " << _max_heap.size() << "\n";
        */
    }
    
    double findMedian()
    {
        if (_max_heap.size() > _min_heap.size()) {
            return _max_heap.top();
        }
        return static_cast<double>(_max_heap.top() + _min_heap.top()) / 2.0;
    }

private:
    priority_queue<int> _max_heap; // ceil(n/2) min elements
    priority_queue<int, vector<int>, greater<int>> _min_heap; // floor(n/2) max elements
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
