/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if (node->right) {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent; // parent hashmap
        getParent(root, parent);

        // reach the target node from root
        // from that node, we have to explore every left, right child & parent
        // for parent, we'll use parentHashmap
        // and to not visit any node again, we'll use visited array/set

        unordered_map<TreeNode*, bool>
            visited; // visited hashmap (can also use set)

        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int distance = 0;

        while (!q.empty()) {
            int size = q.size();

            if (distance == k)  break;
            distance++;
            
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                // left
                if (temp->left && !visited[temp->left]) {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                // right
                if (temp->right && !visited[temp->right]) {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                // parent
                if (parent[temp] && !visited[parent[temp]]) {
                    q.push(parent[temp]);
                    visited[parent[temp]] = true;
                }
            }
        }

        vector<int> result; // answer vector
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            result.push_back(temp->val);
        }
        return result;
    }
};