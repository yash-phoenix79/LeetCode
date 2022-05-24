class Solution {
public:
    string getPermutation(int n, int k) {
       vector<int>t;
        int fact=1;
        for(int i=1;i<n;i++){
            fact*=i;
           t.push_back(i);
        }
        t.push_back(n);
        
        string ans="";
        k--;
        int temp=n-1;
        while(true){
            ans+=to_string(t[k/fact]);
            t.erase(t.begin()+(k/fact));
            if(t.empty())
                break;
            k%=fact;
            fact/=temp;
            temp--;
        }
        return ans;
    }
};