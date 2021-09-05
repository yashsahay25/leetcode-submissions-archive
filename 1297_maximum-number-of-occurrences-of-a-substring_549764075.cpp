class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n=s.size();
        int i=0,j=0,res=0;
        unordered_map<char,int> mp; //freq of chars in window
        unordered_map<string,int> strmap; //freq ofsubstring occurances
        while(j<n)
        {
            mp[s[j]]++;
            //if(j-i+1<minSize)   j++; covered at end
            if(j-i+1>minSize)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
            if(j-i+1==minSize and mp.size()<=maxLetters)
            {
                string sub = s.substr(i,j-i+1);
                strmap[sub]++;
                //res = max(res,strmap[sub]);
            }
            j++;
        }
        for(auto it:strmap)
            res=max(res,it.second);
        return res;
    }
};