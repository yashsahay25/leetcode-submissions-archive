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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        // keep traversing till all nodes aren't traversed
        while (curr) {
            // if left doesn't exist, we print root & move to right [rule of inorder]
            if (!curr->left) {
                result.push_back(curr->val);
                curr = curr->right;
            } 
            // traverse left subtree if it exists
            else { 
                // inorder predecessor ie. prev node of curr node in inorder traversal
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right; // move to the rightmost node in left subtrree
                }

                // create a temp thread to curr node for moving back directly in one jump
                if (!prev->right) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    // break the created link and move right
                    prev->right = NULL;
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return result;
    }
};