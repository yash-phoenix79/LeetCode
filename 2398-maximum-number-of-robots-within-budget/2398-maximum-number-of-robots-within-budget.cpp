class Solution {
public:
    int maximumRobots(vector<int>& ch, vector<int>& ru, long long bud) {
        
        long long sum=0,i=0,j,n=ch.size();
        multiset<int>s;
        
        for(j=0;j<n;j++){
            sum+=ru[j];
            s.insert(ch[j]);
            if(*rbegin(s)+(j-i+1)*sum>bud){
                sum-=ru[i];
                s.erase(s.find(ch[i++]));
            }
        }
        return n-i;
    }
};