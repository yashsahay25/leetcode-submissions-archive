class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        
        // We use lo < hi (instead of lo <= hi) because we are shrinking 
        // the search space to pinpoint a single element. When the loop ends,
        // lo and hi will converge exactly on the minimum element.
        while (lo < hi) {
            // Prevent integer overflow that can happen with (lo + hi) / 2
            int mid = lo + (hi - lo) / 2;
            
            // CASE 1: The right half is strictly sorted.
            // If the middle element is smaller than the far right element,
            // the minimum MUST be in the left half, or it is the mid element itself.
            // Therefore, we shrink the right boundary to 'mid'.
            if (nums[mid] < nums[hi]) {
                hi = mid;
            } 
            
            // CASE 2: The rotation drop is in the right half.
            // If the middle element is strictly greater than the far right element,
            // we know for a fact the array "dropped" somewhere to the right of mid.
            // Therefore, the minimum is strictly to the right of mid.
            else if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } 
            
            // CASE 3: The Duplicate Trap (nums[mid] == nums[hi])
            // We don't know if the minimum is to the left or right because the array
            // could look like [1, 0, 1, 1, 1] or [1, 1, 1, 0, 1].
            // However, because nums[mid] equals nums[hi], we know nums[hi] is redundant.
            // We can safely discard the far right element to shrink the search space by 1.
            else {
                hi--;
            }
        }
        
        // At the end of the loop, lo == hi, pointing to the minimum element.
        return nums[lo];
    }
};