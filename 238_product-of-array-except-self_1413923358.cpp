class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixProduct(n,1);
        vector<int> suffixProduct(n,1);

        prefixProduct[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixProduct[i]=nums[i]*prefixProduct[i-1];
        }
        suffixProduct[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffixProduct[i]=nums[i]*suffixProduct[i+1];
        }

        vector<int> ans(n);
        ans[0]=suffixProduct[1];
        ans[n-1]=prefixProduct[n-2];
        for(int i=1;i<=n-2;i++){
            ans[i]=prefixProduct[i-1]*suffixProduct[i+1];
        }
        return ans;
    }
};