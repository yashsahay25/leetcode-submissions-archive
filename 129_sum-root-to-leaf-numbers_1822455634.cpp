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
    int globalSum=0;
    void calcNumberPathSum(TreeNode* node, int sum){
        if(!node) return;

        sum = sum*10;
        sum += node->val;
        
        if(!node->left && !node->right){
            globalSum += sum;
            return;
        }

        calcNumberPathSum(node->left, sum);
        calcNumberPathSum(node->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        calcNumberPathSum(root,sum);
        return globalSum;
    }
};