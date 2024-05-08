class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        
        int ans = nums[0]+nums[1]+nums[2];

        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        for(int i=0;i<n-2;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            
            int j=i+1,k=n-1;
            int diff=0;
            
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(target-sum)<abs(target-ans)){ // compare diffs
                    ans = sum;
                }

                if(sum < target) j++;
                else if(sum > target) k--;
                else if(sum==target){
                    // j++,k--; // no need directly return
                    return sum;
                }
                
            }
        }
        return ans;
    }
};