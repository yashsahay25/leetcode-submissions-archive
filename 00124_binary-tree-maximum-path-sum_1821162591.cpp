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
        // base case
        if(!node) return 0;

        // find left & right child sum (similar to maxHeight logic)
        // to find max, we have to do max(0, negativeSum)
        int leftSum = max(0, solve(node->left, maxSum));
        int rightSum = max(0, solve(node->right, maxSum));

        // update max sum so far
        // sum at each node = node.val + left + right
        maxSum = max(maxSum, node->val + leftSum + rightSum);

        // return statement similar to maxHeight ie. 1 + max(lh,rh)
        return node->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};