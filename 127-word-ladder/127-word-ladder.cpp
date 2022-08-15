class Solution {
public:
    int ladderLength(string beg, string endl, vector<string>& word) {
        
        unordered_set<string>s(begin(word),end(word));
        
        if(s.find(endl)==s.end())
            return 0;
        
        queue<string>q;
        q.push(beg);
        int level=0;
        
        while(!q.empty()){
            int n=q.size();
            level++;
            while(n--){
                auto cur=q.front();
                q.pop();
                string t=cur;
                for(int i=0;i<cur.length();i++){
                    t=cur;
                    for(int j=0;j<26;j++)
                    {
                        t[i]='a'+j;
                        if(s.find(t)!=s.end()){
                            if(t==endl)
                             return level+1;
                            else
                            {
                                q.push(t);
                                s.erase(t);
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};