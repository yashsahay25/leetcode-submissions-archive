/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        // BFS approach - we stop as soon as we get a leaf node
        if(!root) return 0;

        queue<pair<TreeNode*, int>> q; // Node, depth
        q.push({root,1});
        
        while(!q.empty()){
            auto [curr, depth] = q.front();
            q.pop();

            if(!curr->left && !curr->right) return depth;

            if(curr->left) q.push({curr->left, depth+1});
            if(curr->right) q.push({curr->right, depth+1});
        }
        return 0;
    }
};