class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int count = 0;
        int n = nums.size();
        vector<int> transform = nums; // can replace nums in-place also

        // we transform the array into +1/-1 (matching, non-matching)
        for(int i=0;i<n;i++){
            if(nums[i] == target) transform[i]=1;
            else transform[i]=-1;
        }

        // prefixSum array (analogus of leadVote +/-)
        vector<int> prefixSum(n,0);
        prefixSum[0] = transform[0];
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + transform[i];
        }

        // now calc majority candidate/element for each subarray
        for (int i = 0; i < n; i++) {
            for (int j = i; j < nums.size(); j++) {
                int leadVotes = prefixSum[j]-(i>0 ? prefixSum[i-1]: 0);
                if (leadVotes > 0)
                    count++;
            }
        }
        return count;
    }
};