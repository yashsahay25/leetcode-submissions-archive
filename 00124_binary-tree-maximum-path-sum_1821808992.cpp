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
        // pass maxSum by ref so that it keeps getting updated
        
        if(!node) return 0; // base case

        // At each point, maxSum is max of 4 values
        // node.val, node + left, node + right, node + both left & right
        // compare with 0 to ignore -ve values, as they decrease sum
        int lSum = max(0, solve(node->left, maxSum));
        int rSum = max(0, solve(node->right, maxSum));

        int sumThruLeft = node->val + lSum;
        int sumThruRight = node->val + rSum;
        int sumThruBoth = node->val + lSum + rSum;

        int maxSumThruNode = max({sumThruLeft, sumThruRight, sumThruBoth, node->val});

        maxSum = max(maxSum, maxSumThruNode);

        // For return statement, we only return those values which can form a path
        // so possible values are: sumThruLeft, sumThruRight
        // sumThruBoth cannot form path with ancestors as it already a complete path
        // node->val alone cannot be taken without considering its children

        return max(sumThruLeft, sumThruRight);
        // return node->val + max(lSum, rSum);
    }
    int maxPathSum(TreeNode* root) {
        // maxSum variable to track the global path sum
        // initialised with INT_MIN as answer can be -ve
        int maxSum = INT_MIN;
        
        // helper method, which modifie/updates maxSum accordingly
        solve(root, maxSum);

        return maxSum;
    }
};