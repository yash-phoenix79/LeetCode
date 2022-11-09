class Solution {
public:
    
    struct trie{
      trie* next[2];
        trie(){
            next[0]=NULL;
            next[1]=NULL;
        }
    };
    
    class TrieNode{
        private:
        trie* root;
        public:
        TrieNode(){
          root=new trie();   
        };
        void insert(int num){
            trie* cur=root;
            for(int i=31;i>=0;i--){
                int mas=(num>>i)&1;
                if(!cur->next[mas])
                    cur->next[mas]=new trie();
                cur=cur->next[mas];
            }
        }
        
        int maxXoR(int num){
            int val=0;
            trie*cur=root;
            for(int i=31;i>=0;i--){
                int mas=(num>>i)&1;
                if(cur->next[!mas]){
                    val+=(1<<i);
                    cur=cur->next[!mas];
                }
                else
                    cur=cur->next[mas];
            }
             return val;
        }
       
        
    };
    
    int findMaximumXOR(vector<int>& nums) {
        
        int n=nums.size();
        int res=0;
        
        TrieNode* t=new TrieNode();
        
        for(int i=0;i<n;i++){
            t->insert(nums[i]);
            res=max(res,t->maxXoR(nums[i]));
            
        }
        
        return res;
        
    }
};