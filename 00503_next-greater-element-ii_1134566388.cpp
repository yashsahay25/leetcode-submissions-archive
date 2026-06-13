class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s;
        // For circular array, next of last element is 1st element
        // or simply, we can place the whole array at the back again
        // In code, we can assume arry of double length (2*n)
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i % n]) //i%n for cyclic
                s.pop();
            if (i < n && !s.empty()) {
                res[i] = s.top();
            }
            s.push(nums[i % n]);
        }
        return res;
    }
};