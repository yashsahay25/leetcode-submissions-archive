class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorSum = 0;
        /* If every element would have occured twice, 
            xor of whole array will be zero
            But, here one element occurs only once, 
            which will be left after full xor
        */
        for(int i=0;i<nums.size();i++){
            xorSum = xorSum^nums[i];
        }
        return xorSum;
    }
};