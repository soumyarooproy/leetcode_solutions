// 0 ms, 09/16/2017
// Time  : O(1) for pop(), top(), and empty(); O(n) for push()
// Space : O(n)
// TODO  : Try O(1) for push() (and O(n) for pop()?)
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() { }
    
    /** Push element x onto stack. */
    void push(int x)
    {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; ++i, q.push(q.front()), q.pop());
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = q.front();
        q.pop();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
