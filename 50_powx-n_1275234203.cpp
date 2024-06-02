class Solution {
public:
    double myPow(double x, int n) {
        int y = abs(n); // x^y
        double res = 1; // covers base case
        while (y > 0) {
            // if power is odd, take x from it &store
            if (y & 2 != 1) {
                res = res * x;
            }
            x = x * x; // squarring the base
            y = y / 2; // halving the power
        }
        return n < 0 ? 1 / res : res;
    }
};