class Solution {
public:
    string reverseWords(string s) {
     
        string res="";
        vector<string>temp;
        
        stringstream x(s);
        string t;
        
        int c=0;
        
        while(getline(x,t,' ')){
            // cout<<t<<t.size()<<endl;
               if(t.size()>0){
                 temp.push_back(t);
                 c++;  
               }
        }
            
        
        int n=temp.size();
        // cout<<n;
        int i=n-1;
        while(i>=0){
           
                 res+=temp[i];
            if(c>1)
                res+=' ';
                c--;
            
            i--;
        }
        
        
        
        return res;
    }
};