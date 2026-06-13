class Solution {
public:
    bool isPowerOfFour(int n) {
        // for power of 4, number should be even power of 2 and
        // position of set bit in binary format should be odd 
        // to check 2nd condition, we take and with 0101..... or 0x55...
        return n > 0 && (n & (n-1)) == 0 && (n & 0x55555555) != 0;
    }
};