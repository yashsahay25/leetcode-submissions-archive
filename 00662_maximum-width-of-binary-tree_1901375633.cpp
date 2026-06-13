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
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});

        // node at index i, left child at 2i+1, right at 2i+2 (0-based indexing)
        while(!q.empty()){
            int size=q.size();
            int firstIdx = q.front().second;
            int lastIdx = q.back().second;
            
            maxWidth = max(maxWidth, lastIdx-firstIdx+1);

            for(int i=0;i<size;i++){
                TreeNode* temp = q.front().first;
                unsigned long long idx = q.front().second;
                q.pop();

                if(temp->left) q.push({temp->left,2*idx+1});
                if(temp->right) q.push({temp->right,2*idx+2});
            }
        }
        return maxWidth;
    }
};