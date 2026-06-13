class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 1)
            return 1;
        if (n == 2)
            if (ratings[0] != ratings[1])
                return 3;

        vector<int> candies(n, 1);

        // left side
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // right side
        for (int i = n - 1; i >= 1; i--) {
            if (ratings[i - 1] > ratings[i]) {
                candies[i - 1] = max(candies[i] + 1, candies[i - 1]);
            }
        }

        // reuse left array to store max(L,R)
        int sum = 0;
        for (int c : candies)
            sum += c;
        return sum;
    }
};