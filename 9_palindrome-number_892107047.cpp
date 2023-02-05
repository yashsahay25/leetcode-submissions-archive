class Solution {
public:
    bool isPalindrome(int x)
    {
        if(x<0 || (x!=0 && x%10==0))    return false;
        //reverse till half & check, no need of long
        int rev=0;
        while(x>rev)
        {
            int d=x%10;
            rev = rev*10+d;
            x=x/10;
        }
        //incase of even-odd length
        return (x==rev) || (x==rev/10);
    }
};