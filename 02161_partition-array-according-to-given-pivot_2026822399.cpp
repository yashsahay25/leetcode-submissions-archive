class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> more, less;
        for(int num:nums){
            if(num < pivot) less.push_back(num);
            else if(num > pivot) more.push_back(num);
        }
        int lessCount = less.size();
        int moreCount = more.size();
        int equalCount = n - lessCount - moreCount;

        // nums[0...lessCount-1]
        // nums[equal]
        // nums[n-moreCount...n-1]
        int i=0,j=0;
        while(lessCount--) nums[i++] = less[j++];
        while(equalCount--){
            nums[i++] = pivot;
        }
        j=0;
        while(moreCount--) nums[i++] = more[j++];

        return nums;
    }
};