class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // Brute force - Linear search

        // Binary Search approach
        // find index of firstZero & firstPos, using lower bound
        // res = max(firstZero,n-firstPos)

        // if Zero doesn't exist, it will return index of next nearest +ve ie. 1
        // if One doesn't exist, it will return index of next nearest +ve
        // so this way, it will cover all cases

        int n=nums.size();
        int firstPos = lower_bound(nums.begin(),nums.end(),1)-nums.begin();
        int firstZero = lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        
        return max(firstZero,n-firstPos);
    }
};