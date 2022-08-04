class Solution {
public:
    string sortSentence(string s) {
        
        vector<string>temp;
        int n=s.length();
        
        int i=0;
        string t;
        
        while(i<n){
            t="";
            while(i<n&&s[i]!=' ')
                t+=s[i++];
            // cout<<t<<endl;
            temp.push_back(t);
            i++;
        }
        
        
        sort(temp.begin(),temp.end(),[](auto &s1,auto &s2){
            int n1=s1.length();
            int n2=s2.length();
            return s1[n1-1]<s2[n2-1];
        });
        
        for(int j=0;j<temp.size();j++)
            cout<<temp[j]<<endl;
        
        string res="";
        int l=temp[0].length();
        res+=temp[0].substr(0,l-1);
        
        i=1;
        while(i<temp.size()){
            res+=" ";
            l=temp[i].length();
            res+=temp[i].substr(0,l-1);
            i++;
        }
        return res;
    }
};