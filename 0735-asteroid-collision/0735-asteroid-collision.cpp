class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        
        vector<int>res;
        int n=as.size();
        int i=0;
        
        stack<int>s;
        
        while(i<n&&as[i]<0)
        {
            s.push(as[i++]);
        }
        
        for(;i<n;i++){
            
            if(as[i]>0)
                s.push(as[i]);
            else {
                
                while(!s.empty()&&abs(as[i])>s.top()&&s.top()>0){
                    
                    s.pop();
                }
                 
              if(s.empty())
                  s.push(as[i]);
                else if(!s.empty()&&s.top()<0)
                    s.push(as[i]);
                else if(!s.empty()&&s.top()==abs(as[i]))
                    s.pop();
                
            }
            
        }
        
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        reverse(begin(res),end(res));
        return res;
        
    }
};