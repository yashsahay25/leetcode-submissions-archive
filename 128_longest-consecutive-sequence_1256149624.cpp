class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Sorting Method
        if(nums.size()==0) return 0;

        sort(nums.begin(),nums.end());

        int currCount=0,lastSmaller=INT_MIN,maxLen=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==lastSmaller) 
                continue;
            else if(nums[i]==lastSmaller+1){
                currCount++;
                lastSmaller=nums[i];
                maxLen=max(maxLen,currCount);    
            }
            else if(nums[i]!=lastSmaller){
                currCount=1;
                lastSmaller=nums[i];
                
            }
            
        }
        return maxLen;
    }
};