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
    // Make these modification in maxHeight/maxDepth code
    // if subtree does not contain infected node, return maximum depth like normal
    // if subtree contains infected node, return infected node depth 
    // (use negative value to distinguish this case)
    int dfs(TreeNode* node, int start, int& maxDistance){
        if(!node) return 0;

        // calc left and right depth
        int lh=dfs(node->left, start, maxDistance);
        int rh=dfs(node->right, start, maxDistance);

        if(node->val==start){
            // if current node is the original infected node
            // initial maxD will be max left/right subtree depth
            maxDistance= max(lh,rh);
            return -1;  // return -1 to parent node to indicate infection + depth
        }
        else if(lh>=0 && rh>=0){
            // if both depth are +ve, no node in subtree is infected
            // so return maxDepth like normal 
            return max(lh,rh)+1;
        }
        else{
            // if either of left or right subtree is infected (lh or rh is -ve)
            // sum depth of original infected node (-ve) and max depth of the other subtree (+ve)
            maxDistance=max(maxDistance, abs(lh)+abs(rh));
            return min(lh,rh)-1; // add 1 to depth and return
        }
        return 0;
    }
    int amountOfTime(TreeNode* root, int start) {
        int maxDistance=0;
        dfs(root, start, maxDistance);
        return maxDistance;
    }
};