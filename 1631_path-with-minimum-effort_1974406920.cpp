typedef tuple<int, int, int> tp;  // (effort, x, y)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        // effort[i][j] = minimum effort required to reach cell (i, j)
        // Initialize with a very large value (infinity)
        vector<vector<int>> effort(n, vector<int>(m, 1e9));

        // Starting point requires 0 effort
        effort[0][0] = 0;

        // Min-heap (priority queue) storing: (effort, x, y)
        // We always process the cell with the minimum effort so far
        priority_queue<tp, vector<tp>, greater<tp>> pq;

        // Start from top-left cell
        pq.push({0, 0, 0});

        // Direction arrays for moving: right, up, left, down
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {1, 0, -1, 0};

        // Standard Dijkstra loop
        while (!pq.empty()) {

            // Get the cell with the minimum effort so far
            auto [currEffort, x, y] = pq.top();
            pq.pop();

            // IMPORTANT OPTIMIZATION:
            // If we have already found a better way to reach (x, y),
            // skip this outdated entry
            if (currEffort > effort[x][y]) continue;

            // If we reached destination, this is the minimum possible effort
            // (because Dijkstra guarantees optimality)
            if (x == n - 1 && y == m - 1)
                return currEffort;

            // Explore all 4 directions
            for (int k = 0; k < 4; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                // Boundary check for next cell
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                // Cost to move to neighbor:
                // absolute difference in heights
                int diff = abs(heights[nx][ny] - heights[x][y]);

                // KEY IDEA:
                // Path effort = maximum edge cost encountered so far
                // So we take max of:
                // - current path effort
                // - this edge's cost
                int newEffort = max(currEffort, diff);

                // Relaxation step:
                // If this path gives a better (smaller) effort, update it
                if (newEffort < effort[nx][ny]) {
                    effort[nx][ny] = newEffort;

                    // Push updated state into the priority queue
                    pq.push({newEffort, nx, ny});
                }
            }
        }

        return 0;
    }
};