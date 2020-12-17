class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> a(nums.size());//a[nums.size()]={0};
        int i=0;
        for(;i<nums.size();i++)
        {
            if(!a[nums[i]])
                a[nums[i]]++;
            else
                break;
        }
        return nums[i];
    }
};