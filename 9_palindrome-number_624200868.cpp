class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long int num=x,rev=0;
        while(x>0)
        {
            int d=x%10;
            rev = rev*10+d;
            x=x/10;
        }
        if(num==rev)
            return true;
        return false;
    }
};