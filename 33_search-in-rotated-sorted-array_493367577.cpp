class Solution {
public:
 int search(vector<int>& nums, int target) {
        int s = 0;  //start
        int e = nums.size()-1;  //end
        int mid;
        
        while(s<=e){
            mid = (s+e)/2;
            if(nums[mid] == target){    //target found
                return mid;
            }
            else if(nums[mid] >= nums[s]){  //mid greater than start
                if(nums[s] <= target and target <= nums[mid]){  //target b/w start & mid
                    e = mid-1;  //search in left half
                }
                else{
                    s = mid+1;  //search in right half
                }
            }
            else{   //mid less than start
                if(nums[mid] <= target and target <= nums[e]){  
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }
            
        }
        return -1;
        
    }
};