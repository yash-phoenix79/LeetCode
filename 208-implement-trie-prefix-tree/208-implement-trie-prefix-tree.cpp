class Trie {
public:
    
    class TrieNode{
      public:
        bool stringEnd;
        TrieNode* children[26];
        TrieNode(){
            stringEnd=false;
            for(int i=0;i<26;i++)
                children[i]=NULL;
        }
    };
    
    TrieNode *root;
    
    Trie() {
        root= new TrieNode();
    }
    
    void insert(string word) {
        
        int len=word.length();
        int k=0;
        TrieNode* cur=root;
        for(int i=0;i<len;i++){
            k=word[i]-'a';
            if(!cur->children[k])
                cur->children[k]=new TrieNode();
            cur=cur->children[k];
        }
        cur->stringEnd=true;
        
    }
    
    bool search(string word) {
     
        int len=word.length();
        int k=0;
        TrieNode* cur=root;
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
        TrieNode* cur=root;
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