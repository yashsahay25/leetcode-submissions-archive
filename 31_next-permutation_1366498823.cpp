class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2,j;
        while(i>=0){
            if(nums[i]<nums[i+1])
                break;
            i--;
        }
        // edge case : last case
        if(i<0){
            sort(nums.begin(),nums.end());
            return;
        }
        for(j=nums.size()-1;j>i;j--){
            if(nums[j]>nums[i])
                break;
        }
        swap(nums[i],nums[j]);

        reverse(nums.begin()+i+1,nums.end());
    }
};