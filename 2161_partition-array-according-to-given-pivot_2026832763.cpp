class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int lessCount=0,moreCount=0;
        for(int num:nums){
            if(num < pivot) lessCount++;
            else if(num > pivot) moreCount++;
        }
        int equalCount = n - lessCount - moreCount;

        // nums[0...lessCount-1]
        // nums[leequal]
        // nums[n-moreCount...n-1]
        vector<int> res(n);
        
        int l=0,e=lessCount,m=n-moreCount;

        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                res[l]=nums[i];
                l++;
            }
            else if(nums[i]==pivot){
                res[e]=nums[i];
                e++;
            }
            else{
                res[m]=nums[i];
                m++;
            }
        }

        return res;
    }
};