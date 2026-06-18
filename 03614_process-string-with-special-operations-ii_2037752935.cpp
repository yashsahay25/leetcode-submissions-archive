class Solution {
public:
    char processStr(string s, long long k) {
        /*
        since the constraints are large, we cannot
        form the result string in memory.
        Instead we track the length of the string to be formed,
        and then reverse engineer the solution
        */
        // string res = "";
        long long len=0;

        // calc length, but not the actual string
        for (char& c : s) {
            if (c >= 'a' && c <= 'z')
                len++;
            else if (c == '*' && len>0)
                len--;
            else if (c == '#')
                len += len;
            else if (c == '%')
                continue;
        }

        if(k>=len) return '.';

        // now revere engineer
        long long n=s.length();
        for(long long i=n-1;i>=0;i--){
            char c = s[i];
            if (c >= 'a' && c <= 'z' && len>0)
                len--; // no change in k
            else if (c == '*')
                len++; // no change in k
            else if (c == '#'){
                // length halved, so accordingly shift k
                len = len/2;
                k = k>=len ? k-len : k;
            }
            else if (c == '%')
                k = len-k-1; // k changed, no change in len
            
            // when k chars remain, return answer
            if(k==len) return s[i];
        }
        return '.';
    }
};