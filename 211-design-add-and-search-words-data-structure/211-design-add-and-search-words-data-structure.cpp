class WordDictionary {
public:
    
    class TrieNode{
        public:
        bool check;
        TrieNode* children[26];
        TrieNode(){
            check=false;
            memset(children,NULL,sizeof(children));
        }
    };
    
    TrieNode* root=new TrieNode();
    
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        
        int len=word.length();
        int k=0;
        TrieNode* cur=root;
        
        for(int i=0;i<len;i++){
            k=word[i]-'a';
            if(!cur->children[k])
                cur->children[k]=new TrieNode();
            cur=cur->children[k];
        }
        
        cur->check=true;
    }
    
    bool search(string word) {
        
        return check(word.c_str(),root);
        
    }
    
    bool check(const char*c,TrieNode* cur){
        
        for(int i=0;c[i]&&cur;i++){
            if(c[i]!='.')
                cur=cur->children[c[i]-'a'];
            else{
                TrieNode*tmp=cur;
                for(int j=0;j<26;j++){
                    cur=tmp->children[j];
                    if(check(c+i+1,cur))
                        return true;
                }
            }
        }
        return cur&&cur->check;
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */