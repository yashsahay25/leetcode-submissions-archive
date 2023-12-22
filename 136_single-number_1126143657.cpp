class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorSum = 0;
        /* If every element would have occured twice, 
            they will cancel out each other, hence answer will be zero
            But, here one element occurs only once, 
            which will be left after full xor
        */
        for(int i:nums){
            xorSum = xorSum^i;
        }
        return xorSum;
    }
};