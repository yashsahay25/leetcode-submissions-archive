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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        // keep traversing till all nodes aren't traversed
        while (curr) {
            // if left doesn't exist, we print root & move to right
            if (!curr->left) {
                result.push_back(curr->val);
                curr = curr->right;
            } 
            // traverse left subtree if it exists
            else { 
                // preorder predecessor ie. prev node of curr node in preorder traversal
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right; // move to the rightmost node in left subtrree
                }

                // create a temp thread to curr node for moving back directly in one jump
                if (!prev->right) {
                    prev->right = curr;
                    result.push_back(curr->val);
                    curr = curr->left;
                } else {
                    // break the created link and move right
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return result;
    }
};