class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return false; // get rid of corner cases 
        if(n == 1) return true; // base case
        
        //pointers for 2, 3, 5
        //next ugly number will be minimum of prev*2,prev*3,prev*5
        //to not consider prev again, we move forward that number's pointer
        int t2 = 0, t3 = 0, t5 = 0; 
        int dp[n];
        dp[0] = 1;
        for(int i  = 1; i < n ; i ++)
        {
            dp[i] = min(dp[t2]*2,min(dp[t3]*3,dp[t5]*5));
            //now we check whose multiple is the current number, & forward its pointer
            if(dp[i] == dp[t2]*2) t2++; 
            if(dp[i] == dp[t3]*3) t3++;
            if(dp[i] == dp[t5]*5) t5++;
        }
        return dp[n-1];
    }
};