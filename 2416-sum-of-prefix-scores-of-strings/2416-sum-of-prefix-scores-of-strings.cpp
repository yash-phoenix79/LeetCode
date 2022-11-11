class Solution {
public:
    
    struct trie{
      trie* next[26];
        int cnt;
        trie(){
            for(int i=0;i<26;i++)
                next[i]=NULL;
            cnt=0;
        }
    };
    
    trie* root=new trie();
   
    void insert(trie* cur,string s){
  
        for(int i=0;i<s.length();i++){
            int c=s[i]-'a';
            if(!cur->next[c])
                cur->next[c]=new trie();
             cur=cur->next[c];
            cur->cnt++;
       
        }
    }
    
    int find(trie* cur,string s){
        int sum=0;
        
        for(int i=0;i<s.length();i++){
            int c=s[i]-'a';
             cur=cur->next[c];
            
            sum+=cur->cnt;
           
        }
        return sum;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        
        int n=words.size();
        vector<int>res(n);
        
        for(int i=0;i<n;i++){
            trie* cur=root;
            insert(cur,words[i]);
        }
        
        for(int i=0;i<n;i++){
            trie* cur=root;
            res[i]=find(cur,words[i]);
        }
        
        return res;
    }
};