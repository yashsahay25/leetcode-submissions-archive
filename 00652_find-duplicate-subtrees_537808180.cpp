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
    unordered_map<string,int> m;
    vector<TreeNode*> res;

    string solve(TreeNode *root)
    {
        if(!root)   return "#";
        /*if(!root->left and !root->right)
        {
            string s = to_string(root->data);
            return s;
        }*/
        string s="";
        s+= to_string(root->val);
        s+= "#";
        s+= solve(root->left);
        s+= "#";
        s+= solve(root->right);
        m[s]++;
        if(m[s]==2)
            res.push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        m.clear();
        res.clear();
        solve(root);
        return res;
    }
};