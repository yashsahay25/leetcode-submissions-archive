class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum=0,overall_sum=INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            curr_sum = max(curr_sum + nums[i], nums[i]); 
            overall_sum = max(curr_sum, overall_sum);
        }
        return overall_sum;  
    }
};