class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //sorting -> nlogn
        //heap ->nlogk
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 1; i <= k-1; i++)
            pq.pop();
        return pq.top();
    }
};