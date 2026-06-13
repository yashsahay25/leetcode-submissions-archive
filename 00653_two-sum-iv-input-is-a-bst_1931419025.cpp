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
    bool dfs(TreeNode* root, set<int>& s, int k) {
        if (!root)
            return false;

        int complement = k - root->val;
        if (s.find(complement) != s.end())
            return true;

        s.insert(root->val);
        
        return dfs(root->left, s, k) || dfs(root->right, s, k);
    }
    bool findTarget(TreeNode* root, int k) {
        // generic Two Sum Approach
        set<int> s; // use set instead of map as no duplicates in BST
        return dfs(root, s, k);
    }
};