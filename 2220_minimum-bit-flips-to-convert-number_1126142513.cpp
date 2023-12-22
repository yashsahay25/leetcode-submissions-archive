class Solution {
public:
    int minBitFlips(int start, int goal) {
        // number of bits to flip is equal to
        // number of set bits in start^goal
        int n = start^goal;
        int count=0;
        while(n){
            n = n & (n-1); // turn off the rightmost set bit
            count++; // run loop till n becomes 0
        }
        return count;
    }
};