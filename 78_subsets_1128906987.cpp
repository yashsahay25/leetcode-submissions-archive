class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        // Power Set | Bit Manipulation Technique

        // total 2^n subsets
        // so we iterate from 0 to 2^n-1, & then iterate on the array
        
        for(int i=0;i<(1<<n);i++){
            vector<int> v; // temp vector 
            for(int j=0;j<n;j++){
                if(i & (1<<j)) // check if the ith bit is set or not
                    v.push_back(nums[j]); // push only if the bit is set
            }
            result.push_back(v);
        }
        return result;
    }
};