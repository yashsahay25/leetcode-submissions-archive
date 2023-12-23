class Solution {
public:
    bool isPowerOfFour(int n) {
        // 4^x-1 (ie. n^x-1) is always a multiple of 3

        // return n > 0 && (n & (n-1)) == 0 && (n & 0x55555555) != 0;
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};