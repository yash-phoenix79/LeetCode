class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
       vector<int>ans(n);
        
        stack<int>s;
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&temp[i]>=temp[s.top()])
                s.pop();
          ans[i]=s.empty()?0:s.top()-i;
            s.push(i);
        }
        return ans;
    }
};