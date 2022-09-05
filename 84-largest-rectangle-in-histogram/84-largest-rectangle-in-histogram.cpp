class Solution {
public:
    int largestRectangleArea(vector<int>& hei) {
        
        int n=hei.size();
        stack<int>s;
        
        vector<int>left(n,0),right(n,n-1);
        
        for(int i=0;i<n;i++){
             while(!s.empty()&&hei[i]<=hei[s.top()])
                    s.pop();
            if(s.empty())
                left[i]=0;
            else
                left[i]=s.top()+1;
            
            s.push(i);
        }
        
      
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&hei[i]<=hei[st.top()])
                    st.pop();
               
            if(st.empty())
                right[i]=n-1;
            else
                right[i]=st.top()-1; 
            
            st.push(i);
        }
        
        
        int res=0;
        for(int i=0;i<n;i++)
            res=max(res,hei[i]*(right[i]-left[i]+1));
        return res;
    }
};