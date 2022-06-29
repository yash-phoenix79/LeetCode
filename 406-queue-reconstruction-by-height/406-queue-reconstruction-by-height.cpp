class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        vector<vector<int>>res(n,vector<int>(2,-1));
        
        sort(begin(people),end(people),[](auto &a,auto &b){
           if(a[0]==b[0])
               return a[1]<b[1];
            return a[0]<b[0];
        });
        
        int cnt;
        for(int i=0;i<n;++i){
            cnt=people[i][1];
            for(int j=0;j<n;++j){
                if(res[j][0]==-1&&cnt==0)
                {
                    res[j][0]=people[i][0];
                    res[j][1]=people[i][1];
                    break;
                }
                else if((res[j][0]==-1)||(res[j][0]>=people[i][0]))
                    cnt--;
            }
        }
        
        return res;
        
    }
};