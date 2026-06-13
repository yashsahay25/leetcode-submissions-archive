class Solution {
public:
    bool canSplitArray(vector<int>& arr, int k, int sum) {
        int count = 1;       // start with 1st student
        int subarraySum = 0; // initially, 0

        for (int i = 0; i < arr.size(); i++) {
            // if within limit, we include this element in subarray
            if (subarraySum + arr[i] <= sum) {
                subarraySum += arr[i];
            } else { // move to next subarray & assign it fresh
                count++;
                if (count > k)
                    return false;
                subarraySum = arr[i];
            }
        }
        return true; // array split possible
    }
    int splitArray(vector<int>& nums, int k) {
        // exact same problem as book allocation
        // see GFG sumbitted solution

        if (k > nums.size())
            return -1;

        // ans lies in range [arr_max, arr_sum]
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);

        int ans = hi;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canSplitArray(nums, k, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};