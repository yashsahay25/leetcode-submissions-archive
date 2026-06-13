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
        vector<tuple<int,int,int>> nodes; // col, row, val
        dfs(root, 0, 0, nodes);

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> result;
        int prevCol = INT_MIN;

        for (auto &[col, row, val] : nodes) {
            if (col != prevCol) {
                result.push_back({});
                prevCol = col;
            }
            result.back().push_back(val);
        }
        return result;
    }

    void dfs(TreeNode* node, int col, int row,
             vector<tuple<int,int,int>>& nodes) {
        if (!node) return;
        nodes.push_back({col, row, node->val});
        dfs(node->left, col - 1, row + 1, nodes);
        dfs(node->right, col + 1, row + 1, nodes);
    }
};
