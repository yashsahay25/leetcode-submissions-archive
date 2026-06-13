class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // use a map to keep track of prev elements & their freq
        unordered_map<int, int> m;
        long long ans = 0, s = 0, i = 0, j = 0;

        while (j < nums.size()) {
            m[nums[j]]++; // add element into map or increase its count
            s += nums[j]; // add sum
            if (k == j - i + 1) {
                // if window size reached, check if number of unique elements in
                // the window is equal to map size (size of map gives count of
                // uniques)
                if (m.size() == k)
                    ans = max(ans, s);

                // now slide the window, reduce sum & count in map
                s -= nums[i];
                m[nums[i]]--;
                // if after reducing count, it becomes 0
                // it means that the element doesn't exist anymore in the
                // window, so erase it, else it will be counted
                if (!m[nums[i]])
                    m.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};