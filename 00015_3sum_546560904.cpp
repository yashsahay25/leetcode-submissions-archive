class Solution {
public:
    //solving it as triplet withk-sum problem
    int k=0;
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
        for(int i=0;i<n-2;i++)
        {
            //to ignore duplicates
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
                int lo=i+1,hi=n-1;
                int rsum = k-nums[i];

                while(lo<hi)
                {
                    if(nums[lo]+nums[hi]==rsum)
                    {
                        //vector to store this triplet
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        //add this vector to result vector
                        res.push_back(temp);
                        
                        //again check & ignore duplicates
                        while(lo<hi && nums[lo]==nums[lo+1])
                            lo++;
                        while(lo<hi && nums[hi]==nums[hi-1])
                            hi--;
                        
                        //move pointers
                        lo++; hi--;
                    }
                    else if(nums[lo]+nums[hi]>rsum)
                        hi--;
                    else
                        lo++;
                }
            }
        }
        return res;
    }
};