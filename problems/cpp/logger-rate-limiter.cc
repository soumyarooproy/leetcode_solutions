// 73 ms, 09/14/2017
// Time  : O(m), number of messages with the same timestamp
// Space : O(n), number of unique messages in a 10-second window
class Logger {
public:
    /** Initialize your data structure here. */
    Logger() { }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message)
    {
        while (!q.empty() && q.front().timestamp <= timestamp - 10) {
            msg_window.erase(q.front().message);
            q.pop();
        }
        bool should_print;
        if (should_print = msg_window.insert(message).second)
            q.push({timestamp, message});
        return should_print;
    }
private:
    struct q_entry { int timestamp; string message; };
    queue<q_entry> q;
    unordered_set<string> msg_window;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
