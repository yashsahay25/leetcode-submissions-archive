class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowSize = n - k;
        int i = 0, j = 0, ans = 0, sum = 0, total = 0;
        for (int x : cardPoints)
            total += x;
        if (n == k)
            return total;
        while (j < n) {
            sum += cardPoints[j];
            if (j - i + 1 < windowSize)
                j++;
            else if (j - i + 1 == windowSize) {
                ans = max(ans, total - sum);
                sum -= cardPoints[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};