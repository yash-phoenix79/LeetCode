class Solution {
public:
    int minPartitions(string n) {
        
        char t='0';
        for(int i=0;i<n.length();i++)
        {
            if((int)n[i]>(int)t)
                t=n[i];
        }
        return t-48;
    }
};