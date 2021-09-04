class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Return early if input is empty
        if (nums.size()==0) return 0;
		
        int bestProd = INT_MIN;
        // Running products
        int maxProd = 1;
        int minProd = 1;
        
        for (int n: nums) {
            if (n < 0) {
                // Swap max and min
                swap(maxProd, minProd);
            }
            // Reset to current value if smaller or larger than it
            // (means that we start considering a new sub-array)
            maxProd = max(maxProd*n, n);
            minProd = min(minProd*n, n);
            // Update the best
            bestProd = max(bestProd, maxProd);
        }
        return bestProd;
    }
};