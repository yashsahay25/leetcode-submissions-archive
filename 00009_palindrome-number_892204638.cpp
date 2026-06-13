class Solution {
public:
    bool isPalindrome(int x)
    {
        if(x==0) return true;
        else if(x<0 || x%10==0) return false;
        int num=x,rev=0;
        while(x>rev){
            int d=x%10;
            rev=rev*10+d;
            x=x/10;
        }
        // if(x==rev || x==rev/10) return true;
        // return false;
        return (x==rev || x==rev/10);
    }
};