/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    unordered_map<Node*,Node*>m;
    
    Node* dfs(Node* node){
        Node* clone=new Node(node->val);
        m[node]=clone;
        
        vector<Node*>neighbor;
        for(auto x:node->neighbors){
            if(m.find(x)!=m.end())
                neighbor.push_back(m[x]);
            else
                neighbor.push_back(dfs(x));
        }
        
        clone->neighbors=neighbor;
        return clone;
        
    }
    
    Node* cloneGraph(Node* node) {
        
        if(!node)
            return NULL;
        if(node->neighbors.size()==0)
        {
            Node* clone=new Node(node->val);
            return clone;
        }
        return dfs(node);
    }
};