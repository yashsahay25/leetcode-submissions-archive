class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // find the largest subarray with sum k = arr_sum-x;
        int arr_sum = 0;
        for (int x : nums)
            arr_sum += x;

        if (x > arr_sum)
            return -1; // no valid subarray exists

        int k = arr_sum - x; // target sum for subarray
        if (k == 0)
            return nums.size(); // whole arr_sum == x or k==0

        unordered_map<int, int> mp;
        mp[0] = -1; // when prefix sum starts from first index

        int sum = 0, maxLen = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (mp.find(sum - k) != mp.end()) {
                int len = i - mp[sum - k];
                maxLen = max(maxLen, len);
            }

            if (mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        return maxLen == INT_MIN ? -1 : nums.size() - maxLen;
    }
};