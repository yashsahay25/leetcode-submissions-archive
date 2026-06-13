class Solution {
public:
    double myPow(double x, int n) {
        // brute approach
        // multiply x 'n' times using a for loop

        // binary exponentiation method
        // recursive
        double res = 1;
        while (n) {
            if (n % 2) res = n > 0 ? res * x : res / x;
            x = x * x;
            n /= 2;
        }
        return res;
    }
};

