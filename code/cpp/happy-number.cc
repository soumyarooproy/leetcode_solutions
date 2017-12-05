// 3 ms, 09/04/2017
// O(??) time, O(??) space
class Solution {
public:
    bool isHappy(int n)
    {
        if (!visited.insert(n).second)
            return false;
        int new_n = 0;
        while (n) {
            int digit = n % 10;
            new_n += digit * digit;
            n /= 10;
        }
        return new_n == 1 ? true : isHappy(new_n);
    }
private:
    unordered_set<int> visited;
};
/*-------------------------------------------------------*/
// TODO: Better solution (O(1) space) on leetcode
int digitsquaresum(int n){
    int sum=0, tmp;
    while(n){
        tmp=n%10;
        sum+=tmp*tmp;
        n/=10;
    }
    return sum;
}
bool isHappy(int n) {
    int slow, fast;
    slow=fast=n;
    do{
        slow=digitsquaresum(slow);
        fast=digitsquaresum(fast);
        fast=digitsquaresum(fast);
    }while(slow!=fast);
    if(slow==1) return 1;
    else return 0;
}
