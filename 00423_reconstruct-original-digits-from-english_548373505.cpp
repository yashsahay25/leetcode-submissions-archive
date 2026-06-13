class Solution {
public:
    string originalDigits(string s) {
        vector<int> mp(26, 0), nums(10, 0);
        
        for (char c:s) 
            mp[c-'a']++;
        nums[0] = mp['z'-'a'];
        nums[2] = mp['w'-'a'];
        nums[4] = mp['u'-'a'];
        nums[1] = mp['o'-'a']-nums[0]-nums[2]-nums[4];
        nums[3] = mp['r'-'a']-nums[0]-nums[4];
        nums[6] = mp['x'-'a'];
        nums[7] = mp['s'-'a']-nums[6];
        nums[8] = mp['g'-'a'];
        nums[5] = mp['v'-'a']-nums[7];
        nums[9] = mp['i'-'a']-nums[5]-nums[6]-nums[8];
        
        string ans;
        //for ascending order
        for (int i = 0; i < 10; i++) {
            ans += string(nums[i],'0'+i);
        }
        //for descending order
        //for (int i = 9; i >= 0; i--)
            //ans += string(nums[i],'0'+i);
        return ans;
    }
};