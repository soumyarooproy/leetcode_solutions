// 32 ms, 09/13/2017
// Time  : O(1)
// Space : O(n)
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : _window(size) {}
    
    double next(int val)
    {
        _window.insert(val);
        return _window.avg();
    }
private:
    struct moving_window {
        moving_window(int size) : _max_size(size), _sum(0) {}
        void insert(int val) {
            _sum += val;
            _window.push(val);
            if (_window.size() > _max_size) {
                _sum -= _window.front();
                _window.pop();
            }
        }
        double avg() {
            return _sum / _window.size();
        }
        queue<int> _window;
        int _max_size;
        double _sum;
    };
    moving_window _window;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
