typedef tuple<int, int, int> tp;
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        // make the adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // distance vector (time in this case)
        vector<int> time(n, 1e9);

        // pq to store <cost,time,node>
        priority_queue<tp, vector<tp>, greater<tp>> pq;

        pq.push({passingFees[0], 0, 0});
        time[0] = 0;

        while (!pq.empty()) {
            auto [costSoFar, timeSoFar, node] = pq.top();
            pq.pop();

            // The very first time we reach the destination, we pop it as
            // it is mathematically guaranteed to be the cheapest valid path
            // because of the min-heap.
            if (node == n - 1)
                return costSoFar;

            // traverse neighbors
            for (auto& [nbr, wt] : adj[node]) {
                int newTime = timeSoFar + wt;
                int newCost = costSoFar + passingFees[nbr];

                // explore the faster path
                if (newTime <= maxTime && newTime < time[nbr]) {
                    time[nbr] = newTime;
                    pq.push({newCost, newTime, nbr});
                }
            }
        }
        return -1;
    }
};