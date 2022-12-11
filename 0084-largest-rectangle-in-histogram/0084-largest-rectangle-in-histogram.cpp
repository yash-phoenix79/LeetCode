class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    
        int n=heights.size();
        stack<int>l,r;
        vector<int>left(n,-1),right(n,n);
        
        for(int i=0;i<n;i++){
            
            if(l.empty())
                l.push(i);
            else{
                
                while(!l.empty()&&heights[l.top()]>heights[i]){
                    right[l.top()]=i;
                    l.pop();
                }
                    
                
                l.push(i);
                
            }
            
        }
        
        for(int i=n-1;i>=0;i--){
            
            if(r.empty())
                r.push(i);
            else{
                while(!r.empty()&&heights[r.top()]>heights[i]){
                    left[r.top()]=i;
                    r.pop();
                }
                    
                r.push(i);
            }
            
        }
        
        int res=INT_MIN;
        
        for(int i=0;i<n;i++){
            
            int limit=(i-left[i])+(right[i]-i)-1;
            int ans=heights[i]*limit;
            res=max(res,ans);
        }
        
        return res;
        
        
        // 2
        // 1 -left
        // 4 -right
        
        
    }
    
};