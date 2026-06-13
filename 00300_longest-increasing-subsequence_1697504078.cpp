class Solution {
public:
    int solve(int index, int prevIndex, vector<int>& arr, vector<vector<int>>& dp){
        // base case
        if(index == arr.size()) return 0;
        
        // prevIndex can start from -1 so we offset it using below
        if(dp[index][prevIndex+1]!=-1) return dp[index][prevIndex+1];

        // recurrence
        int notPick = 0 + solve(index+1, prevIndex, arr, dp);

        int pick = 0;
        if(prevIndex == -1 || arr[index] > arr[prevIndex])
            pick = 1 + solve(index+1, index, arr, dp);

        return dp[index][prevIndex+1] = max(pick, notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1,-1));
        return solve(0, -1, nums, dp);
    }
};