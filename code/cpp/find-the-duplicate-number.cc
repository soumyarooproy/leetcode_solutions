// 12 ms, 09/28/2017
// Time  : O(n)
// Space : O(1)
// TODO  : Solve it in O(n lg n) time; see below
class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow = nums[0], fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
/*--------------------------------------------------*/
// O(n lg n)
int findDuplicate(vector<int>& nums)
{
    int n=nums.size()-1;
    int low=1;
    int high=n;
    int mid;
    while(low<high){
        mid=(low+high)/2;
        int count=0;
        for(int num:nums){
            if(num<=mid) count++;
        }
        if(count>mid) high=mid;
        else low=mid+1; 
    }
    return low;
}
