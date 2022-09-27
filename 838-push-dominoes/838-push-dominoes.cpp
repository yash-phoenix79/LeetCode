class Solution {
public:
    string pushDominoes(string dom) {
        int n=dom.length();
        string res(n,'.');
        
        vector<int>q;
        
        for(int i=0;i<n;i++){
            if(dom[i]!='.'){
                res[i]=dom[i];
                q.push_back(i);
            }
        }
        
        while(!q.empty()){
            int m=q.size();
            string temp=res;
            vector<int>q1;
            while(m--){
                int cur=q.back();
                // cout<<cur<<endl;
                q.pop_back();
                if(res[cur]=='R'){
                    if(cur+1==n||(cur+1<n&&res[cur+1]!='.'))
                        continue;
                    if(cur+2<n&&res[cur+2]=='L')
                        continue;
                    else{
                   temp[cur+1]='R';
                    q1.push_back(cur+1); 
                    }

                }
                else {
                    if(cur-1<0||(cur-1>=0&&res[cur-1]!='.'))
                        continue;
                    if(cur-2>=0&&res[cur-2]=='R')
                        continue;
                    else{
                      temp[cur-1]='L';
                    q1.push_back(cur-1);  
                    }
                    
                }
            }
            res=temp;
            q=q1;
        }
        
        return res;
        
    }
};