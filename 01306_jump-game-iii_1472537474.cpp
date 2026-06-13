class Solution {
public:
    bool canReach(vector<int>& arr, int cur) {
        // If index is out of bounds or already visited, return false
        if (cur < 0 || cur >= arr.size() || arr[cur] < 0)
            return false;

        // If current value is 0, we have reached the target
        if (arr[cur] == 0)
            return true;

        // Mark as visited (make it -ve)
        // operation i+arr[i] becomes i-arr[i] & vice-versa, so no effect
        arr[cur] = -arr[cur];

        // Explore both possible jumps (left and right)
        return canReach(arr, cur + arr[cur]) || canReach(arr, cur - arr[cur]);
    }
};
