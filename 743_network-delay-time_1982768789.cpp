typedef pair<int, int> pii;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> adj(n + 1);

        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> time(n + 1, 1e9);

        pq.push({0, k}); // <timeToReachNode, node>
        time[k] = 0;

        while (!pq.empty()) {
            auto [timeToReachNode, node] = pq.top();
            pq.pop();

            if (timeToReachNode > time[node]) continue;

            for (auto& [nbr, timeToReachNbr] : adj[node]) {
                if (timeToReachNode + timeToReachNbr < time[nbr]) {
                    time[nbr] = timeToReachNode + timeToReachNbr;
                    pq.push({time[nbr], nbr});
                }
            }
        }

        int minTime = 0; // min Time to cover all (so we take max of all , except 1e9)
        for (int i = 1; i <= n; i++) {
            if (time[i] == 1e9) return -1;
            minTime = max(minTime, time[i]);
        }
        return minTime;
    }
};