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
    // explore all paths from each node, as path can start at each node
    // count paths having target sum from that node

    // pathSum will traverse all nodes
    // countFrom counts all paths starting from that node

    int pathSum(TreeNode* root, int target) {
        if(!root) return 0;

        // count paths that start from current node
        int pathsFromRoot = countFrom(root, target);

        // count paths that start in left or right subtrees
        int pathsFromLeft = pathSum(root->left, target);
        int pathsFromRight = pathSum(root->right, target);

        return pathsFromRoot + pathsFromLeft + pathsFromRight;
        
    }

    int countFrom(TreeNode* node, long target) {
        if (!node) return 0;

        int count = 0;
        if (node->val == target)
            count++;

        count += countFrom(node->left, target - node->val);
        count += countFrom(node->right, target - node->val);

        return count;
    }
};