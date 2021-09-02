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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return genTree(1,n);
    }
    vector<TreeNode*> genTree(int lo,int hi)
    {
        vector<TreeNode*> res;
        if(lo>hi)
        {
            res.push_back(NULL);
            return res;
        }
        if(lo==hi)
        {
            TreeNode* root = new TreeNode(lo);
            res.push_back(root);
            return res;
        }
        for(int i=lo;i<=hi;i++)
        {
            vector<TreeNode*> leftside = genTree(lo,i-1);
            vector<TreeNode*> rightside = genTree(i+1,hi);
            
            for(auto l:leftside)
                for(auto r:rightside)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
        }
        return res;
    }
};