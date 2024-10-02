class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // prefix_sum, freq
        int count = 0, sum = 0;

        // case when prefix_sum == k ie. subarray start from index 0
        // and has count == 1
        mp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // if (sum-k) seen before, it means subarray with sum k
            // must have occured before, add its freq to count
            if (mp.find(sum - k) != mp.end())
                count += mp[sum - k];

            // store/increment prefix_sum, freq in map
            mp[sum]++;
        }
        return count;
    }
};