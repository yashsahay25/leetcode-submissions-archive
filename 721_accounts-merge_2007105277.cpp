class Solution {
public:
    vector<int> parent, size;

    // Find ultimate parent with path compression
    int findParent(int node) {

        // Base case: node is its own parent
        if (parent[node] == node) return node;

        // Path compression
        return parent[node] = findParent(parent[node]);
    }

    // Union by size
    void unionSet(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        // Already in same component
        if (pu == pv) return;

        // Attach smaller tree under bigger tree
        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        // Initialize DSU
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        // email -> first account index where seen
        unordered_map<string, int> emailToAccountMap;

        // STEP 1: Build DSU connections
        for (int i = 0; i < n; i++) {

            // Start from 1 because index 0 is name
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                // First time seeing this email
                if (emailToAccountMap.find(email) == emailToAccountMap.end()) {
                    emailToAccountMap[email] = i;
                } else {
                    // Shared email found
                    // Merge both account indices
                    int idx = emailToAccountMap[email];
                    unionSet(i, idx);
                }
            }
        }

        // STEP 2: Group emails by ultimate parent
        unordered_map<int, vector<string>> mergedEmails;

        for (auto& [email, accIndex] : emailToAccountMap) {
            int parentAccount = findParent(accIndex);
            mergedEmails[parentAccount].push_back(email);
        }

        // STEP 3: Build final answer
        vector<vector<string>> ans;

        for (auto& it : mergedEmails) {

            int accIndex = it.first;
            vector<string>& emails = it.second;

            // Emails must be sorted lexicographically
            sort(emails.begin(), emails.end());

            vector<string> temp;

            // Add account holder name
            temp.push_back(accounts[accIndex][0]);

            // Add sorted emails
            for (string& email : emails)
                temp.push_back(email);

            ans.push_back(temp);
        }

        return ans;
    }
};