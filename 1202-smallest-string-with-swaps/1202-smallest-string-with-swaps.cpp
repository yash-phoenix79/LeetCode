class Solution {
public:
    
    vector<int>par;
    
    int getPar(int i){
        if(par[i]!=i)
            par[i]=getPar(par[i]);
        return par[i];
    }
    
    void connect(int a,int b){
        
        par[getPar(a)]=par[getPar(b)];
        
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        string res="";
        int n=s.length();
        
        par=vector<int>(n);
        
        for(int i=0;i<n;i++)
            par[i]=i;
        
        for(int i=0;i<pairs.size();i++){
            connect(pairs[i][0],pairs[i][1]);
        }
        
        unordered_map<int,vector<int>>m;
        
        for(int i=0;i<n;i++){
            par[i]=getPar(i);
            m[par[i]].push_back(i);
            
        }
        
        
        for(auto x:m){
            string t="";
           vector<int>temp=x.second;
            for(int i=0;i<temp.size();i++)
                t+=s[temp[i]];
            sort(t.begin(),t.end());
            for(int i=0;i<temp.size();i++)
                s[temp[i]]=t[i];
        }
        
        return s;
        
    }
};