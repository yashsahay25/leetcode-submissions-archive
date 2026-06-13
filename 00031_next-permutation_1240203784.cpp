class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // traverse from right to find breakpoint
        int i=n-1;
        for(;i>0;i--){
            if(nums[i-1]<nums[i])
                break;
        }
        // i-1 will be breakpoint

        // handle edge case [last permutation]
        if(i==0){
            reverse(nums.begin(),nums.end());
            return;
        }

        // instead of finding next greater element L-R
        // traverse R-L (make use of increasing sequence in the array)
        int j=n-1;
        for(;j>=i;j--){
            if(nums[j]>nums[i-1])
                break;
        }
        // j will next greater element, swap it
        swap(nums[i-1],nums[j]);

        // reverse the remaining array
        reverse(nums.begin()+i,nums.end());
    }
};