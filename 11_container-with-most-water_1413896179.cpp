class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, maxArea = 0;
        while (i < j) {
            int h = min(height[i], height[j]);
            int w = j - i;
            maxArea = max(maxArea, w * h);

            // now move the pointer pointing to shorter line
            height[i] < height[j] ? i++ : j--;
        }
        return maxArea;
    }
};