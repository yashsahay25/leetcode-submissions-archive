class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastUnique=1,curr=1;
        while(curr<nums.size()){
            if(nums[curr]!=nums[curr-1]){
                nums[lastUnique]=nums[curr];
                lastUnique++;
            } 
            curr++;
        }
        return lastUnique;
    }
};