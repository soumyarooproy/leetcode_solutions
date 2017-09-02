// 3ms, 09/02/2017
int lengthOfLastWord(string s)
{
    int i = s.size();
    while (--i >= 0 && s[i] == ' ');
    int j = i;
    while (j >= 0 && s[j] != ' ') j--;
    return i - j;
}
