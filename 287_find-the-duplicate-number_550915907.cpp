class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //marking visited value (multiply be -1)
        //if duplicate exists, value will become +ve again
        for(int i = 0; i < nums.size(); i++) 
        {
            int index = abs(nums[i]) - 1;
            
            // mark as visited
            nums[index] *= -1;
            // incase of duplicate, this will become +ve 
            if(nums[index] > 0)
                return abs(nums[i]);
        }    
        return -1;
    }
};