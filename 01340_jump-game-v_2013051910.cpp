class Solution {
public:
    int solve(int i, vector<int>& arr, int d, vector<int>& dp) {
        if(dp[i]!=-1) return dp[i];
        
        int n = arr.size();
        int count = 1;

        // left
        for (int j = i - 1; j >= max(0, i - d); j--) {
            if (arr[j] >= arr[i])
                break;
            count = max(count, 1 + solve(j, arr, d, dp));
        }

        // right
        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
            if (arr[j] >= arr[i])
                break;
            count = max(count, 1 + solve(j, arr, d, dp));
        }

        return dp[i] = count;
    }
    int maxJumps(vector<int>& arr, int d) {
        int ans = 1;

        int n=arr.size();
        vector<int> dp(n,-1);
        for (int i = 0; i < arr.size(); i++) {
            ans = max(ans, solve(i, arr, d, dp));
        }
        return ans;
    }
};