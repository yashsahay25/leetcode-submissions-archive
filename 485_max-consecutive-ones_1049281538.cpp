class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currCount = 0, maxCount = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                currCount++;
                if(currCount > maxCount)
                    maxCount = currCount;
            }
            else{
                currCount=0;
            }
        }
        return maxCount;
    }
};