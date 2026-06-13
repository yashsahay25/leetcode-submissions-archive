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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;

        // store {node, depth, horizontal-dist}
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        
        // map<col, map<row, multiset<values>>>
        map<int, map<int, multiset<int>>> mp;

        while(!q.empty()){
            // pop the element at front
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int col = p.second.first;
            int row = p.second.second;
            
            // insert into map
            // Like mp[0][0] = root->val
            mp[col][row].insert(node->val);

            // push left and right children to q if exists
            if(node->left) q.push({node->left,{col-1,row+1}});
            if(node->right) q.push({node->right,{col+1,row+1}});
        }

        // copy elements into output vector
        for (auto &[col, rows] : mp) {
            vector<int> column;
            for (auto &[row, values] : rows) {
                column.insert(column.end(),values.begin(), values.end());
            }
            result.push_back(column);
        }
        return result;
    }
};