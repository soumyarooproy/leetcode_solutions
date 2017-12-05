// 0 ms, 09/16/2017
// Time  : O(1) for push(), peek(), and empty(), O(1) amortized and O(n) worst case for push()
// Space : O(n) (for push())
// TODO  : Review solution using one stack
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() { }
    
    /** Push element x to the back of queue. */
    void push(int x)
    {
        if (s.empty())
            oldest = x;
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (s_rev.empty())
            while (!s.empty())
                s_rev.push(s.top()), s.pop();
        int ret = peek();
        s_rev.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek()
    {
        if (s_rev.empty())
            return oldest;
        return s_rev.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s.empty() && s_rev.empty();
    }
private:
    stack<int> s, s_rev;
    int oldest;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
