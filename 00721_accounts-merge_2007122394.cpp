class Solution {
public:
    void dfs(set<string>& collectedEmails, int accountIndex,
             vector<bool>& visited, map<string, vector<int>>& emailToAccounts,
             vector<vector<string>>& accounts) {

        // Already processed
        if (visited[accountIndex])
            return;

        // Mark current account visited
        visited[accountIndex] = true;

        // first index is name, emails start from index 1
        for (int j = 1; j < accounts[accountIndex].size(); j++) {

            string email = accounts[accountIndex][j];

            // Add email to final merged set
            collectedEmails.insert(email);

            // Find all accounts sharing this email.
            for (int neighborAccount : emailToAccounts[email]) {

                // DFS on connected account
                dfs(collectedEmails, neighborAccount, visited, emailToAccounts,
                    accounts);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        // accounts, index
        map<string, vector<int>> emailToAccounts;

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                emailToAccounts[email].push_back(i);
            }
        }

        vector<bool> visited(accounts.size(), false);
        vector<vector<string>> result;

        // start DFS
        for (int i = 0; i < accounts.size(); i++) {
            if (!visited[i]) {
                // Stores unique sorted emails automatically
                set<string> collectedEmails;

                // Collect all connected emails/accounts
                dfs(collectedEmails, i, visited, emailToAccounts, accounts);

                // Build merged account
                vector<string> mergedAccount;

                // Add account holder name
                mergedAccount.push_back(accounts[i][0]);

                // Add sorted emails
                for (string email : collectedEmails) {
                    mergedAccount.push_back(email);
                }

                result.push_back(mergedAccount);
            }
        }

        return result;
    }
};