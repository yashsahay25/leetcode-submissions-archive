class Solution
{
    public:
        vector<int> maxSlidingWindow(vector<int> &nums, int k)
        {
            vector<int> res;
            deque<int> dq;
            int n = nums.size();
            int i = 0;

            for (int j = 0; j < n; ++j)
            {
               	// Remove elements from the front of the deque if they are out of the current window
                if (!dq.empty() && dq.front() == j - k)
                    dq.pop_front();

               	// Remove elements from the back of the deque that are smaller than the current element
                while (!dq.empty() && nums[dq.back()] < nums[j])
                    dq.pop_back();

               	// Push the current element's index into the deque
                dq.push_back(j);

               	// Start adding elements to the result once the window size reaches k
                if (j >= k - 1)
                    res.push_back(nums[dq.front()]);
            }

            return res;
        }
};