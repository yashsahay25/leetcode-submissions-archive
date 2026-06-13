class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        unordered_map<int, vector<int>> mp; // <value, list of indices>
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);

        vector<bool> visited(n, 0);
        visited[0] = 1;

        int steps = 0; // answer

        // standard BFS
        while (!q.empty()) {
            int levelSize = q.size();

            while(levelSize--) {
                int i = q.front();
                q.pop();

                // Target found
                if (i == n - 1) return steps;

                if (i - 1 >= 0 && !visited[i - 1]) {
                    q.push(i - 1);
                    visited[i - 1] = 1;
                }
                if (i + 1 < n && !visited[i + 1]) {
                    q.push(i + 1);
                    visited[i + 1] = 1;
                }
                // check indexes having same value
                for (int j : mp[arr[i]]) {
                    if (!visited[j]) {
                        q.push(j);
                        visited[j] = 1;
                    }
                }
                // IMPORTANT STEP
                mp.erase(arr[i]);
            }
            steps++;
        }
        return 0;
    }
};