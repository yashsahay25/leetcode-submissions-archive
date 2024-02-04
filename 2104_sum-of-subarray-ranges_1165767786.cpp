class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMin(n, -1), rightMin(n, n);
        vector<int> leftMax(n, -1), rightMax(n, n);
        stack<int> st;

        // NSL
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            if (!st.empty())
                leftMin[i] = st.top();
            st.push(i);
        }
        // clear stack for reuse
        while (!st.empty())
            st.pop();

        // NSR
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            if (!st.empty())
                rightMin[i] = st.top();
            st.push(i);
        }

        // clear stack for reuse
        while (!st.empty())
            st.pop();

        // NGL
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            if (!st.empty())
                leftMax[i] = st.top();
            st.push(i);
        }
        // clear stack for reuse
        while (!st.empty())
            st.pop();

        // NGR
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            if (!st.empty())
                rightMax[i] = st.top();
            st.push(i);
        }
        // main logic
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long f = (rightMax[i] - i) * (i - leftMax[i]) -
                          (rightMin[i] - i) * (i - leftMin[i]);
            sum += nums[i] * f;
        }
        return sum;
    }
};