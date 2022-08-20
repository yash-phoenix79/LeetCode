class Solution {
public:
     vector<vector<string>>res;
    unordered_map<string,int>m;
    string b;
    vector<string>path;
    
    void dfs(string s){
        path.push_back(s);
        if(s==b){
            vector<string>p=path;
            reverse(begin(p),end(p));
            res.push_back(p);
            path.pop_back();
            return;
        }
        int x=m[s];
        for(int i=0;i<s.size();i++){
            string temp=s;
            for(char ch='a';ch<='z';ch++){
                temp[i]=ch;
                if(m.count(temp)&&m[temp]==x-1)
                    dfs(temp);
            }
        }
        path.pop_back();
        return;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(begin(wordList),end(wordList));
        queue<string>q;
        q.push(beginWord);
        m[beginWord]=0;
        
        int k=beginWord.size();
        b=beginWord;
        
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto cur=q.front();
                q.pop();
                int x=m[cur]+1;
                for(int i=0;i<k;i++){
                    string temp=cur;
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
        
        if(s.count(endWord))
            dfs(endWord);
        return res;
    }
};