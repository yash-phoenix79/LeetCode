class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>>m;
        for(auto x:paths){
            stringstream ss(x);
            string root;
            string s;
            getline(ss,root,' ');
            while(getline(ss,s,' ')){
                string filePath=root+"/"+s.substr(0,s.find('('));
                string fileName=s.substr(s.find('(')+1,s.find(')')-s.find('(')-1);
                m[fileName].push_back(filePath);
            }
        }
        
        for(auto x:m){
            if(x.second.size()>1)
                res.push_back(x.second);
        }
        return res;
    }
};