class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // two pointer in-place merge algorithm
        // can be used here, since arr1 is expandable
        int i = m - 1;  // last of arr1
        int j = n - 1;  // last of arr2 
        int k = m + n - 1; // last of arr1+arr2
        
        // traverse until right array is completely traversed
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                // pick the greater element & place it
                nums1[k] = nums1[i];
                // move pointers
                k--,i--;
            } else {
                nums1[k] = nums2[j];
                k--,j--;
            }
        }
    }
};