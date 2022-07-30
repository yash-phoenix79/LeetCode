class Solution {
public:
    
    bool check(string s, unordered_map<char,int>m){
        int n=s.length();
        
        for(int i=0;i<n;i++){
          
           if(m[s[i]]==1)
                m.erase(s[i]);
            else if(m[s[i]]>1)
                m[s[i]]--;
        }
        
//           for(auto pair:m){
//             cout<<pair.first<<" "<<pair.second<<endl;
//         }
        
//         cout<<endl;
//          cout<<endl;
        
       bool res=true;
        for(auto x:m){
            if(x.second>0){
                res=false;
                break;
            }
        }
        return res;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
       vector<string> res;
        int m=words1.size(),n=words2.size();
        
        unordered_map<char,int>mp;
        for(int i=0;i<words2[0].length();i++)
            mp[words2[0][i]]++;
        
        for(int i=1;i<n;i++){
            vector<int>al(26,0);
            for(int j=0;j<words2[i].length();j++)
                al[words2[i][j]-'a']++;
            for(int i=0;i<26;i++){
                
                if(mp['a'+i]<al[i])
                   mp['a'+i]=al[i];
            }
        }
        
//         for(auto pair:mp){
//             cout<<pair.first<<" "<<pair.second<<endl;
//         }
        
        for(int i=0;i<m;i++){
            if(check(words1[i],mp))
                res.push_back(words1[i]);
        }
        
        return res;
        
    }
};