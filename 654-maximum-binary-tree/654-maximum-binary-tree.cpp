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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*>bt;
        
        for(int i=0;i<nums.size();i++){
            TreeNode* cur=new TreeNode(nums[i]);
            while(!bt.empty()&&bt.back()->val<nums[i])
            {
                cur->left=bt.back();
                bt.pop_back();
            }
            if(!bt.empty())
             bt.back()->right=cur;
            bt.push_back(cur);
        }
        return bt.front();
    }
};