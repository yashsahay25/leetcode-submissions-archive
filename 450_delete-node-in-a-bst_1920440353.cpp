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
    TreeNode* findMax(TreeNode* root){
        while(root->right){
            root=root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent=NULL;
        TreeNode* curr=root;

        while(curr && curr->val!=key){
            parent=curr;
            if(key < curr->val) curr=curr->left;
            else curr=curr->right;
        }
        if(!curr) return root;

        // No or one child
        if(!curr->left || !curr->right){
            TreeNode* newRoot;
            
            // handles both 0/1 cases
            if(!curr->left) newRoot=curr->right;
            else newRoot=curr->left;

            if(!parent) return newRoot; // if root node is to be deleted

            // link parent to newNode
            parent->left == curr ? parent->left = newRoot : parent->right = newRoot;

            delete curr;
        }
        // Both child
        else{
            // Steps:
            // preserve left and right subtree
            // find inorder predecessor in left subtree
            // link succ->right to preserved right subtree
            // if parent is null, delete curr & return early
            // else link parent to left subtree
            // delete curr node
            TreeNode* leftSub = curr->left;
            TreeNode* rightSub = curr->right;

            TreeNode* pred = findMax(leftSub);
            pred->right = rightSub;
            
            if(!parent){
                delete curr;
                return leftSub;
            }            
            
            parent->left == curr? parent->left = leftSub : parent->right = leftSub;
            delete curr;
        }
        return root;
    }
};