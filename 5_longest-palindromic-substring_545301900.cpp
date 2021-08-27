class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==0)    return "";
        if(n==1)    return s;
        int maxlen=0;
        string lps;
        //odd length palindrome
        for(int i=1;i<n;i++)
        {
            int l=i-1,r=i+1;
            while(l>=0 and r<n and s[l]==s[r])
            {
                l--;r++;
            }
            l++;r--;
            if(r-l+1>maxlen)
            {
                maxlen=r-l+1;
                lps = s.substr(l,r-l+1);
            }
            //cout<<lps<<" "<<r-l+1<<" "<<maxlen<<"\n";
        }
        //even length palidrome
        for(int i=1;i<n;i++)
        {
            int l=i-1,r=i;
            while(l>=0 and r<n and s[l]==s[r])
            {
                l--;r++;
            }
            l++;r--;
            if(r-l+1>maxlen)
            {
                maxlen=r-l+1;
                lps = s.substr(l,r-l+1);
            }
            //cout<<lps<<" "<<r-l+1<<" "<<maxlen<<"\n";
        }
        return lps;
    }
};