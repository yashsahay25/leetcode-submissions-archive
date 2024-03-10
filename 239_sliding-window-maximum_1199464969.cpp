class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        int i = 0, j = 0;
        deque<int> dq; // store index

        while (j < n) {
            // do calculations for j
            // empty deque
            if (dq.empty())
                dq.push_back(j);
            else {
                // incoming is larger, then check it
                while (!dq.empty() && nums[j] > nums[dq.back()])
                    dq.pop_back();
                // else push at back
                dq.push_back(j);
            }
            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k) {
                // calc final ans
                res.push_back(nums[dq.front()]);
                // now slide the window
                // outgoing is current max
                if (i == dq.front())
                    dq.pop_front();
                // outgoing is not current max
                i++, j++;
            }
        }
        return res;
    }
};