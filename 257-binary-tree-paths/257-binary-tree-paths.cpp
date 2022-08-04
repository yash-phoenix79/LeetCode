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
    vector<string>res;
    bool check=true;
    void findPath(TreeNode* root,string t){
        
        if(!root)
            return;
        string temp=to_string(root->val);
        if(!check)
        t+="->";
        t+=temp;
        check=false;
        if(!root->left&&!root->right)
        {
           res.push_back(t);
            return;
        }
        findPath(root->left,t);
        findPath(root->right,t);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
     string t="";
        findPath(root,t);
        return res;
    }
};