class Solution {
public:
    int calcSum(vector<int>& nums, int threshold, int divisor) {
        int sum = 0;

        for (int x : nums) {
            sum += (x + divisor - 1) / divisor; // optimised ceil
            if (sum > threshold)
                return sum; // avoid overflow
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = *max_element(nums.begin(), nums.end());

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int sum = calcSum(nums, threshold, mid);
            if (sum <= threshold)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        // no need to store answer, directly return lo at the end
        return lo;
    }
};