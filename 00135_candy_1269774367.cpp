class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 1)
            return 1;
        if (n == 2)
            if (ratings[0] != ratings[1])
                return 3;

        vector<int> left(n, 1), right(n, 1);

        // left side
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        // right side
        for (int i = n - 1; i >= 1; i--) {
            if (ratings[i - 1] > ratings[i]) {
                right[i - 1] = right[i] + 1;
            }
        }

        // reuse left array to store max(L,R)
        int sum = 0;
        for (int i = 0; i < n; i++) {
            left[i] = max(left[i], right[i]);
            sum += left[i];
        }
        return sum;
    }
};