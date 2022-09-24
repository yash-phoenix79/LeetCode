class Solution {
public:
    
    class myComparator{
        public:
        bool operator() (const pair<int,string> &a,const pair<int,string> &b){
           
            
            if(a.second==b.second)return a.first<b.first;
            return a.second<b.second;
            
        }
    };
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        
        int n=nums.size();
        int m=q.size(),len=nums[0].length();
        
        vector<int>res(m);
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,myComparator>pq,t;
        
        for(int i=0;i<m;i++){
            int l=len-q[i][1];
            t=pq;
            for(int j=0;j<n;j++){
                  string temp=nums[j].substr(l);
                t.push({j,temp});
                if(t.size()>q[i][0])
                    t.pop();
            }
          res[i]=t.top().first;
        }
        return res;
    }
};