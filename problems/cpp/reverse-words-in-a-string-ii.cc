// Problem description URL:
//   https://leetcode.com/problems/reverse-words-in-a-string-ii

// 6 ms, 08/29/2017
void reverseWords(string &s)
{
    reverse(s.begin(), s.end());

    for (auto it = s.begin(), end = s.end(); it < end; ) {
        auto space_it = find(it, end, ' ');
        reverse(it, space_it);
        it = space_it + 1;
    }
}
