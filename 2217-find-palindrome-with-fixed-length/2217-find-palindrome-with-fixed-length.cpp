class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& q, int len) {
        
        vector<long long>res;
        
        long long ba;
        if(len%2)
            ba=pow(10,len/2);
        else
            ba=pow(10,len/2-1);
        
        for(int i=0;i<q.size();i++){
            string a=to_string(ba+q[i]-1);
            string b=a;
            reverse(b.begin(),b.end());
            if(len%2)
                a+=b.substr(1);
            else
                a+=b;
            
            if(a.length()!=len)
                res.push_back(-1);
            else{
                long long t=stol(a);
            res.push_back(t);
            }
            
            
        }
        
        return res;
        
    }
};