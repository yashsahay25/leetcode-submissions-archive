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
        vector<tuple<int,int,int>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            int col = pos.first, row = pos.second;

            nodes.push_back({col, row, node->val});

            if (node->left)
                q.push({node->left, {col - 1, row + 1}});
            if (node->right)
                q.push({node->right, {col + 1, row + 1}});
        }

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> result;
        int prevCol = INT_MIN;
        for (auto &[c, r, v] : nodes) {
            if (c != prevCol) {
                result.push_back({});
                prevCol = c;
            }
            result.back().push_back(v);
        }
        return result;
    }
};
