class Solution {
public:
    bool checkZeroOnes(string s) {
        int len1=0,len0=0;
        int ones=0,zeros=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                ones++;
                zeros=0;   
            }
            else
            {
                zeros++;
                ones=0;
            }
            len1=max(len1,ones);
            len0=max(len0,zeros);
        }
        return len1>len0;
    }
};