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
    void dfs(TreeNode* root, long long currSum, int target, unordered_map<long long,int>& mp, int& count){
        if(!root) return;

        currSum += root->val;           // sum so far (running sum)
        long long gain = currSum - target;    // how much extra sum we have (gain)
        if(mp.find(gain)!=mp.end()){    // does there exists a subarray/path having this extra gain
            count += mp[gain];
        }

        mp[currSum]++; // add to map

        dfs(root->left, currSum, target, mp, count);
        dfs(root->right, currSum, target, mp, count);

        mp[currSum]--; // backtrack
    }
    int pathSum(TreeNode* root, int targetSum) {
        // we'll apply the logic used in - find number of subarrays with sum k
        // Hashing + prefix sum
        if(!root) return 0;

        unordered_map<long long, int> mp; // <sum, count of paths having that sum>
        mp[0]=1; // There is 1 path having sum 0
         
        // Note: above is reqd to handle count of paths starting at root with sum=target
        int count=0;
        dfs(root, 0, targetSum, mp, count);
        return count;
    }
};