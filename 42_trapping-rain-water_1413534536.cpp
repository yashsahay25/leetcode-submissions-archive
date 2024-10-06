class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1, lmax = 0, rmax = 0, water = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                // water will depend on left boundary
                // now 2 cases, height[l] > or < lmax
                if (height[l] >= lmax) {
                    lmax = height[l];
                } else {
                    water += lmax - height[l];
                }
                l++;
            } else {
                if (height[r] >= rmax) {
                    rmax = height[r];
                } else {
                    water += rmax - height[r];
                }
                r--;
            }
        }
        return water;
    }
};