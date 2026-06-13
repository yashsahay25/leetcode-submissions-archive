class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem, count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                elem = nums[i];
                count = 1;
            }
            else if(nums[i]==elem) count++;
            else count--;
        }
        int elemCount=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]==elem)
                elemCount++;

        if(elemCount > (nums.size()/2))   return elem;
        return -1;
    }
};