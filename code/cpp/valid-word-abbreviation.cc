// 3ms, 09/02/2017
bool validWordAbbreviation(string word, string abbr)
{
    int word_i = 0, abbr_i = 0, word_n = word.size(), abbr_n = abbr.size();
    while (word_i < word_n && abbr_i < abbr_n) {
        if (isdigit(abbr[abbr_i])) {
            if (abbr[abbr_i] == '0')
                return false;
            auto count = 0;
            for ( ; abbr_i < abbr_n && isdigit(abbr[abbr_i]); ++count, ++abbr_i);
            word_i += stoi(abbr.substr(abbr_i - count, count));
        }
        if (word_i < word_n && abbr_i < abbr_n && word[word_i] != abbr[abbr_i])
            return false;
        ++word_i, ++abbr_i;
    }
    return word_i - word_n == abbr_i - abbr_n;
}
