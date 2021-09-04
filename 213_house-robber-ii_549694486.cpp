class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)    return nums[0];
        int n = nums.size(), pre1 = 0, cur1 = 0;
        //for range 1st to 2nd last (as last and first are consecutive)
        for (int i = 0; i < n-1; i++) 
        {
            int temp = max(pre1 + nums[i], cur1);
            pre1 = cur1;
            cur1 = temp;
        }
        int pre2=0,cur2=0;
        for (int i = 1; i < n; i++) 
        {
            int temp = max(pre2 + nums[i], cur2);
            pre2 = cur2;
            cur2 = temp;
        }
        return max(cur1,cur2);
    }
};