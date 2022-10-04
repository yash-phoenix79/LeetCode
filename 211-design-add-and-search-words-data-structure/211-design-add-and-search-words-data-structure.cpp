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
        return search(word.c_str(),root);
    }
    
    bool search(const char*c,TrieNode* root)
    {
        for(int i=0;c[i]&&root;i++){
            if(c[i]!='.')
                root=root->children[c[i]-'a'];
            else{
                TrieNode* temp=root;
                for(int j=0;j<26;j++){
                  root=temp->children[j];
                    if(search(c+i+1,root))
                        return true;
                }
             
            }
        }
        return root&&root->check;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */