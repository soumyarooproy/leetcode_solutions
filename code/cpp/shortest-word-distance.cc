// 12 ms, 09/04/2017
int shortestDistance(vector<string>& words, string word1, string word2)
{
    int n = words.size(), min_dist = n, i1 = n, i2 = n;
    for (int i = 0; i < n; ++i) {
        if (words[i] == word1 || words[i] == word2) {
            if (words[i] == word1)
                i1 = i;
            else
                i2 = i;
            min_dist = min(min_dist, abs(i1 - i2));
        }
    }
    return min_dist;
}
