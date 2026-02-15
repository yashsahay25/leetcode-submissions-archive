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
    TreeNode* insertIntoBST(TreeNode* root, int key) {
        if(!root) return new TreeNode(key);
        TreeNode* curr=root;
        while(true){    // keep running an infinite loop, break when position reached 
            if(curr->val < key){    // traverse right subtree if key greater
                // check if we can move right   
                if(curr->right != NULL) curr=curr->right;
                else {
                    // if not, then position reached
                    curr->right = new TreeNode(key);
                    break;
                }

            } else { 
                if(curr->left != NULL) curr=curr->left;
                else {
                    curr->left = new TreeNode(key);
                    break;
                }
            }
        }
        return root;
    }
};