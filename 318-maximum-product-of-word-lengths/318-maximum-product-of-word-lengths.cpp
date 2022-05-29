class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=size(words),ans=0;
        vector<int>mask(n,0);
        for(int i=0;i<n;i++)
            for(auto &ch:words[i])
                mask[i]|=(1<<(ch-'a'));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(__builtin_popcount(mask[i]&mask[j])==0)
                    ans=max(ans,int(size(words[i])*size(words[j])));
            }
        }
        return ans;
    }
};