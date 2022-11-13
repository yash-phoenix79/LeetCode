class Solution {
public:
    string reverseWords(string s) {
     
        stringstream x(s);
        
        string res="";
        
        vector<string>temp;
        string t;
        
        int c=0;
        
        while(getline(x,t,' ')){
            // cout<<t<<t.size()<<endl;
            temp.push_back(t);
            if(t.size()>0)
                c++;
        }
            
        
        int n=temp.size();
        // cout<<n;
        int i=n-1;
        while(i>=0){
            if(temp[i].size()){
                 res+=temp[i];
            if(c>1)
                res+=' ';
                c--;
            }
            i--;
        }
        
        
        
        return res;
    }
};