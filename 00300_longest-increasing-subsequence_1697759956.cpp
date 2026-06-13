class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // intuitive dp approach
        int n=nums.size();
        vector<int> lis(n,1);
        int maxLen=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i] > nums[prev]){
                    lis[i] = max(lis[i], 1 + lis[prev]);
                }
            }
            maxLen = max(maxLen, lis[i]);
        }
        return maxLen;
    }
};