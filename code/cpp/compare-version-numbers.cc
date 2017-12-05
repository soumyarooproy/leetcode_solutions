// 0 ms, 09/26/2017
// Time  : O(min(n1, n2)) 
// Space : O(min(m1, m2)), number of '.'
// TODO  : Iterative solution
class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        return compare_version(version1.cbegin(), version1.cend(), version2.cbegin(), version2.cend());
    }
private:
    typedef string::const_iterator stri;
    int compare_version(stri it1, stri end1, stri it2, stri end2)
    {
        if (it1 >= end1 && it2 >= end2)
            return 0;
        auto it_next1 = find(it1, end1, '.'), it_next2 = find(it2, end2, '.');
        int num1 = it_next1 > it1 ? stoi(string(it1, it_next1)) : 0;
        int num2 = it_next2 > it2 ? stoi(string(it2, it_next2)) : 0;
        if (num1 > num2)
            return 1;
        if (num1 < num2)
            return -1;
        return compare_version(it_next1 + 1, end1, it_next2 + 1, end2);
    }
};
