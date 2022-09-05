/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
        int n=q.size();
            vector<int>temp;
            while(n--){
                auto cur=q.front();
                q.pop();
                temp.push_back(cur->val);
                for(Node* x:cur->children)
                    q.push(x);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};