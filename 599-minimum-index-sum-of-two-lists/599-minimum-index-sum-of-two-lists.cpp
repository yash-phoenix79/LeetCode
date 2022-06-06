class Solution {
public:
    vector<string> findRestaurant(vector<string>& l1, vector<string>& l2) {
         vector<string> res;
        unordered_map<string,int>m1,m2;
        for(int i=0;i<size(l1);i++)
            m1[l1[i]]=i;
        for(int i=0;i<size(l2);i++)
        {
            if(m1.count(l2[i])>0)
                m2[l2[i]]=(m1[l2[i]])+i;
        }
        
        int mini=size(l1)+size(l2)+1;
        
        for(auto m:m2){
            if(m.second<mini)
                mini=m.second;
        }
        
        for(auto m:m2){
            if(m.second==mini)
                res.push_back(m.first);
        }
        return res;
    }
};