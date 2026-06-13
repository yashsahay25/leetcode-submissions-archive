class Solution {
public:
    int solve(int index, int k, vector<int>& arr, vector<int>& dp) {
        int n = arr.size();

        // base case
        if (index == n) return 0;

        if (dp[index] != -1)    return dp[index];

        int len = 0;                 // length to track current subarray
        int maxOfSubarray = INT_MIN; // max num in that subarray
        int subarraySum = 0;         // sum of that subarray
        int maxSum = 0;              // overall max sum across all partitions

        // we can form atmost k length partition,
        // so j will be from index to (index+k)

        // min(n, index+k) is the safety check for index out of bounds
        for (int j = index; j < min(n, index + k); j++) {
            len++;
            maxOfSubarray = max(arr[j], maxOfSubarray);
            // arr[j] = maxNum;
            // we don't actually need to replace values, just max*subarray_len
            subarraySum = len * maxOfSubarray + solve(j + 1, k, arr, dp);
            maxSum = max(maxSum, subarraySum);
        }
        return dp[index] = maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // arr[i...i+k/ i+k+1....j]
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, k, arr, dp);
    }
};