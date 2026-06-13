class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s;
        // For circular array, next of last element is 1st element
        // or simply, we can place the whole array at the back again
        // but we actually don't need to actually create that 2nd array
        // TRICK: In code, we can simply assume array of double length (2*n)

        // traverse fro right to left
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i % n]) // i%n for cyclic
                s.pop();
            if (i < n && !s.empty()) {
                res[i] = s.top();
            }
            s.push(nums[i % n]);
        }
        return res;
    }
};