class Solution {
public:
    int maxScore(vector<int>& card, int k) {
     
        int mini=INT_MAX,n=card.size();
        int sum=0,tot=0;
        int i,t=n-k;
        for( i=0;i<n;i++){
            tot+=card[i];
            if(i<t)
            sum+=card[i];
        }
        if(k==n)
            return tot;
    
        mini=min(mini,sum);
        
        int j=0;
        i=t;
        while(i<n){
            sum-=card[j++];
            sum+=card[i++];
            mini=min(mini,sum);
        }
        
        return tot-mini;
    }
};