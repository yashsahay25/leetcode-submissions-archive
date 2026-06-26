class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // freq > n/2
        int n = nums.size();
        int leader = nums[0];
        int voteLead = 1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]==leader){
                voteLead++;
                if(voteLead > n/2) break;
            } 
            else{
                voteLead--;
                if(voteLead == 0){
                    leader = nums[i];
                    voteLead=1;
                }
            }
        }
        return leader;  
    }
};