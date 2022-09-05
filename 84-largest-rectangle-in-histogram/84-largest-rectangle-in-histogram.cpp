class Solution {
public:
    int largestRectangleArea(vector<int>& hei) {
        
        int n=hei.size();
        stack<int>s;
        
        vector<int>left(n,0),right(n,n-1);
        
        for(int i=0;i<n;i++){
            if(s.empty())
                left[i]=0;
            else{
                while(!s.empty()&&hei[i]<=hei[s.top()])
                    s.pop();
                left[i]=s.empty()?0:s.top()+1;
            }
            s.push(i);
        }
        
        // for(int i=0;i<n;i++)
        //     cout<<left[i]<<" ";
        // cout<<endl;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty())
                right[i]=n-1;
            else{
                while(!st.empty()&&hei[i]<=hei[st.top()])
                    st.pop();
                right[i]=st.empty()?n-1:st.top()-1;
            }
            st.push(i);
        }
        
        // for(int i=0;i<n;i++)
        //     cout<<right[i]<<" ";
        
        int res=0;
        for(int i=0;i<n;i++)
            res=max(res,hei[i]*(right[i]-left[i]+1));
        return res;
    }
};