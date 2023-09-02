class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            //2nd number to find
            int k=target-nums[i];

            // write found logic before insert logic
            //if found, then add to res & return res
            if(mp.find(k)!=mp.end())
            {
                res.push_back(mp[k]);
                res.push_back(i);
                return res;
            }

            //add nums[i] to map
            mp[nums[i]]=i;
        }
        return res;
        
    }
};