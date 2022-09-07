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
    
    void helper1(TreeNode* root,string &res){
        if(!root)
            return;
    
        res+=to_string(root->val);
        res+='-';
        helper1(root->left,res);
        helper1(root->right,res);
        return;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res="";
        helper1(root,res);
        return res;
    }

    // Decodes your encoded data to tree.
    
    TreeNode* helper2(TreeNode* root,int value){
        if(!root){
            TreeNode* temp=new TreeNode(value);
            return temp;
            
        }
        
        if(value<=root->val)
            root->left=helper2(root->left,value);
        else
            root->right=helper2(root->right,value);
        
        return root;
        
    }
    
    TreeNode* deserialize(string data) {
        
        int i=0;
        
        TreeNode* root=NULL;
        
        while(i<data.length()){
            string temp="";
            while(i<data.length()&&data[i]!='-')
                temp+=data[i++];
            i++;
            
            root=helper2(root,stoi(temp));
        }
        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;