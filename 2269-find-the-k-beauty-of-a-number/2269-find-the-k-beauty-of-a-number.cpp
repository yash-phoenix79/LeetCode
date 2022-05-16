class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int cnt=0;
        
        string s= to_string(num);
        int n=s.length(),temp;
        for(int i=0;i<n-k+1;i++){
            string t=s.substr(i,k);
            temp=stoi(t);
            if(temp==0)
                continue;
            if(num%temp==0)
                cnt++;
        }
        return cnt;
    }
};