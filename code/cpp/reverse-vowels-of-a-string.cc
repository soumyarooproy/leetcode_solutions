// 9 ms, 09/04/2017
bool is_vowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string reverseVowels(string s)
{
    for (int i_left = 0, i_right = s.size() - 1; i_left < i_right; ) {
        if (is_vowel(s[i_left]) && is_vowel(s[i_right]))
            swap(s[i_left++], s[i_right--]);
        else {
            if (!is_vowel(s[i_left]))
                ++i_left;
            if (!is_vowel(s[i_right]))
                --i_right;
        }
    }
    return s;
}
/*------------------------------------------------------------------------*/
// TODO: Skip consonants within the for-loop so that for-loop runs as many times swaps needed
// TODO: Speed up by replacing is_vowel() function with a map lookup
