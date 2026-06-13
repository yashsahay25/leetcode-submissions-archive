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
class BSTIterator {
private:
    stack<TreeNode*> st;

    // Helper function:
    // Pushes all left children of a subtree into stack
    // This ensures smallest element stays on top
    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

public:
    // Constructor
    // Initialize stack with leftmost path of root
    BSTIterator(TreeNode* root) { 
        pushAllLeft(root); 
    }

    // Returns true if there is a next smallest number
    bool hasNext() { 
        return !st.empty(); 
    }

    // Returns next smallest number in BST
    int next() {
        TreeNode* temp = st.top(); // Top element is next smallest
        st.pop();

        // If there is a right subtree, push all its left children
        if (temp->right != nullptr) {
            pushAllLeft(temp->right);
        }
        
        return temp->val;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */