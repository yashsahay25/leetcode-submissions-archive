class Solution {
public:
    int reverse(int x) {
        int rev = 0; //output value - reverse
        while (x != 0) {
            int d = x % 10; // take last digit & store it
            x /= 10;    // remove last digit

            // logic
            /*
                if rev become greater than INT_MAX/10, then it will overflow
                else if rev is equal to INT_MAX but it's last digit is greater than the last digit of INT_MAX (7 in this case), then also it will overflow
            */
            
            // similary, for negative values

            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && d > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && d < -8)) return 0;
            rev = rev * 10 + d;
        }
        return rev;   
    };
};