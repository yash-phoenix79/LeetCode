class Solution {
public:
    
    vector<vector<string>>res;
    unordered_map<string,int>m;
    string b;
    vector<string>path;
    
    void dfs(string e)
    {
     path.push_back(e);
        if(e==b){
            vector<string>re=path;
            reverse(begin(re),end(re));
            res.push_back(re);
            path.pop_back();
            return;
        }
        int cur=m[e];
        
        for(int i=0;i<e.size();i++){
            char c=e[i];
            for(char ch='a';ch<='z';ch++){
                  e[i]=ch;
                if(m.count(e)&&m[e]==cur-1)
                    dfs(e);
            }
             e[i]=c; 
        }
        path.pop_back();
        return;
    }
    
    vector<vector<string>> findLadders(string beg, string endW, vector<string>& word) {
        unordered_set<string>s(begin(word),end(word));
        queue<string>q;
        b=beg;
        m[beg]=0;
        int k=beg.size();
        q.push(beg);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto t=q.front();
                q.pop();
                int x=m[t]+1;
                for(int i=0;i<k;i++){
                    string temp=t;
                    for(char ch='a';ch<='z';ch++){
                        temp[i]=ch;
                        if(!m.count(temp)&&s.count(temp))
                        {
                            m[temp]=x;
                            q.push(temp);
                        }
                    }
                }
            }
        }
        
        if(s.count(endW))
            dfs(endW);
        return res;
    }
};