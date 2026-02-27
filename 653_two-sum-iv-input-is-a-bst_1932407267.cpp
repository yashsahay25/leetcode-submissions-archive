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
class BSTIterator {
private:
    stack<TreeNode*> st;
    bool reverse;  // false = normal inorder, true = reverse inorder

    // Push nodes depending on traversal direction
    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            if (reverse)
                node = node->right;   // reverse inorder
            else
                node = node->left;    // normal inorder
        }
    }

public:
    // Constructor
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    // Get next element
    int next() {
        TreeNode* temp = st.top();
        st.pop();

        // If normal → explore right subtree
        // If reverse → explore left subtree
        if (!reverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);

        return temp->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        // Left iterator → smallest
        BSTIterator left(root, false);

        // Right iterator → largest
        BSTIterator right(root, true);

        int i = left.next();
        int j = right.next();

        // Two-pointer logic
        while (i < j) {
            int sum = i + j;

            if (sum == k)
                return true;
            else if (sum < k)
                i = left.next();      // move left forward
            else
                j = right.next();     // move right backward
        }

        return false;
    }
};