class TreeAncestor {
public:
    // ancestor[node][j] = ? (say b)
    // we can write 2^j = 2^j-1 + 2^j-1
    // j-1 jumps from node --> ancestor[node][j-1] = a
    // again j-1 jumps from above reached position --> ancestor[a][j] = b
    // so we have, ancestor[ancestor[node][j-1]][j-1] = b
    // therefore, ancestor[node][j] = ancestor[ancestor[node][j-1]][j-1]

    vector<vector<int>> ancestor;
    int m;

    TreeAncestor(int n, vector<int>& parent) {
        m = log2(n) + 1; // max possible value of jumps j

        // ancestor[node][j] = position reached after 2^j jumps from given `node`
        ancestor.resize(n, vector<int>(m, -1));

        // prefill 1st column
        // ie. ancestor[node][0] = 2^0 jumps from given node = 1 jump from given 
        // node = parent of given node
        for (int node = 0; node < n; node++) {
            ancestor[node][0] = parent[node];
        }

        // fill other rows and columns
        for (int j = 1; j < m; j++) {
            for (int node = 0; node < n; node++) {
                if (ancestor[node][j - 1] != -1) {
                    // above check since index should not be -1
                    ancestor[node][j] = ancestor[ancestor[node][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        // to reach kth ancestor, what jumps of power of 2 will be required
        // that can be detemined using set bits of k

        // k ka set bits dhundo, kyoki utna hi jumps lena h
        // for ex k = 5 --> binary = 101 --> (2^2 + 2^0) jumps lena h

        // check all bits from right to left
        for (int j = 0; j < m; j++) {

            // if jth bit is set in k
            if (k & (1 << j)) {

                // lookup ancestor table
                node = ancestor[node][j];

                // if while jumping we surpass root, return -1 as no ancestor
                // would exist
                if (node == -1)
                    return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */