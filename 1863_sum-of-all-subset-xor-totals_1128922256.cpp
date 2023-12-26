class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int xorSum = 0;
        for(int i=0;i<(1<<n);i++){
            int tempXor = 0; // to store Xor of subset in each iteration 
            for(int j=0;j<n;j++){
                if(i & (1<<j)) // check if the ith bit is set or not
                    tempXor = nums[j]^tempXor; // take xor only if the bit is set
            }
            xorSum += tempXor;
        }
        return xorSum;
    }
};