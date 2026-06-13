typedef pair<int,double> pid;
typedef pair<double,int> pdi;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pid>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i]; // use double for probability
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt}); // undirected graph
        }

        // max-heap, we need max probability first
        priority_queue<pdi> pq;
        vector<double> prob(n,0.0);

        prob[start_node]=1.0; // not 0.0
        pq.push({1.0,start_node});

        while(!pq.empty()){
            auto [probSoFar, node]=pq.top();
            pq.pop();

            if(node==end_node) return probSoFar;

            for(auto& [nbr,wt]:adj[node]){
                if(probSoFar * wt > prob[nbr]){
                    prob[nbr]=probSoFar*wt;
                    pq.push({prob[nbr],nbr});
                }
            }
        }
        return prob[end_node];
    }
};