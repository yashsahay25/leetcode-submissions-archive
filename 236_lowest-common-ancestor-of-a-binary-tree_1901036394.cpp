/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool pathRootToNode(TreeNode* node, int data, vector<TreeNode*>& path) {
        if (!node)  return false;
        
        path.push_back(node); // add current node to path

        if (node->val == data)  return true; // if current node is target val, return true

        if (pathRootToNode(node->left, data, path) ||
            pathRootToNode(node->right, data, path))
            return true; // if any children are target val, return true

        path.pop_back(); // else backtrack & retun false
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Brute force

        vector<TreeNode*> pathP, pathQ;

        // find path for both nodes
        pathRootToNode(root, p->val, pathP);
        pathRootToNode(root, q->val, pathQ);

        // now compare both paths & stop at differing element
        int i=0;
        int size = min(pathP.size(), pathQ.size());
        
        while(i<size && pathP[i]->val == pathQ[i]->val)
            i++;
        return pathP[i-1];
    }
};