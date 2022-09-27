class Solution {
public:
    string pushDominoes(string dom) {
        int n=dom.length();
        string res(n,'.');
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(dom[i]!='.'){
                res[i]=dom[i];
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int m=q.size();
            string temp=res;
            while(m--){
                int cur=q.front();
                q.pop();
                if(res[cur]=='R'){
                    if(cur+1==n||(cur+1<n&&res[cur+1]!='.'))
                        continue;
                    if(cur+2<n&&res[cur+2]=='L')
                        continue;
                    else{
                   temp[cur+1]='R';
                    q.push(cur+1); 
                    }

                }
                else {
                    if(cur-1<0||(cur-1>=0&&res[cur-1]!='.'))
                        continue;
                    if(cur-2>=0&&res[cur-2]=='R')
                        continue;
                    else{
                      temp[cur-1]='L';
                    q.push(cur-1);  
                    }
                    
                }
            }
            res=temp;
        }
        
        return res;
        
    }
};