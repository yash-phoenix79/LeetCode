class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows<=1)
            return s;
        
        string res;
        vector<string>temp(numRows);
        
        int step=0,row=0;
        for(int i=0;i<s.size();i++)
        {
            row+=step;
            temp[row].push_back(s[i]);
            if(row==0)step=1;
            if(row==numRows-1)step=-1;
            
        }
        
        for(auto x:temp)
            res.append(x);
        return res;
        
    }
};