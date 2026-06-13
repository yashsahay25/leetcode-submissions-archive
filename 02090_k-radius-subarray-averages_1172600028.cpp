class Solution
{
    public:
        vector<int> getAverages(vector<int> &nums, int k)
        {
            int i = 0, j = 0, n = nums.size(); 
            long long sum = 0;
            vector<int> average(n, -1);
            if (k > n) return average;
            int windowSize = 2 *k + 1;
            while (j < n)
            {
                sum += nums[j];
                if (j - i + 1 < windowSize) j++;
                else if (j - i + 1 == windowSize)
                {
                    average[i + k] = sum / (j - i + 1);
                   	// now slide the window
                    sum -= nums[i];
                    i++;
                    j++;
                }
            }
            return average;
        }
};