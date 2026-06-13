class Solution {
public:
    int searchOccurance(vector<int>& nums, int k, bool checkFirst) {
        int lo = 0, hi = nums.size() - 1;
        int ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (k == nums[mid]) {
                ans = mid;
                if (checkFirst)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            } else if (k < nums[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = searchOccurance(nums, target, true);
        if (first == -1)
            return {-1, -1};
        int last = searchOccurance(nums, target, false);
        return {first, last};
    }
};