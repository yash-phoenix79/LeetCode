class Solution {
public:
    
    struct trie{
        trie*next[2];
        trie(){
            next[0]=next[1]=NULL;
        }
    };
    
   trie* root=new trie();
    
    int res=0;
    
    int find(trie*cur,int num){
        int sum=0;
        for(int i=31;i>=0;i--){
            int val=(num>>i)&1;
            if(cur->next[!val]){
                sum+=(1<<i);
                cur=cur->next[!val];
            }
            else
                cur=cur->next[val];
        }
        return sum;
    }
    
    void insert(trie* cur,int num){
        for(int i=31;i>=0;i--){
            int val=(num>>i)&1;
            if(!cur->next[val])
                cur->next[val]=new trie();
            cur=cur->next[val];
        }
    }
    
    
    
    int findMaximumXOR(vector<int>& nums) {
        
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            trie* cur=root;
            insert(cur,nums[i]);
            res=max(res,find(cur,nums[i]));
        }
        
        return res;
        
    }
};