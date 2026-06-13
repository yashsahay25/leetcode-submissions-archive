/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void getParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root)  return;
        
        if (root->left)     parent[root->left] = root;
        if (root->right)    parent[root->right] = root;

        getParent(root->left, parent);
        getParent(root->right, parent);
    }

    TreeNode* findNode(TreeNode* root, int key) {
        if (!root || root->val == key)  return root;

        TreeNode* left = findNode(root->left, key); // find in left first
        if (left) return left; // if left exists, return it

        return findNode(root->right, key); // else find in right subtree
    }
    int calcTime(TreeNode* startNode, unordered_map<TreeNode*, TreeNode*>& parent){
        unordered_map<TreeNode*, bool> visited; // visited hashmap
        
        queue<TreeNode*> q;
        q.push(startNode);
        visited[startNode] = true;

        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            time++;
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

        return time-1;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent; // parent hashmap
        parent[root] = NULL;
        getParent(root, parent);

        TreeNode* startNode = findNode(root, start); // get start node

        return calcTime(startNode,parent);
    }
};