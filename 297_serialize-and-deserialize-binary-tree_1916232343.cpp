/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // we use X for NULL nodes (so as to stop traversal there) &
        // comma is used as delimiter to distinguish digits/numbers
       if(!root) return "X,";

       // preorder
       string leftSerialize = serialize(root->left);
       string rightSerialize = serialize(root->right);
       return to_string(root->val)+"," + leftSerialize + rightSerialize; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s;
        for(int i=0;i<data.size();i++){ // iterate the given data string
            if(data[i]==','){   // if comma is reached
                q.push(s);      // push number so far into q
                s="";           // reset number string s
                continue;       // skip
            }
            s += data[i];   // keep concatenating digits to form number until comma is reached
        }
        if(s.size()!=0) q.push(s);  // push last number as for loop ended on last comma
        return deserialize_helper(q);
    }

    // helper method
    TreeNode* deserialize_helper(queue<string> &q) {
        // similar to BFS
        string s=q.front();
        q.pop();

        if(s=="X")return NULL;
        TreeNode* root=new TreeNode(stoi(s));
        
        root->left=deserialize_helper(q);
        root->right=deserialize_helper(q);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));