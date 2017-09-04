bool isValid(string s)
{
    stack<char> brackets;
    for (auto c : s) {
        if (c == '(' | c == '{' | c == '[')
            brackets.push(c);
        else if (c == ')' && !brackets.empty() && brackets.top() == '('
                || c == '}' && !brackets.empty() && brackets.top() == '{'
                || c == ']' && !brackets.empty() && brackets.top() == '[')
            brackets.pop();
        else
            return false;
    }
    return brackets.empty();
}
