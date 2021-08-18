#define ll long long
#define mod 1000000007
class Solution {
public:
    ll dp[101][101];
    ll solve(int n,int goal,int k,int len,int uniq)
    {
        //len - size of playlist so far
        //uniq - number of unique songs used so far
        if(len==goal)   return uniq == n;
        if(dp[len][uniq]!=-1)   return dp[len][uniq];
        
        //choosing next song from already used songs under condition of 'k'
        ll ans = ( max(0,uniq-k)*solve(n,goal,k,len+1,uniq) )%mod;
        
        //choosing next song which is unused
        ans+= ( max(0,n-uniq)*solve(n,goal,k,len+1,uniq+1) )%mod;
        
        return dp[len][uniq] = ans%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,goal,k,0,0);
    }
};

/*class Solution {
public:
    const int m=1000000007;
    long helper(int n,int goal,int k,int i,int used,vector<vector<long>> &dp)
    {
        if(i==goal){
            if(used==n)return 1;
            return 0;
        }
        if(dp[i][used]!=-1)return dp[i][used];
        long ans1=0;
        if(i-k>=0)
        {
            ans1=((used-k)*helper(n,goal,k,i+1,used,dp))%m;
        }
        long ans2=0;
        if(n-used>=0){
            ans2=((n-used)*helper(n,goal,k,i+1,used+1,dp))%m;
        }
        return dp[i][used]=(ans1+ans2)%m;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long>> dp(101,vector<long>(101,-1));
        return helper(n,goal,k,0,0,dp);
    }
}*/