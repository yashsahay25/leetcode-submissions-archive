class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();

        // find pivot element where increasing seq from R2L breaks
        int pivot=-1;
        for(int i=n-1;i>0;i--){
            if(nums[i-1] < nums[i]) {
                pivot = i-1; // seq breaks at index i-1
                break;
            }
        }

        // if no pivot found, it means we are at last permutation
        if(pivot==-1){
            // so sort nums & return
            sort(nums.begin(),nums.end());
            return;
        }

        // find next greater element of pivot
        // make use of increasing nature property of that half
        int j=n-1;
        for(;j>=pivot;j--){
            if(nums[j]>nums[pivot]){
                break;
            }
        }

        // swap NGR and pivot values
        swap(nums[j],nums[pivot]);

        // reverse the second half
        reverse(nums.begin()+pivot+1,nums.end());

        // return;
    }
};