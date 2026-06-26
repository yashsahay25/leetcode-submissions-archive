class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefixFreq(n, 0); // target Prefix Freq
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                if (i == 0)
                    prefixFreq[i] = 1;
                else
                    prefixFreq[i] = 1 + prefixFreq[i - 1];
            } else {
                if (i == 0)
                    prefixFreq[i] = 0;
                else
                    prefixFreq[i] = prefixFreq[i - 1];
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int len = j - i + 1;
                int freqTarget =
                    prefixFreq[j] - (i > 0 ? prefixFreq[i - 1] : 0);
                if (freqTarget > len / 2)
                    count++;
            }
        }
        return count;
    }
};