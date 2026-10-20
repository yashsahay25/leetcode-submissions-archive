class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // handles k>n cases
        k = k % nums.size();

        // reverse whole array
        reverse(nums.begin(), nums.end());

        // last k elements become first k elements, reverse them
        reverse(nums.begin(), nums.begin() + k);

        // reverse remaining to obtain final array
        reverse(nums.begin() + k, nums.end());
    }
};