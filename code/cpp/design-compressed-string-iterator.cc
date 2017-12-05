// 12 ms, 09/03/2017
// TODO: Clean up the code
class StringIterator {
private:
    void advance() {
        _c_cached = _c_idx < _str.size() ? _str[_c_idx] : ' ';
        int i = _c_idx + 1; 
        for ( ; i < _str.size() && isdigit(_str[i]); ++i);
        _c_rem = stoi(_str.substr(_c_idx + 1, i - _c_idx));
        _c_idx = i;
    }

public:
    StringIterator(string comp_str) : _str(comp_str), _c_idx(0), _c_rem(0)
    {
        advance();
    }
    
    char next()
    {
        if (!hasNext())
            return ' ';
        if (!_c_rem--) {
            advance();
            --_c_rem;
        }
        return _c_cached;
    }
    
    bool hasNext()
    {
        return _c_rem || _c_idx < _str.size();
    }
    
private:    
    char _c_cached;
    int _c_idx, _c_rem;
    string _str;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
