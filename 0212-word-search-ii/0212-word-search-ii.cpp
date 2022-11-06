class Solution {
public:
    
    vector<string>res;
    
    class TrieNode{
        public:
        string word;
        TrieNode* child[26];
        TrieNode(){
            word="";
            for(int i=0;i<26;i++)
                child[i]=NULL;
        }
        
    };
    
    
    
    
    TrieNode* insert(vector<string>&words){
        TrieNode* root=new TrieNode();
        for(int i=0;i<words.size();i++){
            TrieNode* cur=root;
            for(int j=0;j<words[i].length();j++){
                int k=words[i][j]-'a';
                if(!cur->child[k])
                    cur->child[k]=new TrieNode();
                cur=cur->child[k];
            }
            cur->word=words[i];
        }
        return root;
    }
    
    void dfs(int x,int y,vector<vector<char>>& b,TrieNode* p){
        char c=b[x][y];
        if(c=='#'||!p->child[c-'a'])return;
        p=p->child[c-'a'];
        
        if(p->word.size()>0){
            res.push_back(p->word);
            p->word="";
        }
        
        b[x][y]='#';
        if(x>0)dfs(x-1,y,b,p);
        if(y>0)dfs(x,y-1,b,p);
        if(x<b.size()-1)dfs(x+1,y,b,p);
        if(y<b[0].size()-1)dfs(x,y+1,b,p);
        
        b[x][y]=c;
        
    }
    
    vector<string> findWords(vector<vector<char>>& b, vector<string>& words) {
        
        TrieNode* root=insert(words);    
        
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                dfs(i,j,b,root);
            }
        }
        return res;
    }
};