class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0) {
            if (nums1 == nums2) return 0;
            return -1;
        }

        int n = nums1.size();
        long long diffSum = 0, netDiff = 0;
        for (int i = 0; i < n; i++) {
            long long diff = (long long)nums1[i] - nums2[i];
            if (diff % k != 0) return -1;
            diffSum += abs(diff) / k;
            netDiff += diff / k;
        }
        return netDiff == 0 ? diffSum / 2 : -1;
    }
};