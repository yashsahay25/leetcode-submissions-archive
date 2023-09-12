class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // based on observation
        int n = nums.size();

        // handles k>n cases
        k = k%n;

        // reverse whole array
        reverse(nums.begin(), nums.end());

        // last k elements become first k elements, reverse them
        reverse(nums.begin(), nums.begin()+k);

        // reverse remaining to obtain final array
        reverse(nums.begin()+k, nums.end());
    }
};