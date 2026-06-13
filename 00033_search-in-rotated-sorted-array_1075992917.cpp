class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;  //start
        int hi = nums.size()-1;  //end
        
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid] == target){    //target found
                return mid;
            }
            else if(nums[mid] >= nums[lo]){  //mid greater than start
                if(nums[lo] <= target and target <= nums[mid]){  //target b/w start & mid
                    hi = mid-1;  //search in left half
                }
                else{
                    lo = mid+1;  //search in right half
                }
            }
            else{   //mid less than start
                if(nums[mid] <= target and target <= nums[hi]){  
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
            
        }
        return -1;
    }
};