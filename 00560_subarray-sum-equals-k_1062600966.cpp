class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // map to store (prefixSum,count of prefixSum)
        unordered_map<int,int> mp;
        // for empty subarray, prefixSum = 0 & count=1
        mp[0]=1;

        int prefixSum=0,count=0;
        
        for(int i=0;i<nums.size();i++){
            prefixSum += nums[i];

            // add how many times (prefixSum-k) occurs, in the count
            count += mp[prefixSum-k];
            
            // increase current prefixSum count
            mp[prefixSum]+=1;
        }
        return count;
    }
};