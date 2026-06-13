class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int total = 1;     // First child
        int prevCandy = 1; // Candies for the previous child
        int decSeq = 0;    // Length of the current decreasing sequence

        for (int i = 1; i < n; i++) {
            if (ratings[i] >= ratings[i - 1]) {
                // End of decreasing sequence, handle its adjustment
                if (decSeq > 0) {
                    total += (decSeq * (decSeq + 1)) /
                             2; // Sum of decreasing sequence
                    if (decSeq >= prevCandy)
                        total += decSeq - prevCandy + 1;
                    decSeq = 0;    // Reset the decreasing sequence
                    prevCandy = 1; // Reset previous candy
                }

                // Handle current increasing or equal case
                prevCandy = (ratings[i] == ratings[i - 1]) ? 1 : prevCandy + 1;
                total += prevCandy;
            } else {
                // Decreasing sequence
                decSeq++;
            }
        }

        // Final adjustment for any remaining decreasing sequence
        if (decSeq > 0) {
            total += (decSeq * (decSeq + 1)) / 2; // Sum of decreasing sequence
            if (decSeq >= prevCandy)
                total += decSeq - prevCandy + 1;
        }

        return total;
    }
};