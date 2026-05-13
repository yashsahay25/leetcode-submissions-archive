class Solution {
public:
    vector<int> parent;
    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }
    bool unionDsu(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        
        if (pu == pv) return false;
        
        // directly connect one parent to another (specific to this ques)
        parent[pv] = pu;
        return true;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // DSU Concept
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Initially every node is its own province
        int groups = n;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) {
                    if(unionDsu(i, j)) groups--;
                }
            }
        }
        return groups;
    }
};