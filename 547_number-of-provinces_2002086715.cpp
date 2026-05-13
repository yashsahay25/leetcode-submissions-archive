class Solution {
public:
    vector<int> parent, size;
    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }
    void unionDsu(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;
        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // DSU Concept
        parent.resize(n);
        size.resize(n,1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) {
                    unionDsu(i, j);
                }
            }
        }
        int groups=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i) groups++;
        }
        return groups;
    }
};