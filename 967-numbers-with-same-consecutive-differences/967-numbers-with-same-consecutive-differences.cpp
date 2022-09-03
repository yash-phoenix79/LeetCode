class Solution {
public:
    
     vector<int>res;
    
    void findNum(int i,string t,int k,int n){
        if(i==n){
            if(find(res.begin(),res.end(),stoi(t))==res.end())
            res.push_back(stoi(t));
              return;
        }
      
        int dig=t[t.length()-1]-'0';
        if(dig-k>=0){
            char c=dig-k+'0';
            t.push_back(c);
            findNum(i+1,t,k,n);
            t.pop_back();
        }
            
        if(dig+k<=9){
            char c=dig+k+'0';
            t.push_back(c);
            findNum(i+1,t,k,n);
            t.pop_back();
        }
            
        
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
       
        for(int i=1;i<=9;i++)
            findNum(1,to_string(i),k,n);
        return res;
    }
};