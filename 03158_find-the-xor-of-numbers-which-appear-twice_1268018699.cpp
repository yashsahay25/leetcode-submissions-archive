class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (int num : nums)
            ans ^= num;
        for (int x : st)
            ans ^= x;
        return ans;
    }
};