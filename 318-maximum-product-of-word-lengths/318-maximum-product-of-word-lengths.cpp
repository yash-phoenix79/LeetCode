class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int>mask(n,0);
        for(int i=0;i<n;i++){
            for(auto &ch:words[i])
                mask[i]|=1<<(ch-'a');
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((mask[i]&mask[j])==0)
                   ans=max(ans,int (size(words[i])*size(words[j]))); 
            }
        }
        return ans;
    }
};