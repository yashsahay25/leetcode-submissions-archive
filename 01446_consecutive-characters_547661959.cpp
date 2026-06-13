class Solution {
public:
    int maxPower(string s) {
        //ans will store the final ans and now will store the current answer
        int ans = 1, now = 1;
        
        for(int i = 0;i<s.length()-1;i++)
        {
            //if the current char is the same as the next char then increase now
            if(s[i]==s[i+1])
            {
                now++;
                ans = max(ans,now);
            }
            else
            {
                //if the 2 consecutive characters are not same then update ans
                //ans = max(ans,now);
                //assign 1 to now to store the count for the next consecutive chars
                now = 1;            
            }
        }
        //return ans as the final answer
        return ans;  
    }
};

