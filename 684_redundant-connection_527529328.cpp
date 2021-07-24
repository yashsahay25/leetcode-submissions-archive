class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int v) 
    {
        if (parent[v] == -1)
            return v;
        return parent[v] = find(parent[v]); //path compression
    }
    
    void unite(int pu, int pv) 
    { 
        if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else if(rank[pu] < rank[pv])
            parent[pv] = pu;
        else
        {
            parent[pu]=pv;
            rank[pv]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        parent.resize(n, -1);
        rank.resize(n, 0);
        for (auto edge: edges) 
        {
            int pu = find(edge[0]-1);
            int pv = find(edge[1]-1);
            
            if (pu != pv) //different abs parent
                unite(pu, pv);
            else 
                return {edge[0], edge[1]};  //if same, cycle detected, return edge
        }
        return {};  //if nothing found, return empty vector
    }
};