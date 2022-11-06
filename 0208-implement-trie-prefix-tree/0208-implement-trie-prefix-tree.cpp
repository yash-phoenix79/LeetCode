class Trie {
public:
    
    class TrieNode{
        public:
        
        bool end;
        TrieNode*child[26];
        TrieNode(){
            end=false;
            for(int i=0;i<26;i++)
                child[i]=NULL;
        }
        
    };
    
    TrieNode* root=new TrieNode();
    
    Trie() {
        
       
        
    }
    
    void insert(string word) {
        
        int i=0,n=word.length();
        
        TrieNode* t=root;
        for(i=0;i<n;i++){
            if(t->child[word[i]-'a']==NULL){
                t->child[word[i]-'a']=new TrieNode();
            }
            
            t=t->child[word[i]-'a'];
            
        }
        
        t->end=true;
        
        
    }
    
    bool search(string word) {
        
        int i=0,n=word.length();
        TrieNode* t=root;
        
        for(i=0;i<n;i++){
            
            if(t->child[word[i]-'a']==NULL)
                return false;
             t=t->child[word[i]-'a'];
            
        }
        return t->end;
        
    }
    
    bool startsWith(string word) {
     
        int i=0,n=word.length();
        TrieNode* t=root;
        
        for(i=0;i<n;i++){
            
            if(t->child[word[i]-'a']==NULL)
                return false;
             t=t->child[word[i]-'a'];
            
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