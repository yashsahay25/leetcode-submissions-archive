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
class Solution {
public:
    vector<vector<int>> levelOrderTraversal(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            result.push_back(level);
        }
        return result;
    }

    int minSwaps(vector<int>& arr) {
        // Target: minimum number of swaps to sort an array
        int swaps = 0;

        // Step 1: duplicate the given arr & sort it
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        // Step 2: Maintain <arr[i],index> of original arr in hashap
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
        }

        // Step 3: Now iterate both the arrays, to find element out of place
        for (int i = 0; i < arr.size(); i++) {

            // Step 4: don't do anything if both elements are same
            if (sorted[i] == arr[i])
                continue;

            // Step 5: if they're different
            int correctIdx = mp[sorted[i]]; // find correct index where arr[i] should go
            mp[arr[i]] = correctIdx;        // update map before swap
            mp[arr[correctIdx]] = i;
            swap(arr[i],arr[correctIdx]);   // do the swap
            swaps++;
        }
        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        int swaps = 0;

        // Step 1: find level order traversal of given BT
        vector<vector<int>> levelOrder = levelOrderTraversal(root);

        // Step 2: Find min swaps to sort each row/array and count totalSwaps
        for (auto& level : levelOrder) {
            swaps += minSwaps(level);
        }

        // Step 3: return total swaps
        return swaps;
    }
};