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
    int solve(TreeNode* node, int& maxSum){
        if(!node) return 0; // base case

        // Recursively get the max path sum from left and right subtrees
        // Ignore negative sums by comparing with 0
        int leftSum = max(0, solve(node->left, maxSum));
        int rightSum = max(0, solve(node->right, maxSum));
        
        // -ve sum not considered above
        // sum through this node
        int sumThruNode = node->val + leftSum + rightSum;

        // update global sum
        maxSum = max(maxSum, sumThruNode);

        return node->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;   // declare max global sum as INT_MIN due to -ve values
        solve(root, maxSum);    // pass maxSum by reference    
        return maxSum;          // return global sum
    }
};