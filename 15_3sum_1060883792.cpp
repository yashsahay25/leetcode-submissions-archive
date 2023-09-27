class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            //remove duplicates:
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            
            int j=i+1,k=n-1;
            int target = -nums[i];
            
            while(j<k){
                int sum = nums[j]+nums[k];
                if(sum < target)
                    j++;
                else if(sum > target)
                    k--;
                else if (sum == target){
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;

                    //skip the duplicates:
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return res;
    }
};