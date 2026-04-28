class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        // SDE-2 Optimization: Normalize the shortcut so 'x' is always the smaller index.
        // This removes the need for complex bi-directional math later.
        if (x > y) swap(x, y);

        // Result array, 0-indexed, so distance 'k' is stored at index 'k-1'.
        vector<int> result(n, 0);

        // Generate every unique pair of houses (leftHouse < rightHouse)
        // This ensures we only calculate each pair once and avoid distance 0.
        for (int rightHouse = 1; rightHouse <= n; ++rightHouse) {
            for (int leftHouse = 1; leftHouse < rightHouse; ++leftHouse) {
                
                // Path 1: Walk directly down the sequential street
                int directDist = rightHouse - leftHouse;
                
                // Path 2: Walk to 'x', take the shortcut to 'y', then walk to rightHouse
                int shortcutDist = abs(leftHouse - x) + 1 + abs(rightHouse - y);
                
                // The true distance is simply the shorter of the two paths
                int shortestDist = min(directDist, shortcutDist);
                
                // Add 2 to our result because the graph is undirected 
                // (The path from leftHouse -> rightHouse also counts as rightHouse -> leftHouse)
                result[shortestDist - 1] += 2;
            }
        }

        return result;
    }
};