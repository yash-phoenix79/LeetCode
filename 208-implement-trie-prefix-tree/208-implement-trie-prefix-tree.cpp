class Trie {
public:
    
    class TreeNode{
        public:
        bool stringEnd;
        TreeNode* children[26];
        TreeNode(){
            stringEnd=false;
            for(int i=0;i<26;i++)
                children[i]=NULL;
        }
    };

    TreeNode* root;
    
    Trie() {
        root=new TreeNode();
    }
    
    void insert(string word) {
        
        int len=word.length();
        int k=0;
        TreeNode* cur=root;
        for(int i=0;i<len;i++){
            k=word[i]-'a';
            if(cur->children[k]==NULL)
                cur->children[k]=new TreeNode();
            cur=cur->children[k];
        }
        cur->stringEnd=true;
        
    }
    
    bool search(string word) {
        
        int len=word.length();
        int k=0;
        TreeNode* cur=root;
        for(int i=0;i<len;i++){
            k=word[i]-'a';
            if(!cur->children[k])
                return false;
            cur=cur->children[k];
        }
        return cur->stringEnd;
    }
    
    bool startsWith(string prefix) {
        
        int len=prefix.length();
        int k=0;
        TreeNode* cur=root;
        for(int i=0;i<len;i++){
            k=prefix[i]-'a';
            if(!cur->children[k])
                return false;
            cur=cur->children[k];
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */