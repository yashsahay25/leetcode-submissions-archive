class Solution {
public:
    int findPairs(vector<int>& nums, int k) {        
        
        unordered_map<int,int> mp;  //freq map
        for(auto n:nums)    mp[n]++;   //store freq
        
        int count=0;
        for(auto it:mp) //traverse map, not the array to cover only distinct elements
        {
            //(p,p) being considered a pair, so freq should be >2
            if(k==0 and it.second>1) 
                count++;
            //otherwise find element = x+k in map
            else if(k>0 and mp.find(it.first+k)!=mp.end())
                count++;
        }
        return count;
    }
};