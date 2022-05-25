class Solution {
public:
    vector<vector<string>>ans;
    
    void findPartition(int idx,int n,string s,vector<string>temp){
        
        if(idx>=n){
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx+1;i<=n;i++){
            string palin=s.substr(idx,i-idx);
            string check=palin;
            reverse(palin.begin(),palin.end());
            if(check==palin){
                temp.push_back(palin);
                findPartition(i,n,s,temp);
                temp.pop_back();
            }
        }
        
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<string>temp;
     
        int n=s.length();
        findPartition(0,n,s,temp);
        return ans;
    }
};