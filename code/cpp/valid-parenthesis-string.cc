// 3ms, 09/26/2017
// Time  : O(n)
// Space : O(n)
// TODO  : Better solution below
class Solution {
private:
    struct stack_entry { char c; bool has_left; };
public:
    bool checkValidString(string s)
    {
        stack<stack_entry> st;
        
        for (auto c : s) {
            if (c == ')') {
                if (st.empty())
                    return false;
                if (st.top().has_left) {
                    // pop all the '*' till '(' is found
                    int count = 0;
                    for ( ; st.top().c != '('; ++count, st.pop());
                    // pop the '('
                    st.pop();
                    while (count--) st.push({'*', st.empty() ? false : st.top().has_left});
                } else {
                    st.pop();
                }
            } else { // c == '*' || c == '('
                // if '(', set has_left to true
                // if '*', propagate has_left
                st.push({c, c == '(' ? true : st.empty() ? false : st.top().has_left});
            }
        }
        for (int count = 0; !st.empty(); st.pop()) {
            auto e = st.top();
            count += e.c == '*' ? 1 : -1;
            if (count < 0)
                return false;
        }
        
        return true;
    }
};
/*----------------------------------------------------------*/
// Better solution on leetcode - O(1) space
class Solution {
public:
    bool checkValidString(string s) {
        int lower = 0, upper = 0;
        for (char c : s) {
            if (c=='(') {
                lower++;
                upper++;
            } else if (c==')') {
                lower--;               
                upper--;
            } else { // * encountered
                lower--;
                upper++;
            }
            lower = max(lower, 0);
            if (upper<0) // unmatched ')' found in the middle of string
                return false;
        }
        return lower==0;
    }
};
