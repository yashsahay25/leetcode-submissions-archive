class Solution {
public:
    int numberOfSpecialChars(string word) {
        // since each word contains only alphabets,
        // we can store them as bitmask in 32 bit integer
        
        int lowerMask = 0;
        int upperMask = 0;

        // formula for mask = mask | (1 << bits)
        for (char c : word) {
            if (islower(c))
                lowerMask = lowerMask | (1 << (c - 'a'));
            else
                upperMask = upperMask | (1 << (c - 'A'));
        }

        // if bit is set in both (which can be found by taking bitwise AND)
        int specialBits = lowerMask & upperMask;

        // return number of set bits
        return __builtin_popcount(specialBits);
    }
};