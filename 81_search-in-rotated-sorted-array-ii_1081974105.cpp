class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0;  //start
        int hi = nums.size()-1;  //end
        
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid] == target){    //target found
                return true;
            }
            // edge case, where all pointers are same
            // so we shrink the array, by moving lo & hi ahead
            else if(nums[lo]==nums[mid] && nums[mid]==nums[hi]){
                lo++;
                hi--;
                continue; // continue this case is removed (array can shrink no further in this iteration of the loop)
            }
            else if(nums[lo] <= nums[mid]){  //left half is sorted
                if(nums[lo] <= target and target <= nums[mid]){  
                    //target b/w start & mid
                    hi = mid-1;  //search in that left half
                }
                else{
                    lo = mid+1;  //search in the right half
                }
            }
            else{   //right is sorted
                if(nums[mid] <= target and target <= nums[hi]){
                    // target b/w mid & end  
                    lo = mid+1; // search in right half
                }
                else{
                    hi = mid-1; // search in left half
                }
            }  
        }
        return false;
    }
};