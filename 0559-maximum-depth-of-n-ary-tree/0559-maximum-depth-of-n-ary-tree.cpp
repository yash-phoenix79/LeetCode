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
    
    int find(Node* root)
    {
    if(!root)
        return 0;
        int res=0;
        for(auto x:root->children)
            res=max(res,1+find(x));
        return res;
    }
    
    
    int maxDepth(Node* root) {
        
        if(!root)return 0;
        
       return 1+find(root);
        
        
    }
};